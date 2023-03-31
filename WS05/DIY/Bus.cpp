#include <iostream>
#include <iomanip>
#include "Bus.h"
using namespace std;

namespace sdds {

    Bus::Bus(int noOfSeats, int noOfPassengers) {
        if (noOfSeats % 2 == 0 && noOfSeats >= 10 && noOfSeats <= 40 
           && noOfPassengers <= noOfSeats && noOfPassengers >= 0) {
            this->m_noOfSeats = noOfSeats;
            this->m_noOfPassengers = noOfPassengers;
        }
        else
            setOutOfService();
    }

    Bus& Bus::setOutOfService() {
        this->m_noOfPassengers = - 1;
        this->m_noOfSeats = -1;
        return *this;
    }

    ostream& Bus::drawBus(int seats, int noOfPassengers, ostream& ostr) const {
        int i, p;
        ostr.fill('_');
        ostr.width((seats / 2) * 3 + 4);
        ostr << "_";
        ostr << endl << "| ";
        for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
        ostr << "|_\\_" << endl;
        ostr << "| ";
        ostr.fill(' ');
        ostr.width(((seats / 2) * 3 - 14) / 2);
        ostr << " " << "Seneca College";
        ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
        ostr << " " << "    )" << endl;
        ostr << "`---OO";
        ostr.fill('-');
        ostr.width((seats / 2) * 3 - 5);
        ostr << "-" << "O---'" << endl;
        return ostr;
    }

    Bus::operator bool() const{
        return this->m_noOfPassengers >= 0;
    }

    Bus::operator double()const {
        return *this ? this->m_noOfPassengers * ticketPrice : -1.0;
    }

    Bus::operator int() const {
        return *this ? this->m_noOfPassengers : -1;
    }

    ostream& Bus::display(ostream& ostr) const{
        if(*this) 
            drawBus(this->m_noOfSeats, this->m_noOfPassengers, ostr) 
                << "Total Fare Price: " << fixed 
                << showpoint << setprecision(2) << double(*this);
        else
            ostr << "Out of service!";
        
        return ostr << endl;
    }

    istream& Bus::read(istream& istr) {
        int seats, passengers;
        char delim;
        istr >> seats >> delim >> passengers;
        *this = Bus(seats, passengers);
        return istr;
    }

    bool Bus::operator--() {
        bool retVal = true;
        if (int(*this) <= 0)
            retVal = false;
        else
            this->m_noOfPassengers--;
        
        return retVal;
    }

    bool Bus::operator++() {
        bool retVal = true;
        if (int(*this) < 0 || int(*this) >= this->m_noOfSeats)
            retVal = false;
        else
            this->m_noOfPassengers++;
        return retVal;
    }

    bool Bus::operator--(int) {
        return --*this;
    }

    bool Bus::operator++(int) {
        return ++*this;
    }

    Bus& Bus::operator=(int value) {
        *this = Bus(this->m_noOfSeats, value);
        return *this;
    }

    Bus& Bus::operator+=(int value) {
        *this = Bus(this->m_noOfSeats, value+this->m_noOfPassengers);
        return *this;
    }

    Bus& Bus::operator+=(Bus& right) {
        if(*this) {
            if (this->m_noOfSeats - this->m_noOfPassengers >= right.m_noOfPassengers) {
                this->m_noOfPassengers += right.m_noOfPassengers;
                right.m_noOfPassengers = 0;
            }
            else {
                right.m_noOfPassengers -= this->m_noOfSeats - this->m_noOfPassengers;
                this->m_noOfPassengers = this->m_noOfSeats;
            }
        }
        return *this;
    }

    bool Bus::operator==(Bus& right)const {
        return *this && right && int(*this) == int(right);
    }

    int operator+(int left, Bus& right) {
        return (right) ? left + int(right) : left;
    }

    std::ostream& operator<<(std::ostream& ostr, const Bus& right) {
        right.display(ostr);
        return ostr;
    }

    istream& operator>>(istream& istr, Bus& right) {
        right.read();
        return istr;
    }
}