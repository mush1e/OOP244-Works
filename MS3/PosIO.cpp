#include "PosIO.h"

using namespace std;

namespace sdds {
    ostream& operator<<(ostream& ostr, const PosIO& ROp) {
        return ROp.write(ostr);
    }

    ofstream& operator<<(ofstream& ofstr, const PosIO& ROp) {
        return ROp.save(ofstr);
    }

    istream& operator>>(istream& istr, PosIO& ROp) {
        return ROp.read(istr);
    }

    ifstream& operator>>(ifstream& ifstr, PosIO& ROp) {
        return ROp.load(ifstr);
    }
}