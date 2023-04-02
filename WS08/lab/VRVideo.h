#ifndef SDDS_VRVIDEO_H
#define SDDS_VRVIDEO_H

#include "Video.h"

namespace sdds {

    class VRVideo : public Video {
        char* m_equipment;

        public:
            VRVideo(); 
            VRVideo(int length, char* equipment);
            ~VRVideo();

            operator bool() const;

            void load(std::istream& istr)           override;
            std::ostream& play(std::ostream& ostr)  override;

    };

}

#endif