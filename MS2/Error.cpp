/*
Final Project Milestone 2
Module: Error
Filename: Error.cpp
Version 1.0
Author    Mustafa Siddiqui
Student ID: 117434225
Email: msiddiqui48@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2023/03/20  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/
#include <iostream>
#include <cstring>
#include "Error.h"

using namespace std;

namespace sdds {
    
    Error::Error(const char* msg) {
        m_ErrMsgPtr = nullptr;
        if(msg) {
            this->m_ErrMsgPtr = new char[strlen(msg) + 1];
            memcpy(this->m_ErrMsgPtr, msg, strlen(msg));
            this->m_ErrMsgPtr[strlen(msg)] = '\0';
        }
    }

    Error::Error(const Error& other) {
       if (this != &other) {
          operator=(other);
       }
    }

    Error::~Error() {
          delete[] this->m_ErrMsgPtr;
          this->m_ErrMsgPtr = nullptr;
    }

    Error& Error::operator=(const Error& other) {
        if(other) {
            clear();
            this->m_ErrMsgPtr = new char [strlen(other.m_ErrMsgPtr) + 1];
            memcpy(this->m_ErrMsgPtr, other.m_ErrMsgPtr, strlen(other.m_ErrMsgPtr));
            this->m_ErrMsgPtr[strlen(other.m_ErrMsgPtr)] = '\0';
        }
        return *this;
    }

    Error& Error::operator=(const char* value) {
        clear();
        if(value) {
            this->m_ErrMsgPtr = new char [strlen(value) + 1];
            memcpy(this->m_ErrMsgPtr, value, strlen(value));
            this->m_ErrMsgPtr[strlen(value)] = '\0';
        }
        return *this;
    }

    Error::operator bool() const{
        return this->m_ErrMsgPtr != nullptr;
    }

    Error& Error::clear() {

       if (this->m_ErrMsgPtr) {
          delete[] this->m_ErrMsgPtr;
          this->m_ErrMsgPtr = nullptr;
       }
        return *this;
    }

    ostream& Error::getMsg(ostream& ostr) const {
       if (this->m_ErrMsgPtr) {
          ostr << this->m_ErrMsgPtr;
       }
        return ostr;
    }
    
    ostream& operator<<(ostream& ostr, const Error& err) {
        return err.getMsg(ostr);
    }
}
