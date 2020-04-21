//
// Created by Daniel Sanchez on 3/30/20.
//

#ifndef THEOFFICEDATA_TRANSFERSCRIPT_H
#define THEOFFICEDATA_TRANSFERSCRIPT_H


#include <string>
#include <vector>

class TransferScript {
public:
    TransferScript();
    void readData();
private:
    void writeData();
    void checkName();
    std::vector<std::string> makeGoodName();
    std::vector<std::string> makeBadName();
    const std::string READ_FILE = "officeScript.csv";
    const std::string WRITE_FILE = "officeData.sql";
    std::vector<std::string> data;
};


#endif //THEOFFICEDATA_TRANSFERSCRIPT_H
