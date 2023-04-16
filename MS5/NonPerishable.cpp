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
            ostr  << ((this->m_displayType == POS_FORM)

                    ? "=============^\n" 
                    : "     N / A   |");
        }
        ostr.unsetf(ios::right);
        return ostr;
    }


}