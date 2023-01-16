/*
*****************************************************************************
                              50Best.cpp
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 15 Jan 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include "Movie.h"
using namespace std;
using namespace sdds;

// flushes the keyboard
void flushkeys() {
   while (cin.get() != '\n');
}

// returns true if user enter y or Y
bool yes() {
   char ch = cin.get();
   flushkeys();
   return ch == 'y' || ch == 'Y';
}

int main() {
   bool done = false;
   char genre[128];
   loadMovies();
   cout << "Welcome to 50 top movies of all times \"genre\" search." << endl << endl;
   while (!done) {
      cout << "Enter the movie genre to start the search: ";
      cin >> genre;
      flushkeys();
      displayMoviesWithGenre(genre);
      cout << "Do another search? (Y)es: ";
      done = !yes();
      cout << endl;
   }
   cout << "Goodbye!" << endl;
   return 0;
}
