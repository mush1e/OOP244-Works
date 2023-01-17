/*
*****************************************************************************
                              File.h
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 17 Jan 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "GPA.h"

namespace sdds {
    GPA* readRecords(FILE* fptr);
    int recordLength();
}

#endif