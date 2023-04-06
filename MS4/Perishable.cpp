#include <iostream>
#include "Perishable.h"
#include "Date.h"
using namespace std;

namespace sdds {

    char Perishable::itemType() const {
        return 'P';
    }

    istream& Perishable::read(istream& istr)  {
        Item::read(istr);
        if(*this && !istr.fail()) {
            Date expDate {};
            expDate.dateOnly(true);
            cout << "Expiry date(YYYY/MM/DD)" << endl << "> ";
            istr >> expDate;
            expDate.validateDate() 
                ? this->m_expiry = expDate 
                : this->m_expiry, 
                  this->err = expDate.error();
        }
        return istr;
    }

    ostream& Perishable::write(ostream& ostr) const {
        Item::write(ostr);
        if (*this) {
            ((this->m_displayType == POS_LIST) 
                ? ostr <<  " " << this->m_expiry << " " 
                : ostr << "Expiry date: " << this->m_expiry
                       << endl << "=============^" << endl);
        }
    }


}