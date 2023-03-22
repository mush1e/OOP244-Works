#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

using uShort = short;


namespace sdds {
    void getSystemDate(uShort& year, uShort& mon, uShort& day, uShort& hour, uShort& muShor, bool dateOnly);
    uShort uniqueDateValue(uShort year, uShort mon, uShort day, uShort hour, uShort muShor);
    uShort daysOfMonth(uShort year, uShort month);
    
}

#endif