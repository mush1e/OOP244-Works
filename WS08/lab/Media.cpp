#include "Media.h"

using namespace std;

namespace sdds {

    ostream& operator << (ostream& ostr, Media& other) {
        return other.play(ostr);
    }

    istream& operator >> (istream& istr, Media& other) {
        other.load(istr);
        return istr;
    }
}