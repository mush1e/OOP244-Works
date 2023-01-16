#include <iostream>

#include "GPAlist.h"
#include "UI.h"
#include "File.h"

using namespace std;

namespace sdds {

    FILE* fptr;
    GPA* gpa;

    bool gpaQuery(const char* filename) {
        fptr = fopen(filename, "r");
        if(fptr) {
            gpa = readRecords(fptr);
            int length  = recordLength();
            return true;
        }
        else 
            return false;
    }
}

