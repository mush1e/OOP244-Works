#ifndef FILE_H
#define FILE_H
bool openFile(const char filename[]);
void closeFile();
bool readTitle(char title[]);
bool readYear(int* year);
bool readMovieRating(char rating[]);
bool readDuration(int* duration);
bool readGenres(char genres[][11]);
bool readConsumerRating(float* rating);

namespace sdds {
    FILE* fptr = NULL;
    Movie movies[50];
}

#endif