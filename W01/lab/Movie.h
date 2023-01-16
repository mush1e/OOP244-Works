/*
*****************************************************************************
                              Movie.h
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 15 Jan 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_MOVIE_H // replace NAMESPACE and HEADERFILENAME with relevant names
#define SDDS_MOVIE_H

#include "File.h"
namespace sdds {
    struct Movie {
        char m_title[128];
        int m_year;
        char m_rating[6];
        int m_duration;
        char m_genres[10][11];
        float m_consumerRating;
    };
    bool loadMovies();
    void displayMoviesWithGenre(const char genre[]);

}
#endif