#include <iostream>
#include "NonPerishable.h"

using namespace std;

namespace sdds {

    char NonPerishable::itemType() const {
        return 'N';
    }

    ostream& NonPerishable::write(ostream& ostr) const {
        Item::write(ostr);
        if(*this) {
            ostr << "     N / A   |"
                 << ((this->m_displayType == POS_FORM) 
                    ? "\n=============^\n" 
                    : "");
        }
        return ostr;
    }


}