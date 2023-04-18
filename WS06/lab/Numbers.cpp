/*
*****************************************************************************
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 18 Apr 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>

#include "Numbers.h"
using namespace std;
namespace sdds {

    bool Numbers::setEmpty() {
        this->m_arrSize = 0;
        this->m_collection = nullptr;
        this->m_fileName[0] = '\0';
        this->m_hasAppend = false;
        this->m_isOriginal = false;
        return true;
    }

    Numbers::Numbers(const char* fName) {
        setEmpty();        
        fName && strcpy(this->m_fileName, fName) && load();
    }

    Numbers::Numbers(const Numbers& other) {
        if(this != &other)  
            *this = other;
    }

    Numbers& Numbers::operator=(const Numbers& other) {
        save();
        delete[] m_collection;
        setEmpty();
        if(other.m_collection != nullptr) {
            this->m_isOriginal = false;
            this->m_collection = new double[other.m_arrSize];
            this->m_arrSize = other.m_arrSize;
            memcpy(this->m_collection, other.m_collection, sizeof(double) * m_arrSize);
        }
        return *this;
    }

    Numbers& Numbers::sort() {
        sort(this->m_collection, this->m_arrSize);
        return *this;
    }

    bool Numbers::load() {
        size_t size{}, numLines = countLines(this->m_fileName);
        delete[] this->m_collection;
        if(numLines) {
            this->m_collection = new double[numLines];
            ifstream istr(this->m_fileName);
            for(;istr >> this->m_collection[size] && size < numLines;size++);
            if(size != numLines) {
                delete[] this->m_collection;
                setEmpty();
            }
            else{
                this->m_arrSize = size;
                this->m_isOriginal = true;
            }
        }
        return size;
    }

    bool Numbers::save() {
        bool retVal{};
        if(this->m_isOriginal && this->m_hasAppend) {
            ofstream ostr(this->m_fileName);
            for(int i = 0 ; i < this->m_arrSize; i++) 
                ostr << fixed << showpoint << setprecision(2)
                    << this->m_collection[i] << endl;
            retVal = true;
        }
        return retVal;
    }

    double Numbers::max() const {
        double max = 0;
        for(int i = 0; i < this->m_arrSize; i++)
            max = this->m_collection[i] > max ? this->m_collection[i] : max;
        return max;
    }

    double Numbers::min() const {
        double min = max();
        for(int i = 0; i < this->m_arrSize; i++)
            min = this->m_collection[i] < min ? this->m_collection[i] : min;
        return min;
    }

    double Numbers::average() const {
        double total{};
        for(int i = 0; i < this->m_arrSize; i++)
            total+=this->m_collection[i];
        return total/this->m_arrSize;
    }

    Numbers::operator bool() const{
        return this->m_collection == nullptr;
    }

    Numbers& Numbers::operator+=(const double value) {
        if(this->m_collection != nullptr) {
            double *temp = new double[m_arrSize + 1];
            for (unsigned int i = 0; i < m_arrSize; i++) 
                temp[i] = m_collection[i];
            temp[m_arrSize++] = value;
            delete[] m_collection;
            m_collection = temp;
            m_hasAppend = true;
        }
        return *this;
    }

    ostream& Numbers::display(ostream& ostr) const {
        if(*this) ostr << "Empty list";
        else {
            ostr << fixed << showpoint << setprecision(2);
            !this->m_isOriginal && ostr << "Copy of numbers.txt";
            for(int i = 0; i < this->m_arrSize; i++) {
                ostr << this->m_collection[i];
                ostr << ((i < this->m_arrSize-1) ? ", " : "\n");
            }
            ostr << setfill('-') << setw(76) << "";
            ostr << endl << "Total of " << this->m_arrSize
              << " number(s), Largest: " << max()
              << ", Smallest: " << min()
              << ", Average: " << average() << endl;
            ostr << setfill('=') << setw(76) << "";
        }
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, Numbers& Rop) {
        return Rop.display(ostr);
    }

    std::istream& operator>>(std::istream& istr, Numbers& Rop) {
        double value;
        istr >> value;
        !istr.fail() ? Rop+= value : nullptr;
        return istr;
    }


    Numbers::~Numbers() {
        save();
        delete[] m_collection;
        setEmpty();
    }

   void Numbers::sort(double* nums, unsigned int size) {
      unsigned int i, j;
      double temp;
      for(i = size - 1; size && i > 0; i--) 
         for(j = 0; j < i; j++) 
            if(nums[j] > nums[j + 1]) 
                swap(nums[j], nums[j+1]);
   }

   unsigned int Numbers::countLines(const char* filename) {
      unsigned int lines = 0u;
      ifstream nums(filename);
      while(nums) {
         lines += (nums.get() == '\n');
      }
      return lines;
   }
}