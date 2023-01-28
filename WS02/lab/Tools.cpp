/*
*****************************************************************************
                              Tools.cpp
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 28 Jan 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "Tools.h"
#include "Package.h"

FILE* fp;

namespace sdds {
    int openFile_r(const char filename[]) { // Fully provided
        fp = fopen(filename_r, "r");
        return fp != NULL;
    }
    int noOfTraces() {  // Fully provided
        int noOfTraces = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfTraces += (ch == '\n');
        }
        rewind(fp);
        return noOfTraces;
    }
    

    // To Do: read functions (4 overloaded read functions)
    

    int read(char* package_name) {
        return fscanf(fp, "%60[^\n]\n", package_name); 
    }

    int read(int &user_time) {
        return fscanf(fp, "%d,", &user_time);
    }

    int read(double &time_in_hours) {
        return fscanf(fp, "%lf,", &time_in_hours);
    }

    int read(char &day_of_week) {
        return fscanf(fp, "%[^ \t\n\r\v\f,]%*c", &day_of_week); 
    }


    void closefile() { // Fully provided
        if (fp) fclose(fp);
    }
    
    void strCpy(char* str1, const char* str2) { // Fully provided 
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
    int strLen(const char* str) {  // Fully provided
        int i = -1;
        while (str[++i]);
        return i;
    }
}