/*
Final Project Milestone 2
Module: char* Error
Filename: POS.h
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
#ifndef SDDS_POS_H
#define SDDS_POS_H
namespace sdds {
    const double TAX = 0.13;
    const int MAX_SKU_LEN = 7;
    const int MIN_YEAR = 2000;
    const int MAX_YEAR = 2030;
    const int MAX_STOCK_NUMBER = 99;
    const int MAX_NO_ITEMS = 2000;
    int MAX_NAME_LEN = 40;

    int POS_LIST = 1;
    int POS_FORM = 2;

    char* ERROR_POS_SKU= "SKU too long";
    char* ERROR_POS_NAME= "Item name too long";
    char* ERROR_POS_PRICE= "Invalid price value";
    char* ERROR_POS_TAX= "Invalid tax status";
    char* ERROR_POS_QTY= "Invalid quantity value";
    char* ERROR_POS_STOCK= "Item out of stock";
    char* ERROR_POS_EMPTY= "Invalid Empty Item";
}
#endif