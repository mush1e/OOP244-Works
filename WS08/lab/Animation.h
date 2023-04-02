#ifndef SDDS_ANIMATION_H
#define SDDS_ANIMATION_H

#include "Video.h"

namespace sdds {
    class Animation : public Video {
        int m_dimension {};
        public:
            Animation();
            Animation(int length, int dimension);
            operator bool() const;
            void load(std::istream& istr)           override;
            std::ostream& play(std::ostream& ostr)  override;
    };
}

#endif