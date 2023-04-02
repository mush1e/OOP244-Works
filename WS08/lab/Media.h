#include <iostream>

#ifndef SDDS_MEDIA_H
#define SDDS_MEDIA_H
namespace sdds {

    class Media {
        public:
            virtual std::ostream& play(std::ostream& ostr) = 0;
            virtual void load(std::istream& istr)          = 0;
            virtual ~Media()                               = 0;
    };
    std::ostream& operator << (std::ostream& ostr, Media& other);
    std::istream& operator >> (std::istream& istr, Media& other);
}

#endif