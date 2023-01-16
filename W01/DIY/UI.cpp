#include <iostream>
#include "UI.h"

using namespace std;

namespace sdds {

    char op;
    double value;

    void displayOutput(GPA* gpa) {
        int length = recordLength();
        cout.precision(2);
        for(int i = 0; i < length; i++) {
            switch(op) {
                case '<':
                    if(gpa[i].gpa < value)
                        cout << gpa[i].stno << ": " 
                             << gpa[i].gpa  << " ("  
                             << gpa[i].name << ")" << endl;
                    break;
            }
        }
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
            displayOutput(gpa);
        }
    }
}