/*
Final Project Milestone 2
Module: Error
Filename: Utils.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Utils.h"

using namespace std;


namespace sdds {
    void getSystemDate(uShort& year, uShort& mon, uShort& day, uShort& hour, uShort& min, bool dateOnly) {
        time_t t = time(0);
        tm lt = *localtime(&t);
        day = lt.tm_mday;
        mon = lt.tm_mon + 1;
        year = lt.tm_year + 1900;

        if (dateOnly) hour = min = 0;
        else {
            hour = lt.tm_hour;
            min = lt.tm_min;
        }
    }
        
    uShort uniqueDateValue(uShort year, uShort mon, uShort day, uShort hour, uShort min) {
        return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
    }

    uShort daysOfMonth(uShort year, uShort month) {
        uShort days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        uShort mon = month >= 1 && month <= 12 ? month : 13;
        mon--;
        return days[mon] + uShort((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
}