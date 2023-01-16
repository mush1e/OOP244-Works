#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include "GPA.h"

namespace sdds {
    GPA* readRecords(FILE* fptr);
    int recordLength();
}

#endif