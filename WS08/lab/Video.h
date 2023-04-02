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