/*
Final Project Milestone 1
Module: POS
Filename: PosApp.cpp
Version 1.0
Author	Mustafa Siddiqui
Student ID: 117434225
Email: msiddiqui48@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2023/03/09  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include "PosApp.h"

using namespace std;

namespace sdds {

    PosApp::PosApp(const char* fileName) {
        bool(fileName) ? strcpy(this->m_fileName, fileName) : 0;
    }

    void PosApp::validateInput(int& userSelection) {
        bool flag = true;
        cin >> userSelection;
        while(flag) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Integer, try again: ";
            }
            else if (userSelection > 6 || userSelection < 0)
                cout << "[0<=value<=5], retry: > ";
            cin >> userSelection;
        }
    }

    ostream& PosApp::loadRecs(ostream& ostr) {
        return ostr << ">>>> Loading Items..........................................................."
            << endl << "Loading data from " << this->m_fileName;
    }

    ostream& PosApp::saveRecs(ostream& ostr) {
        return ostr << ">>>> Saving Data............................................................." 
            << endl << "Saving data in " << this->m_fileName;
    }

    ostream& PosApp::listItems(ostream& ostr) const {
        return ostr << ">>>> Listing Items..........................................................." 
            << endl << "Running listItems()";
    }

    ostream& PosApp::addItem(ostream& ostr) {
        return ostr << ">>>> Adding Item to the store................................................" 
            << endl<< "Running addItem()";
    }

    ostream &PosApp::stockItem(ostream& ostr) {
        return ostr << ">>>> Select an item to stock................................................." 
            << endl << "Running stockItem()";
    }

    ostream &PosApp::removeItem(ostream& ostr) {
        return ostr << ">>>> Remove Item............................................................." 
         << endl << "Running removeItem()";
    }

    ostream& PosApp::pos(ostream& ostr) const {
        return ostr << ">>>> Starting Point of Sale.................................................." 
            << endl <<"Running POS()";
    }   


    PosApp& PosApp::menu() {
        cout << "The Sene-Store" << endl;
        cout << "1- List items" << endl;
        cout << "2- Add item" << endl;
        cout << "3- Remove item" << endl;
        cout << "4- Stock item" << endl;
        cout << "5- Point of Sale" << endl;
        cout << "0- exit program" << endl;
        cout << "> ";
        return *this;
    }

    PosApp& PosApp::run() {
        int userSelection;
        loadRecs() << endl;
        do {
            menu();
            validateInput(userSelection);
            switch(userSelection) {
                
                case 0:
                    saveRecs() << endl << "Goodbye!" << endl;
                    break;

                case 1:
                    listItems() << endl;
                    break;
                
                case 2:
                    addItem() << endl;
                    break;
                
                case 3:
                    removeItem() << endl;
                    break;
                
                case 4:
                    stockItem() << endl;
                    break;

                case 5:
                    pos() << endl;
                    break;
            }

        }while(userSelection);

        return *this;
    }
}