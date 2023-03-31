#include <iostream>
#include "Dog.h"

using namespace std;

namespace sdds {
    Dog::Dog(const char* name, int age, int numberOfWalks) : 
                                  Pet(name, age, m_create) {
        m_numberOfWalks = numberOfWalks;
    }

    Dog& Dog::operator++(int) {
        if(this->isAlive()) {
            double healthDelta = 0;
            healthDelta += 0.15 * (getHugs()   - 1);
            healthDelta += 0.10 * (getFeeds()  - 2);
            healthDelta += 0.10 * (getGrooms() - 1);
            healthDelta += 0.20 * (m_numberOfWalks  - 2);
            this->applyHealthDelta(healthDelta);
        }
        Pet::operator++(0); 
        return *this;
    }

    Dog::operator int() const{
        return m_numberOfWalks;
    }

    Dog& Dog::operator=(const Dog& other) {
        if(this != &other) {
            Pet::operator=(other);
            this->addCharge((m_create + m_base) * 2);
            this->m_numberOfWalks = other;
        }
        return *this;
    }

    Dog& Dog::feed() {
        Pet::feed();
        this->isAlive() ? this->addCharge(m_feed) : this->addCharge(0);
        return *this;
    }

    Dog& Dog::reSpawn() {
        Pet::reSpawn();
        this->addCharge(m_respawn);
        return *this;
    }

    Dog& Dog::walk() {
        this->isAlive() ? m_numberOfWalks++ : 0;
        return *this;
    }

    ostream &operator<<(ostream &ostr, Dog &ROp) {
        ostr << "** Generic Dog **" << endl; 
        ostr << "   Walks: " << int(ROp) << endl;
        return ROp.outputData(ostr);
    }
    
}
