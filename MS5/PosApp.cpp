/*
Final Project Milestone 5
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
#include <iomanip>
#include <cstring>
#include "PosApp.h"
#include "Perishable.h"
#include "NonPerishable.h"

using namespace std;

namespace sdds {

    PosApp::PosApp(const char* fileName) {
        bool(fileName) ? strcpy(this->m_fileName, fileName) : 0;
    }

    void PosApp::sortItems(){

    }

    void PosApp::validateInput(int& userSelection) {
        bool flag = true;
        while (flag) {
            cin >> userSelection;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Invalid Integer, try again: ";
            }
            else if (userSelection > 5 || userSelection < 0)
                cout << "[0<=value<=5], retry: > ";
            else
                flag = false;
        }
    }

    ostream& PosApp::loadRecs(ostream& ostr) {
        int i = 0;
        ostr << ">>>> Loading Items............."
        ".............................................." 
        << endl;
        ifstream ifstr(this->m_fileName);
        if(!ifstr.is_open()) {
            ofstream ofstr(this->m_fileName);
            ofstr.close();
        }
        for(int i = 0; i < m_nptr && m_Iptr[i]->clear(); i++);        
        for(;!ifstr.eof() && i < MAX_NO_ITEMS;i++) {
            char ch, delim;
            ifstr >> ch >> delim;
            Item* iptr;
            (ch == 'P') ? iptr = new Perishable : iptr = new NonPerishable;
            m_Iptr[i] = iptr;
            m_Iptr[i]->load(ifstr);
            m_Iptr[i]->displayType(POS_LIST);
        }
        this->m_nptr = i-1;
        return ostr;
    }

    ostream& PosApp::saveRecs(ostream& ostr) {
        ostr << ">>>> Saving Data........................"
        "....................................."  << endl;
        ofstream ofstr(this->m_fileName);
        for(int i = 0; i < this->m_nptr && ofstr << *this->m_Iptr[i] << endl; i++);
        return ostr;
    }

    ostream& PosApp::listItems(ostream& ostr) {
        double netAssets {};
        for(int i = 0; i < this->m_nptr - 1; i++)
            for(int j = 0; j < this->m_nptr - i - 1; j++)
                if(strcmp(this->m_Iptr[j]->getName(), this->m_Iptr[j+1]->getName()) > 0) {
                    auto *temp =  this->m_Iptr[j];
                    this->m_Iptr[j] = this->m_Iptr[j+1];
                    this->m_Iptr[j+1] = temp;
                }
        ostr << ">>>> Listing Items..........................................................."  << endl
             <<  " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |"  << endl
             <<  "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;
        for(int i = 0; i < m_nptr; i++) {
            netAssets += this->m_Iptr[i]->cost() * this->m_Iptr[i]->quantity();
            ostr << right << setw(4) << (i + 1) << " | " << *this->m_Iptr[i] << endl;
        }
        ostr << "-----^--------^--------------------^-------^---^----^---------^-------------^"  << endl
             << setw(48) << right << "Total Asset: $  |" << setw(14) << fixed << setprecision(2) << netAssets 
             << "|" << endl << "-----------------------------------------------^--------------^";
        
        return ostr;
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
        cout << "5- POS" << endl;
        cout << "0- exit program" << endl;
        cout << "> ";
        return *this;
    }

    PosApp& PosApp::run() {
        int userSelection;
        loadRecs();
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