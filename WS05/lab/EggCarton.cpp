/*
*****************************************************************************
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 18 Apr 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include<iostream>
#include "EggCarton.h"

using namespace std;

namespace sdds {

    EggCarton::EggCarton(int size, int noOfEggs, bool isJumbo) {
        if (size % 6 == 0 && size >= 6 && size <= 36 && noOfEggs <= size && noOfEggs >= 0) {
            this->m_size      = size;
            this->m_noOfEggs  = noOfEggs;
            this->m_jumboSize = isJumbo;
        }
        else
            setBroken();
    }

    EggCarton& EggCarton::setBroken() {
        this->m_size = -1;
        this->m_noOfEggs = -1;
        return *this;
    }

    ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const {
        int cartonWidth = size == 6 ? 3 : 6;
        for(int i = 0; i < size; i++) {
            ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
            ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
        }
        return ostr;
    }

    ostream& EggCarton::display(ostream& ostr) const {
        if(*this)
            displayCarton(this->m_size, this->m_noOfEggs, this->m_jumboSize, ostr);
        else
            ostr << "Broken Egg Carton!" << endl;
        return ostr;
    }

    EggCarton::operator bool() const{
        return this->m_size != -1;
    }

    istream& EggCarton::read(istream& istr) {
        int size, noOfEggs;
        bool isJumbo;
        char delim, jumbo;
        istr >> jumbo >> delim >> size >> delim >> noOfEggs;
        isJumbo = jumbo == 'j';
        *this = EggCarton(size, noOfEggs, isJumbo);
        return istr;
    }

    EggCarton::operator int() const {
        return *this ? this->m_noOfEggs : -1;
    }

    EggCarton::operator double() const{
        return *this ? (this->m_jumboSize ? JumboEggWieght/1000.0 * this->m_noOfEggs : RegularEggWieght/1000.0 * this->m_noOfEggs) : -1.0;
    }

    EggCarton& EggCarton::operator--() {
        *this && this->m_noOfEggs > 0 && this->m_noOfEggs--;
        return *this;
    }

    EggCarton& EggCarton::operator++() {
        *this && this->m_noOfEggs++ && this->m_noOfEggs > this->m_size && setBroken();
        return *this;
    }

    EggCarton EggCarton::operator--(int) {
        EggCarton old = *this;
        --*this;
        return old;
    }

    EggCarton EggCarton::operator++(int) {
        EggCarton old = *this;
        ++*this;
        return old;
    }

    EggCarton& EggCarton::operator=(int value) {
        this->m_noOfEggs = value;
        this->m_noOfEggs > this->m_size && setBroken();
        return *this;
    }

    EggCarton& EggCarton::operator+=(int value) {
        if(*this) {
            value += this->m_noOfEggs;
            *this = value;
        }
        return *this;
    }

    EggCarton& EggCarton::operator+= (EggCarton& right) {
        if(*this) {
            if (this->m_size - this->m_noOfEggs >= right.m_noOfEggs) {
                this->m_noOfEggs += right.m_noOfEggs;
                right.m_noOfEggs = 0;
            }
            else {
                right.m_noOfEggs -= this->m_size - this->m_noOfEggs;
                this->m_noOfEggs = this->m_size;
            }
        }
        return *this;
    } 

    bool EggCarton::operator==(const EggCarton& right) const {
        return double(*this) - double(right) >= -0.001 && double(*this) - double(right) <= 0.001;
    }

    int operator+(int left, const EggCarton& right) {            
        return (right)?left = int(right) + left : left;
    }

    ostream& operator<<(ostream& ostr, const EggCarton& right) {
        right.display(ostr);
        return ostr;
    }

    istream& operator>>(istream& istr, EggCarton& right) {
        right.read(istr);
        return istr;
    }
}