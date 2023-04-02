#include <iostream>
#include "Video.h"

using namespace std;

namespace sdds {

    Video::Video()  {}    // Values already initialised to default

    Video::Video (const int value) {
        this->m_length = value > 0 ? value : 0;
    }

    int Video::get() const {
        return this->m_length;
    }

    void Video::load(std::istream& istr) {
        char delim;
        istr >> this->m_length >> delim;
    }

}