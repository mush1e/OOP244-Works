#include <iostream>
#include "File.h"

using namespace std;

namespace sdds {

    GPA gpaList[100];
    int length;

    GPA* readRecords(FILE* fptr) {

        for(    length = 0
            ;   fscanf(fptr, "%[^,],%d,%lf\n",   gpaList[length].name, 
                                                &gpaList[length].stno, 
                                                &gpaList[length].gpa)==3
            ;   length++); 
        
        return gpaList;
    }
    
    int recordLength() {
        return sdds::length;
    }
    

}