/*
Final Project Milestone 5
Module: POS
Filename: NonPerishable.h
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

#ifndef SDDS_NONPERISHABLE_H
#define SDDS_NONPERISHABLE_H

#include "Item.h"

namespace sdds {

    class NonPerishable : public Item {
        public:
            char itemType() const override;
            std::ostream&  write(std::ostream& ostr)  const override;
    };

}

#endif