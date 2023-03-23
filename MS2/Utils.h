/*
Final Project Milestone 2
Module: Error
Filename: Utils.h
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
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H




namespace sdds {
    void getSystemDate(int& year, int& mon, int& day, int& hour, int& muShor, bool dateOnly);
    int uniqueDateValue(int year, int mon, int day, int hour, int muShor);
    int daysOfMonth(int year, int month);
    
}

#endif