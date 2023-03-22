#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Error.h"

using uShort = short;

namespace sdds {

    class Date {

        uShort m_year{};
        uShort m_month{};
        uShort m_day{};
        uShort m_hour{};
        uShort m_min{};
        bool m_dateOnly;
        Error errMsg{};

        bool validateDate();
        void clearDate();

        public:
            Date();
            Date(uShort year, 
                 uShort month, 
                 uShort day,
                 uShort hour = 250,
                 uShort min = 610);
            ~Date();

        Error error() const;

		bool operator==(const Date& D) const;
		bool operator!=(const Date& D) const;
		bool operator< (const Date& D) const;
		bool operator> (const Date& D) const;
		bool operator<=(const Date& D) const;
		bool operator>=(const Date& D) const;

        operator bool() const;

        Date& dateOnly(bool value);

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const; 

    };

    std::ostream& operator<<(std::ostream& ostr, const Date& ROp);
	std::istream& operator>>(std::istream& istr, Date& ROp);

}

#endif