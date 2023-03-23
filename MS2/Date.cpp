/*
Final Project Milestone 2
Module: Error
Filename: Date.cpp
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
#include <iomanip>
#include "Date.h"
#include "Error.h"
#include "POS.h"
#include "Utils.h"

using namespace std;

namespace sdds {
    Date::Date() {
        getSystemDate(this->m_year, 
                      this->m_month, 
                      this->m_day, 
                      this->m_hour, 
                      this->m_min, 
                      this->m_dateOnly);
    }

    Date::Date(int year, int month, int day, int hour , int min) {
        this->m_year = year;
        this->m_month = month;
        this->m_day = day;
        this->m_hour = hour;
        this->m_min = min;
        this->m_dateOnly = false; 
        validateDate();
    }

    Date::Date(int year, int month, int day) {
        this->m_year = year;
        this->m_month = month;
        this->m_day = day;
        this->m_dateOnly = true; 
        validateDate();
    }


    Date::~Date() {}

    bool Date::validateDate() {
        if(!errMsg) 
            (this->m_year >= MAX_YEAR || this->m_year <= MIN_YEAR) ? 
                    errMsg = "Invalid Year" :
                     errMsg;
        if(!errMsg)
            (this->m_month > 12) ? errMsg = "Invalid Month" : errMsg;
        
        if(!errMsg)
            (this->m_month > daysOfMonth(this->m_year, this->m_month)) ? errMsg = "Invalid Day" : errMsg;

        if(!errMsg && !this->m_dateOnly) {
            if(this->m_hour > 23)        errMsg = "Invalid Hour";
            else if (this-> m_min > 59)  errMsg = "Invalid Minute";
        }
        return errMsg;        
    }

    Date& Date::dateOnly(bool value) {
        this->m_dateOnly = value;
        return *this;
    }

    bool Date::operator==(const Date& D) const {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_min) == uniqueDateValue(D.m_year, D.m_month, D.m_day, D.m_hour, D.m_min);
    }

    bool Date::operator!=(const Date& D) const {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_min) != uniqueDateValue(D.m_year, D.m_month, D.m_day, D.m_hour, D.m_min);
    }

    bool Date::operator<(const Date& D) const {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_min) < uniqueDateValue(D.m_year, D.m_month, D.m_day, D.m_hour, D.m_min);
    }

    bool Date::operator>(const Date& D) const {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_min) > uniqueDateValue(D.m_year, D.m_month, D.m_day, D.m_hour, D.m_min);
    }

    bool Date::operator>=(const Date& D) const {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_min) >= uniqueDateValue(D.m_year, D.m_month, D.m_day, D.m_hour, D.m_min);
    }
    bool Date::operator<=(const Date& D) const {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_min) <= uniqueDateValue(D.m_year, D.m_month, D.m_day, D.m_hour, D.m_min);
    }

    Date::operator bool() const{
        return !this->errMsg;
    }

    Error Date::error() const {
        return errMsg;
    } 

    istream& Date::read(istream& istr) {
        int year, month, day, hour, min;
        char delim;
        errMsg.clear();
        if(!(istr>>year))                       errMsg = "Cannot read year entry";
        istr >> delim;
        if(!errMsg && !(istr>>month))           errMsg = "Cannot read month entry";
        istr >> delim;
        if(!errMsg && !(istr>>day))             errMsg = "Cannot read day entry";  
        if(!this->m_dateOnly) {
            istr >> delim;
            if(!errMsg && !(istr>>hour))        errMsg = "Cannot read hour entry";
            istr >> delim;
            if(!errMsg && !(istr>>min))         errMsg = "Cannot read minute entry";
            *this = Date(year, month, day, hour, min);
        }
        else
            *this = Date(year, month, day);
        return istr;
    }

    ostream& Date::write(ostream& ostr) const{
        ostr << setw(2) << setfill('0');
        if (this->errMsg) {
            ostr << errMsg << "(" << m_year<< "/" << setfill('0') << setw(2) << m_month << "/" << setw(2) << m_day ;
            if(m_dateOnly)    ostr << ")";
            else              ostr << ", " << setfill('0') << setw(2) << m_hour << ":" << setw(2) << m_min << ")";
        }
        else {
            ostr << m_year<< "/" << setfill('0') << setw(2) << m_month << "/" << setw(2) << m_day;
            if(!m_dateOnly)  ostr << ", " << setfill('0') << setw(2) << m_hour << ":" << setw(2) << m_min;
        }
        return ostr;
    }

    ostream& operator<<(ostream& ostr, const Date& ROp) {
        return ROp.write(ostr);
    }

    istream& operator>>(istream& istr, Date& ROp) {
        return ROp.read(istr);
    }
}
