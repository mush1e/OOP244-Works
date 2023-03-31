#ifndef SDDS_FISH_H
#define SDDS_FISH_H

#include "Pet.h"

namespace sdds {
    class Fish : public Pet {
       const double m_create = 2.0;
       const double m_feed = 0.1;
       const double m_respawn = 0.5;

        public:
            Fish(const char* name, int age = 0);
            Fish& feed();
            Fish& reSpawn();

            Fish& operator++(int);
            Fish& operator=(const Fish& other);            
    };
        std::ostream &operator<<(std::ostream &ostr, Fish &ROp);
}

#endif