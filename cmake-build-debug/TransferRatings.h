//
// Created by Daniel Sanchez on 4/20/2020.
//

#ifndef THEOFFICEDATA_TRANSFERRATINGS_H
#define THEOFFICEDATA_TRANSFERRATINGS_H


#include <string>
#include <vector>

class TransferRatings {
public:
    TransferRatings();
    void readData();
private:
    void writeData();
    const std::string READ_FILE = "officeRatings.csv";
    const std::string WRITE_FILE = "officeRatings.sql";
    std::vector<std::string> data;
};


#endif //THEOFFICEDATA_TRANSFERRATINGS_H
