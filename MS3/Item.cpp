#include <iomanip>
#include "Item.h"
// #include "PosIO.h"

using namespace std;

namespace sdds {

    Item::Item() {} // default values already set initially

    Item::~Item() {
        this->clear();
        if(this->m_itemName != nullptr)
            delete[] this->m_itemName;
        this->m_itemName = nullptr;
    }

    Item::Item(const Item& other) {
        *this = other;
    }

    Item& Item::operator=(const Item& other) {
        if(this != &other) {

            strcpy(this->m_SKU, other.m_SKU);

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
    
    Item &Item::displayType(int type)
    {
        if (type == POS_LIST || type == POS_FORM)
        {
            this->m_displayType = type;
        }
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
        char skuBuffer[MAX_SKU_LEN * 2]{};
        char nameBuffer[MAX_NAME_LEN * 2]{};
        char taxedBuffer[10] {};
        double tempPrice = 0.0;
        int tempQuantity = 0;
        cout << "Sku" << endl;
        while(flag) {
            cout << "> ";
            istr >> skuBuffer;
            if (strlen(skuBuffer) > MAX_SKU_LEN)    cout << ERROR_POS_SKU << endl; 
            else    flag = false && strncpy(this->m_SKU, skuBuffer, MAX_SKU_LEN);
            istr.clear();
            istr.ignore(99, '\n');
        }
        cout << "Name" << endl;
        flag = true;
        while(flag) {
            cout << "> ";
            istr.get(nameBuffer, MAX_NAME_LEN * 2, '\n');
            if (strlen(nameBuffer) > MAX_NAME_LEN)   cout << ERROR_POS_NAME << endl;
            else {
                flag = false;
                if(this->m_itemName != nullptr)     delete[] this->m_itemName;
                this->m_itemName = new char [strlen(nameBuffer) + 1];
                strncpy(this->m_itemName, nameBuffer, MAX_NAME_LEN);
            }
            istr.clear();
            istr.ignore(99, '\n');
        }
        cout << "Price" << endl;
        flag = true;
        while(flag) {
            cout << "> ";
            istr.clear();
            istr.ignore();
            (istr >> tempPrice && tempPrice >= 0) 
                ? this->m_price = tempPrice, flag = false
                : flag = true;
            flag && cout << ERROR_POS_PRICE << endl;
        }
        cout << "Taxed" << endl;
        cout << "(Y)es/(N)o: ";
        flag = true;
        while(flag) {
            istr >> taxedBuffer;
            !strcmp(taxedBuffer, "y") || !strcmp(taxedBuffer, "n") ? flag = false : flag = true;
            if(!flag && !strcmp(taxedBuffer, "y"))  this->m_isTaxed = true;
            if(flag)
                cout << "Only 'y' and 'n' are acceptable: "; 
            istr.clear();
            istr.ignore(99, '\n');
        }
        cout << "Quantity" << endl;
        flag = true;
        while(flag) {
            cout << "> ";
            (istr >> tempQuantity && tempQuantity > 0 && tempQuantity < MAX_STOCK_NUMBER)
                ?  this->m_quantity = tempQuantity, flag = false
                :  flag = true;
            flag && cout << ERROR_POS_QTY << endl;
            cout << "111111";
            istr.clear();
            istr.ignore(99, '\n');
            cout << "111111";
        }
        return istr;
    }

    ofstream& Item::save(ofstream& ostr) const {
        if (err)    cerr << err << endl;
        else {
            ostr << itemType() << "," << this->m_SKU << "," << this->m_itemName
                 << "," << this->m_price << "," << int(this->m_isTaxed) << ","
                 << this->m_quantity << endl;
        }
        return ostr;
    }


    ifstream& Item::load(ifstream& istr) {
        char tempSKU[MAX_SKU_LEN * 2];
        char tempName[MAX_NAME_LEN * 2];
        double tempPrice;
        int tempTaxed;
        int tempQuantity;
        bool flag = true;
        this->clear();

        istr.getline(tempSKU, MAX_NAME_LEN*2, ',');
        istr.getline(tempName, MAX_NAME_LEN*2, ',');
        istr >> tempPrice;
        istr.ignore();
        istr >> tempTaxed;
        istr.ignore();
        istr >> tempQuantity;

        if(!istr.fail()) {
            strlen(tempSKU) > MAX_SKU_LEN ? flag = false, err = ERROR_POS_SKU : flag;
            !err && strlen(tempName) > MAX_NAME_LEN ? flag = false, err = ERROR_POS_NAME : flag;
            !err && tempPrice < 0 ? flag = false, err = ERROR_POS_PRICE : flag;
            !err && tempTaxed != 0 && tempTaxed != 1 ?  flag = false, err = ERROR_POS_TAX: flag ;
            !err && tempQuantity < 0 || tempQuantity > MAX_STOCK_NUMBER ? flag = false, err = ERROR_POS_STOCK : flag;
        }
        else    flag = false;
        cout << "loadex";
        return istr;
    } 

    ostream& Item::bprint(ostream &ostr)  const {
        return ostr;
    }
}