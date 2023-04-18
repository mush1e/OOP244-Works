/*
*****************************************************************************
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 18 Apr 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_VIDEO_H
#define SDDS_VIDEO_H

#include "Media.h"

namespace sdds {
    class Video : public Media {
        int m_length {};
        
        protected:
            int get() const;
        
        public:
            Video();
            Video(const int value);
            Video(const Video&)            = delete;
            Video& operator=(const Video&) = delete;
            
            void load(std::istream& istr) override;
    };
}

#endif