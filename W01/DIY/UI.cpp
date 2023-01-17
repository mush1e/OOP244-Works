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
                cout << flag << endl;
                continue;
            }

            else if(op != '>' && op != '<' && op != '~') {
                cout << "Syntax error: ? [Op][value]<ENTER>" << endl 
                     << "Op: [>,<,~,!]" << endl;
                continue;
            }

            value = ((int)(str[1])-48) + 0.1*((int)(str[3])-48);
            flag = displayOutput(gpa);
        }
    }
}