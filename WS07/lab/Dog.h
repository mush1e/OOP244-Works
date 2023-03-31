#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_DOG_H
#define SDDS_DOG_H

#include "Pet.h"

namespace sdds {
    class Dog : public Pet {
        const double m_base = 1.0;
        const double m_create = 4.0;
        const double m_feed = 0.25;
        const double m_respawn = 1.0;
        int m_numberOfWalks{};
        
        public:
            Dog(const char* name, int age = 0, int numberOfWalks = 0);
            Dog& walk();
            Dog& feed();
            Dog& reSpawn();
            operator int() const;
            Dog& operator++(int);
            Dog& operator=(const Dog &other);
            int setWalks(int walks);
    };  
    std::ostream &operator<<(std::ostream &ostr, Dog &ROp);
}

#endif