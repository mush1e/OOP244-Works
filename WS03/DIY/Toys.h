#ifndef SDDS_TOYS_H
#define SDDS_TOYS_H

#define MAX_TNAME

namespace sdds {

    class Toys {
        char m_tname;
        int m_sku; 
        double m_price;
        int m_age;
        bool m_onSale;

        public:
            void addToys(const char* tname, int sku, double price,int age);
            void isSale(bool sale);
            void isSale(bool sale);
            void display()const;
    };

}

#endif