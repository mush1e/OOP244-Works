/*
*****************************************************************************
                              File.cpp
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 17 Jan 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "File.h"

using namespace std;

namespace sdds {

    int length;

    GPA* readRecords(FILE* fptr) {
        static GPA gpaList[100];

        for(length = 0
           ;fscanf(fptr, "%[^,],%d,%lf\n",   gpaList[length].name, 
                                            &gpaList[length].stno, 
                                            &gpaList[length].gpa)==3
           ;length++); 
        
        return gpaList;
    }
    
    int recordLength() {
        return length;
    }
    

}