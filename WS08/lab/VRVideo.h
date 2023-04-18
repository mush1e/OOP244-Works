/*
*****************************************************************************
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 18 Apr 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_VRVIDEO_H
#define SDDS_VRVIDEO_H

#include "Video.h"

namespace sdds {

    class VRVideo : public Video {
        char* m_equipment {};

        public:
            VRVideo(); 
            VRVideo(int length, const char* equipment);
            ~VRVideo();

            operator bool() const;

            void load(std::istream& istr)           override;
            std::ostream& play(std::ostream& ostr)  override;

    };

}

#endif