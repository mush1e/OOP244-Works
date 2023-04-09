/***********************************************************************
                 Validate.h
 Name: Mustafa Siddiqui
 Email: msiddiqui48@myseneca.ca
 Student Id: 117424225
 Date: 08/04/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***************************************************************************/

#include <cstddef>

#ifndef SICT_VALIDATE_H
#define SICT_VALIDAT_H

namespace sict {
    template<typename T>
    bool validate(const T& minimum, const T* testValues, const size_t numElements, bool* results) {
        bool allValid = true;
        for (size_t i = 0; i < numElements; ++i) {
            results[i] = testValues[i] >= minimum;
            allValid &= results[i];
        }
        return allValid;
    }
}

#endif