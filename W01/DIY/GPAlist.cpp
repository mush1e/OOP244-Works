#include <iostream>

#include "GPAlist.h"
#include "UI.h"
#include "File.h"

using namespace std;

namespace sdds {

    FILE* fptr;
    GPA* gpaList;

    void sort(int length) {
        for(int i = 0; i < length - 1; i++) {
            for(int j = 0; j < length - i - 1; j++) {
                if(gpaList[j].gpa < gpaList[j+1].gpa)
                    swap(gpaList[j], gpaList[j+1]);
            }
        }
    }

    bool gpaQuery(const char* filename) {
        fptr = fopen(filename, "r");
        if(fptr) {
            gpaList = readRecords(fptr);
            int length  = recordLength();
            return true;
        }
        else 
            return false;
    }
}

