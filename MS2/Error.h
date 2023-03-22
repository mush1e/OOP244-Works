#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H
#include <iostream>

namespace sdds {
    class Error {
        char* m_ErrMsgPtr{};
        
        public:
            Error(const char* msg = nullptr);
            Error(const Error& other);
            ~Error();

            Error& operator=(const Error& other);
            Error& operator=(const char* value);
            operator bool() const;
            
            Error& clear();
            std::ostream& getMsg(std::ostream& ostr) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Error& err);
}

#endif