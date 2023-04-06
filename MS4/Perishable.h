#include <iostream>

#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H

#include "Item.h" 
#include "Date.h"


namespace sdds {

    class Perishable : public Item {
        Date m_expiry {};

        public:
            char itemType() const override;

            std::ostream&  write(std::ostream& ostr)  const override;
            std::istream&  read(std::istream& istr)         override;
            std::ofstream& save(std::ofstream& ostr)  const override;
            std::ifstream& load(std::ifstream& istr)        override; 
    };

}

#endif