#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include "PosIO.h"
#include "POS.h"
#include "Error.h"

namespace sdds {
    class Item : public PosIO {
        char m_SKU[MAX_SKU_LEN + 1] {};
        char* m_itemName            {};
        double m_price              {};
        bool m_isTaxed              {};
        int m_quantity              {};
    
        protected:
            int m_displayType     =   0;
            Error err               {};

        public:
            Item();
            ~Item();
            Item(const Item& other);
            Item& operator=(const Item& other);
            bool operator==(const char* name) const;
            bool operator>(const Item& other)  const;
            int operator+=(const int value);
            int operator-=(const int value);
            operator bool() const;

            virtual char itemType() = 0;
            double cost()  const;
            int quantity() const;

            Item& clear();
            Item& displayType(int posValue);

            virtual std::ostream& write(std::ostream& ostr)  const override;
            virtual std::istream&  read(std::istream& istr)        override;
            virtual std::ofstream& save(std::ofstream& ostr) const override;
            virtual std::ifstream& load(std::ifstream& istr)       override; 

    };

    double& operator+=(double& value, const Item& ROp);

}

#endif