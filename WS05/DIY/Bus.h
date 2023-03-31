#include <iostream>
#ifndef SDDS_BUS_H
#define SDDS_BUS_H

namespace sdds {
    const double ticketPrice = 125.34;
    class Bus{
        int m_noOfSeats{};
        int m_noOfPassengers{};
        std::ostream& drawBus(int seats, int noOfPassengers, std::ostream& ostr) const;
        Bus& setOutOfService();
        public:
            Bus(int noOfSeats = 20, int noOfPassengers = 0);
            std::ostream& display(std::ostream& ostr = std::cout) const;
            std::istream& read(std::istream& istr = std::cin);
            operator bool()const;
            operator int()const;
            operator double()const;
            bool operator--();
            bool operator++();
            bool operator--(int);
            bool operator++(int);
            Bus& operator=(int value);
            Bus& operator+=(int value);
            Bus& operator+=(Bus& ROp);
            bool operator==(Bus& ROp)const;
    };
    int operator+(int LOp, Bus& ROp);
    std::ostream& operator<<(std::ostream& ostr, const Bus& right);
    std::istream& operator>>(std::istream& istr, Bus& right);
}

#endif