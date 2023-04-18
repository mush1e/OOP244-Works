/*
*****************************************************************************
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 18 Apr 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H

namespace sdds {
    const int RegularEggWieght = 50;
    const int JumboEggWieght = 75;

    class EggCarton {
        int m_size{};
        int m_noOfEggs{};
        bool m_jumboSize{};
        EggCarton& setBroken();
        std::ostream& displayCarton(int size, int noOfEggs, bool jumbo, std::ostream& ostr)const;

        public:
            EggCarton(int size=6, int noOfEggs=0, bool jumboSize=false);
            std::ostream& display(std::ostream& ostr = std::cout) const;
            std::istream& read(std::istream& istr = std::cin);
            operator int() const;
            operator double() const;
            operator bool() const;
            EggCarton& operator--();
            EggCarton& operator++();
            EggCarton operator--(int);
            EggCarton operator++(int);
            EggCarton& operator=(int value);
            EggCarton& operator+=(int value);
            EggCarton& operator+=(EggCarton& right);
            bool operator==(const EggCarton& right) const;


    };
    int operator+(int left, const EggCarton& right);
    std::ostream& operator<<(std::ostream& ostr, const EggCarton& right);
    std::istream& operator>>(std::istream& istr, EggCarton& right);

}

#endif