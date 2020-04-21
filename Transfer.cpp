//
// Created by dsanchez on 3/30/20.
//

#include "Transfer.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

Transfer::Transfer() {
    data.resize(7);
    ofstream ofs;
    ofs.open(WRITE_FILE, ofstream::out | ofstream::trunc);

    if (!ofs.is_open()) {
        cout << "Could not open file: " << WRITE_FILE << endl;
    }

    ofs << "DROP TABLE IF EXISTS office_data;" << endl << endl;
    ofs << "CREATE TABLE office_data (" << endl;
    ofs << "\tID \t\t\t\tinteger," << endl;
    ofs << "\tseason \t\t\tinteger," << endl;
    ofs << "\tepisode \t\tinteger," << endl;
    ofs << "\tscene \t\t\tinteger," << endl;
    ofs << "\tline_text \t\ttext," << endl;
    ofs << "\tspeaker \t\ttext" << endl;
    ofs << ");" << endl << endl;
    ofs.close();
}

void Transfer::readData() {
    ifstream rData;
    string temp = "";
    rData.open(READ_FILE);
    if (!rData.is_open()) {
        cout << "Could not open file: " << READ_FILE << endl;
    }

    getline(rData, temp);

    while(!rData.eof()) {
        bool first = true;
        data.resize(0);
        getline(rData, temp);
        string output = "";
        for (int i = 0; i < temp.length(); ++i) {
            bool skip = false;
            if (temp.at(i) == '\"' && first) {
                first = false;
                //output += '\'';
                skip = true;
            }
            if (!skip && temp.at(i) == '\"' && !first) {
                first = true;
                //output += '\'';
                skip = true;
            }
            if (temp.at(i) == '\'') {
                output += '\'';
            }
            if (!skip) {
                if (temp.at(i) == ',' && first) {
                    data.push_back(output);
                    output = "";
                } else {
                    output += temp.at(i);
                }
            }
        }
        data.push_back(output);
        data.resize(6);
        writeData();
    }
    rData.close();
}
void Transfer::writeData() {
    if (data.at(0) == "") {
        return;
    }

    ofstream wData;
    wData.open(WRITE_FILE, ios_base::app);
    //wData.open(WRITE_FILE);
    string output = "INSERT INTO office_data";
    wData << output << endl;
    output = "VALUES (";
    for (int i = 0; i < 4; ++i) {
        output += data.at(i) + ", ";
    }

    /*
    if (data.at(4).at(0) != '\'') {
        output += '\'' + data.at(4) + '\'';
    } else {
        output += data.at(4);
    }
    */
    output += '\'' + data.at(4) + '\'';

    output += ", ";

    checkName();

    output += '\'' + data.at(5) + "\');";
    wData << output << endl << endl;

    wData.close();

}

void Transfer::checkName() {
    vector<string> badName = makeBadName();
    vector<string> goodName = makeGoodName();

    for (int i = 0; i < makeBadName().size(); ++i) {
        if (data.at(5) == badName.at(i)) {
            data.at(5) = goodName.at(i);
        }
    }
}

vector<string> Transfer::makeBadName() {
    vector<string> badName(0);
    badName.emplace_back("David Wallace");
    badName.emplace_back("Daryl");
    badName.emplace_back("Robert California");
    badName.emplace_back("Ryan Howard");
    badName.emplace_back("Todd Packer");
    badName.emplace_back("Packer");
    badName.emplace_back("Everybody");
    badName.emplace_back("Everyone");
    badName.emplace_back("Group");
    badName.emplace_back("Bob Vance");

    return badName;
}

vector<string> Transfer::makeGoodName() {
    vector<string> goodName(0);
    goodName.emplace_back("David");
    goodName.emplace_back("Darryl");
    goodName.emplace_back("Robert");
    goodName.emplace_back("Ryan");
    goodName.emplace_back("Todd");
    goodName.emplace_back("Todd");
    goodName.emplace_back("All");
    goodName.emplace_back("All");
    goodName.emplace_back("All");
    goodName.emplace_back("Bob");

    return goodName;
}


