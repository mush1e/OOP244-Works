/*
*****************************************************************************
                              File.h
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 15 Jan 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_FILE_H // replace NAMESPACE and HEADERFILENAME with relevant names
#define SDDS_FILE_H
#include <cstdio>
namespace sdds {

    bool openFile(const char filename[]);
    void closeFile();
    bool readTitle(char title[]);
    bool readYear(int* year);
    bool readMovieRating(char rating[]);
    bool readDuration(int* duration);
    bool readGenres(char genres[][11]);
    bool readConsumerRating(float* rating);

}
#endif