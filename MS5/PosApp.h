/*
Final Project Milestone 5
Module: POS
Filename: PosApp.h
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

#include<iostream>
#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H

#include "Item.h"

namespace sdds {
    class PosApp {
        char m_fileName[255]         {};
        int m_nptr                   {};
        Item* m_Iptr[MAX_NO_ITEMS]   {};

        void validateInput(int& input);

        public:
            PosApp(const char *fileName = nullptr);
            // PosApp(const PosApp& rep)   = delete; 
            void sortItems();
		    // PosApp& operator=(const PosApp& rep) = delete; 

            std::ostream& addItem(std::ostream&    ostr = std::cout);
            std::ostream& removeItem(std::ostream& ostr = std::cout);
            std::ostream& stockItem(std::ostream&  ostr = std::cout);
            std::ostream& listItems(std::ostream&  ostr = std::cout);
            std::ostream& pos(std::ostream&        ostr = std::cout) const;
            std::ostream& saveRecs(std::ostream&   ostr = std::cout);
            std::ostream& loadRecs(std::ostream&   ostr = std::cout);

            PosApp& menu();
            PosApp& run();
    };
}

#endif