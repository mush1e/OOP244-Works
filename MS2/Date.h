/*
Final Project Milestone 2
Module: Error
Filename: Date.h
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
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Error.h"

using uShort = short;

namespace sdds {

    class Date {

        uShort m_year{};
        uShort m_month{};
        uShort m_day{};
        uShort m_hour{};
        uShort m_min{};
        bool m_dateOnly;
        Error errMsg;

        bool validateDate();
        void clearDate();

        public:
            Date();

            Date(uShort year, 
                 uShort month, 
                 uShort day);

            Date(uShort year, 
                 uShort month, 
                 uShort day,
                 uShort hour,
                 uShort min = 0);

            ~Date();

        Error error() const;

		bool operator==(const Date& D) const;
		bool operator!=(const Date& D) const;
		bool operator< (const Date& D) const;
		bool operator> (const Date& D) const;
		bool operator<=(const Date& D) const;
		bool operator>=(const Date& D) const;

        operator bool() const;

        Date& dateOnly(bool value);

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const; 

    };

    std::ostream& operator<<(std::ostream& ostr, const Date& ROp);
	std::istream& operator>>(std::istream& istr, Date& ROp);

}

#endif