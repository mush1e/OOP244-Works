#include <iostream>
#include "UI.h"

using namespace std;

namespace sdds {

    char op;
    double value;

    int displayOutput(GPA* gpa) {
        char quitChar;
        int length = recordLength(),
            returnValue = 1;

        cout.precision(1);

        for(int i = 0; i < length; i++) {
            switch(op) {
                case '<':
                    if(gpa[i].gpa < value)
                        cout << gpa[i].stno << ": " <<
                             fixed << gpa[i].gpa  << " ("  
                             << gpa[i].name << ")" << endl;
                    break;

                case '>':
                    if(gpa[i].gpa > value)
                        cout << gpa[i].stno << ": "  <<
                             fixed << gpa[i].gpa  << " ("  
                             << gpa[i].name << ")" << endl;
                    break;

                case '~':
                    if(gpa[i].gpa > value-0.05 && gpa[i].gpa < value+0.05)
                        cout << gpa[i].stno << ": " <<
                             fixed << gpa[i].gpa  << " ("  
                             << gpa[i].name << ")" << endl;
                    break;
                
                default:
                    cout << "Exit the program? (Y)es/(N)o: ";
                    cin >> quitChar;
                    if (quitChar == 'y')
                        returnValue = 0;
            }
        }
        return returnValue;
    }

    void promptUser(GPA* gpa) {
        int flag = 1;
        cout << "Enter GPA query..." << endl;
        while(flag) {
            cout << "? ";
            cin >> op >> value;
            if(op != '>' && op != '<' && op != '~' && op != '!') {
                cout << "Syntax error: ? [Op][value]<ENTER>" << endl 
                     << "Op: [>,<,~,!]" << endl;
                continue;
            }
            flag = displayOutput(gpa);
        }
    }
}