#include <iostream>
#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H

namespace sdds {
    class PosIO{
        public:
            virtual std::ostream& write(std::ostream& ostr)  const = 0;
            virtual std::istream&  read(std::istream& istr)        = 0;
            virtual std::ofstream& save(std::ofstream& ostr) const = 0;
            virtual std::ifstream& load(std::ifstream& istr)       = 0; 
    };

    std::ostream& operator<<(std::ostream& ostr, const PosIO& ROp);
    std::ofstream& operator<<(std::ofstream& ostr, const PosIO& ROp);

    std::istream& operator>>(std::istream& istr, PosIO& ROp);
    std::ifstream& operator>>(std::ifstream& ifstr, PosIO& ROp);
}

#endif