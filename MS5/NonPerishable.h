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