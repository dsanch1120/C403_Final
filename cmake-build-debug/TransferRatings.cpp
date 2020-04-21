//
// Created by Daniel Sanchez on 4/20/2020.
//

#include "TransferRatings.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

TransferRatings::TransferRatings() {
    data.resize(7);
    ofstream ofs;
    ofs.open(WRITE_FILE, ofstream::out | ofstream::trunc);

    if (!ofs.is_open()) {
        cout << "Could not open file: " << WRITE_FILE << endl;
    }

    ofs << "DROP TABLE IF EXISTS office_ratings;" << endl << endl;
    ofs << "CREATE TABLE office_ratings (" << endl;
    ofs << "\tseason \t\t\tinteger," << endl;
    ofs << "\tepisode \t\tinteger," << endl;
    ofs << "\ttitle \t\t\ttext," << endl;
    ofs << "\trating \t\tfloat" << endl;
    ofs << ");" << endl << endl;
    ofs.close();
}

void TransferRatings::readData() {
    ifstream rData;
    string temp = "";
    rData.open(READ_FILE);
    if (!rData.is_open()) {
        cout << "Could not open file: " << READ_FILE << endl;
    }

    getline(rData, temp);
    bool first = true;
    while(!rData.eof()) {
        data.resize(0);
        getline(rData, temp);
        string output = "";
        if (!first) {
            for (char i : temp) {
                if (i == '\'') {
                    output += '\'';
                }
                if (i == ',') {
                    data.push_back(output);
                    output = "";
                } else {
                    output += i;
                }
            }
            writeData();
        }
        first = false;
    }
    rData.close();
}
void TransferRatings::writeData() {
    if (data.at(0) == "") {
        return;
    }

    ofstream wData;
    wData.open(WRITE_FILE, ios_base::app);
    //wData.open(WRITE_FILE);
    string output = "INSERT INTO office_ratings";
    wData << output << endl;
    output = "VALUES (";
    output += data.at(0) + ", " + data.at(1) + ", ";
    output += '\'' + data.at(2) + '\'';

    output += ", ";

    output += data.at(3) + ");";
    wData << output << endl << endl;

    wData.close();

}

