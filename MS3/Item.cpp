#include <iomanip>
#include "Item.h"

using namespace std;

namespace sdds {

    Item::Item() {} // default values already set initially

    Item::~Item() {
        this->clear();
        delete[] this->m_itemName;
        this->m_itemName = nullptr;
    }

    Item::Item(const Item& other) {
        this != &other ? *this = other : *this ;
    }

    Item& Item::operator=(const Item& other) {
        if(this != &other) {

            memcpy(this->m_SKU, other.m_SKU, MAX_SKU_LEN+1);

            if(this->m_itemName != nullptr) {
                delete[] this->m_itemName;
                this->m_itemName = nullptr;
            }

            this->m_itemName = new char[strlen(other.m_itemName) + 1];
            memcpy(this->m_itemName, other.m_itemName, strlen(other.m_itemName) + 1 );
            
            this->m_price       = other.m_price;
            this->m_isTaxed     = other.m_isTaxed;
            this->m_quantity    = other.m_quantity;
            this->m_displayType = other.m_displayType;
            this->err           = other.err;
        }
        return *this;
    }

    bool Item::operator==(const char* name) const {
        return strcmp(this->m_SKU, name) == 0;
    }

    bool Item::operator>(const Item& other) const {
        return strcmp(this->m_SKU, other.m_SKU) > 0;
    }

    int Item::operator+=(const int value) {
        bool error = false;
        
        (this->m_quantity+value) > MAX_STOCK_NUMBER 
            ? this->m_quantity = MAX_STOCK_NUMBER, error = true 
            : this->m_quantity = this->m_quantity + value;

        error ? this->err = ERROR_POS_QTY : err;

        return this->m_quantity;
    }

    int Item::operator-=(const int value) {
        bool error = false;
        
        (this->m_quantity-value) < 0 
            ? this->m_quantity = 0, error = true 
            : this->m_quantity = this->m_quantity - value;

        error ? this->err = ERROR_POS_STOCK : err;

        return this->m_quantity;
    }

    Item::operator bool() const {
        return !err;
    }

    double operator+=(double& value, const Item& ROp) {
        return value += ROp.cost() * ROp.quantity();
    }
    
    Item& Item::displayType(int posValue) {

        (posValue == POS_LIST || posValue == POS_FORM )
            ? this->m_displayType = posValue 
            : this->m_displayType;

        return *this;
    }
    
    double Item::cost() const {

        double totalCost {};

        totalCost = this->m_isTaxed 
            ? this->m_price * (1+TAX) 
            : this->m_price;

        return totalCost;
    }

    int Item::quantity() const {
        return this->m_quantity;
    }

    Item& Item::clear() {
        this->err.clear();
        return *this;
    }

    ostream& Item::write(ostream& ostr)  const {
        if (this->err)    ostr << this->err;
        else 
            switch(this->m_displayType) {
                case POS_LIST:
                    ostr << setw(7) << left << this->m_SKU << "|";
                    strlen(this->m_itemName) > 20 
                        ? ostr.write(this->m_itemName, 20) 
                        : ostr << setw(20) << this->m_itemName;
                    ostr << "|" << setw(7) << right << fixed 
                         << setprecision(2) << this->m_price << "|"
                         << setw(3) << (this->m_isTaxed ? " X |" : "   |")
                         << setw(4) << right << this->m_quantity << "|"
                         << setw(10) << fixed << setprecision(2) 
                         << cost() * this->m_quantity << "|";
                    break;
                case POS_FORM:
                    ostr << "=============v" << endl
                         << setw(13) << left << "Name:" << this->m_itemName << endl
                         << setw(13) << left << "Sku:" << this->m_SKU << endl
                         << setw(13) << left << "Price:" << this->m_price << endl
                         << setw(13) << left << "Price + tax:";
                    this->m_isTaxed ? ostr << cost() : ostr << "N/A";
                    ostr << endl << "Quantity: " << this->m_quantity << endl
                         << "====================" << endl;
                    break;
        }
        return ostr;
    }

    istream& Item::read(istream& istr)  {
        bool flag = true;
        char skuBuffer[MAX_SKU_LEN + 1]{};
        char nameBuffer[MAX_NAME_LEN + 1]{};
        double tempPrice;
        bool tempTaxed;
        int tempQuantity;

        cout << "Sku" << endl;
        while(flag) {
            cout << "> ";
            istr.getline(skuBuffer, MAX_SKU_LEN + 1, '\n');
            if (skuBuffer[MAX_SKU_LEN] != '\0')
                cout << ERROR_POS_SKU << endl; 
            else {
                flag = false; 
                memcpy(this->m_SKU, skuBuffer,  MAX_SKU_LEN + 1);
            }
            
        }

        return istr;
    }

    ofstream& Item::save(ofstream& ostr) const {
        return ostr;
    }

    ifstream& Item::load(ifstream& istr) {
        return istr;
    } 

    ostream& Item::bprint(ostream &ostr)  const {
        return ostr;
    }
}