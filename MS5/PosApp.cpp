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

    PosApp::~PosApp() {
        for (int i = 0; i < this->m_nptr; i++) {
            delete this->m_Iptr[i];
            this->m_Iptr[i] = nullptr;
        }
    }

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
        char ch, delim;

        ostr << ">>>> Loading Items............."
                ".............................................." 
        << endl;
        ifstream ifstr(this->m_fileName);
        if(!ifstr.is_open()) {
            ofstream ofstr(this->m_fileName);
            ofstr.close();
        }

        for(int j = 0; j < m_nptr && m_Iptr[j]->clear(); j++);        
        for(;ifstr >> ch >> delim && i < MAX_NO_ITEMS;i++) {            
            Item* iptr;
            (ch == 'P') ? iptr = new Perishable : iptr = new NonPerishable;
            m_Iptr[i] = iptr;
            m_Iptr[i]->load(ifstr);
            m_Iptr[i]->displayType(POS_LIST);
        }
        this->m_nptr = i;
        return ostr;
    }

    ostream& PosApp::saveRecs(ostream& ostr) {
        ostr << ">>>> Saving Data........................"
                ".....................................";
        ofstream ofstr(this->m_fileName);
        for(int i = 0; i < this->m_nptr && ofstr << *this->m_Iptr[i] << endl; i++);
        return ostr;
    }

    ostream& PosApp::listItems(ostream& ostr, bool list) {
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

            ostr << "-----^--------^--------------------^-------^---^----^---------^-------------^"  << endl;
            if(list)
                ostr << setw(48) << right << "Total Asset: $  |" << setw(14) << fixed << setprecision(2) << netAssets 
                     << "|" << endl << "-----------------------------------------------^--------------^" << endl;
        
        return ostr;
    }

    ostream& PosApp::addItem(ostream& ostr) {
        ostr << ">>>> Adding Item to the store....................."
                "..........................." << endl; 

        if(this->m_nptr < MAX_NO_ITEMS) {
            Item* usrInp;
            char perish;
            ostr << "Is the Item perishable? (Y)es/(N)o: ";
            cin >> perish;
            perish == 'y' ? usrInp = new Perishable{} : usrInp = new NonPerishable{};
            usrInp->read(cin);
            ostr << ">>>> DONE!.................................................................";
            if(usrInp)  this->m_Iptr[this->m_nptr++] = usrInp;
        }
        else    ostr << "Inventory Full!";
        return  ostr;
    }

    ostream& PosApp::stockItem(ostream& ostr) {
        return ostr << ">>>> Select an item to stock................................................." 
            << endl << "Running stockItem()";
    }

    int PosApp::selectItem(ostream& ostr){
        int inp {};
        ostr << ">>>> Item Selection by row number............................................" << endl
             << "Press <ENTER> to start....";
        cin.ignore(1000, '\n');
        cin.get();
        this->listItems(ostr, false);
        ostr << "Enter the row number: ";
        while(inp < 1 || inp > this->m_nptr) {
            cin >> inp;
            if(cin.fail()) {
                inp = 0;
                cin.clear();
                cin.ignore(1000, '\n');
                ostr << "Invalid Integer, try again: ";
            }
            else if (inp < 1 || inp > this->m_nptr) {
                ostr << "[1<=value<=" << this->m_nptr <<"], retry: Enter the row number: ";
            }
        }
        return inp;
    }

    ostream& PosApp::removeItem(ostream& ostr) {
        ostr << ">>>> Remove Item................................"
                "............................." << endl;
        int row = selectItem(ostr);
        ostr << "Removing...." <<endl;
        this->m_Iptr[row-1]->displayType(POS_FORM);
        ostr << *this->m_Iptr[row-1];
        ostr << *this->m_Iptr[row-1];
        delete this->m_Iptr[row-1];
        for(int i = row-1; i < this->m_nptr - 1; i++) 
            swap(this->m_Iptr[i], this->m_Iptr[i+1]);
        this->m_Iptr[m_nptr-1] = nullptr;
        this->m_nptr--;
        return ostr << ">>>> DONE!.................................................................";
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