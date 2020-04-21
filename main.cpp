/*
 * Created by Daniel Sanchez
 */

#include <iostream>
#include "TransferScript.h"
#include "cmake-build-debug/TransferRatings.h"

using namespace std;

int main() {
    int userChoice;
    cout << "Choose which script to produce:" << endl;
    cout << "\t 1 for Script" << endl << "\t 2 for Ratings" << endl << "\t 3 for both" << endl;
    cin >> userChoice;

    if (userChoice == 1) {
        TransferScript *script = new TransferScript();
        script->readData();
    }
    if (userChoice == 2) {
        TransferRatings *ratings = new TransferRatings();
        ratings->readData();
    }
    if (userChoice == 3) {
        TransferScript *script = new TransferScript();
        script->readData();
        TransferRatings *ratings = new TransferRatings();
        ratings->readData();
    }
    return 0;
}
