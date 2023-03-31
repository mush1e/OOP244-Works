#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>

namespace sdds {
    class Numbers {
        double* m_collection{};
        char m_fileName[255]{};
        size_t m_arrSize{};
        bool m_isOriginal{};
        bool m_hasAppend{};
        
        unsigned int countLines(const char* filename);
        void sort(double* collectionPtr, unsigned int size);
        bool setEmpty();

    public:
        Numbers(const char* fileName = nullptr);
        Numbers(const Numbers& other);
        ~Numbers();

        Numbers& operator=(const Numbers& other);
        Numbers& operator+=(const double value);
        operator bool() const;

        bool load();
        bool save();
        double max() const;
        double min() const;
        double average() const;
        Numbers& sort();

    std::ostream& display(std::ostream& ostr = std::cout) const;
   };

   std::ostream& operator<<(std::ostream& ostr, Numbers& Rop);
   std::istream& operator>>(std::istream& istr, Numbers& Rop);

}
#endif // !SDDS_NUMBERS_H_
