/*
*****************************************************************************
                              UI.cpp
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 17 Jan 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "UI.h"

using namespace std;

namespace sdds {

    char op;
    double value;

    int displayOutput(GPA* gpa) {
        int length = recordLength(),
            returnValue = 1;

        cout.precision(1);

        for(int i = 0, count = 0; i < length; i++) {
            switch(op) {
                case '<':
                    if(gpa[i].gpa < value)
                        cout << "[" << ++count << "] " << gpa[i].stno 
                             << ": " << fixed << gpa[i].gpa 
                             << " (" << gpa[i].name << ")" << endl;
                    break;

                case '>':
                    if(gpa[i].gpa > value)
                        cout << "[" << ++count << "] " << gpa[i].stno 
                             << ": " << fixed << gpa[i].gpa 
                             << " (" << gpa[i].name << ")" << endl;
                    break;

                case '~':
                    if(gpa[i].gpa > value-0.05 && gpa[i].gpa < value+0.05)
                        cout << "[" << ++count << "] " << gpa[i].stno 
                             << ": " << fixed << gpa[i].gpa 
                             << " (" << gpa[i].name << ")" << endl;
                    break;
            }
        }
        return returnValue;
    }

    void promptUser(GPA* gpa) {
        int flag = 1;
        char str[4] = {'\0'};
        char quitChar;
        cout << "Enter GPA query..." << endl;

        while(flag) {

            cout << "? ";
            cin >> str;
            op = str[0];

            if(op == '!') {
                cout << "Exit the program? (Y)es/(N)o: ";
                cin >> quitChar;
                flag = quitChar == 'y'  ?  0 : 1;
                continue;
            }

            else if(op != '>' && op != '<' && op != '~') {
                cout << "Syntax error: ? [Op][value]<ENTER>" << endl 
                     << "Op: [>,<,~,!]" << endl
                     << "value: GPA value" << endl << endl;
                     flag = 1;
                continue;
            }

            value = ((int)(str[1])-48) + 0.1*((int)(str[3])-48);
            flag = displayOutput(gpa);
        }
    }
}