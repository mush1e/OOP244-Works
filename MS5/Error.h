/*
Final Project Milestone 5
Module: Error
Filename: Error.h
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
#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H

namespace sdds {
    class Error {
        char* m_ErrMsgPtr{};
        
        public:
            Error(const char* msg = nullptr);
            Error(const Error& other);
            ~Error();

            Error& operator=(const Error& other);
            Error& operator=(const char* value);
            operator bool() const;
            
            Error& clear();
            std::ostream& getMsg(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Error& err);
}

#endif