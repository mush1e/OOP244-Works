/*
*****************************************************************************
                              GPAlist.cpp
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 17 Jan 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>

#include "GPAlist.h"
#include "UI.h"
#include "File.h"

using namespace std;

namespace sdds {

    FILE* fptr;
    GPA* gpaList;

    void sortGPA(int length) {
        for(int i = 0; i < length - 1; i++) 
            for(int j = 0; j < length - i - 1; j++) {

                if(gpaList[j].gpa > gpaList[j+1].gpa)
                    swap(gpaList[j], gpaList[j+1]);

                if(gpaList[j].gpa == gpaList[j+1].gpa && 
                   gpaList[j].name > gpaList[j+1].name)
                        swap(gpaList[j], gpaList[j+1]);
            }
    }

    bool gpaQuery(const char* filename) {
        bool retVal = true;
        fptr = fopen(filename, "r");
        if(fptr) {
            gpaList     = readRecords(fptr);
            int length  = recordLength();
            sortGPA(length);
            promptUser(gpaList);
            fclose(fptr);
        }
        else {
            retVal = false;
        }
        return retVal;
    }
}

