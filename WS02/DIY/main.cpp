/***********************************************************************
// OOP244 Workshop 2 p2: tester program
//
// File	main.cpp
// Version 1.0
// Date   Fall 2022
// Author Yosef Ashibani
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

// Please don't change this file
// This file is to test your source code

#include <iostream>
#include "Customer.h"
using namespace std;
using namespace sdds;

int main() {
    bool Check = false;

    Customers c_rec;
    EmptyRecord(c_rec);

    CustomersRecord t_rec;
    EmptyRecord(t_rec);

    cout << "---------  Customers records entry ------------------" << endl;
    while (!Check) {
        cout << endl<<"Enter customer information (to exit, press Enter): " << endl;
        if (read(c_rec)) {
            addCustomer(t_rec, c_rec);
        }
        else {
            Check = true;
        }
    }
    cout << "---------------------------------------------------------" << endl;
    cout << "                Users' tweets report                     " << endl;
    cout << " user name, re-tweets, likes, replies, share videos (y/n)" << endl;
    cout << "---------------------------------------------------------" << endl;

    display(t_rec);
    cout << "---------------------------------------------------------" << endl;
    cout << "            Report was successfully created                " << endl;

    delete[] t_rec.ptr_rec;
    cout << "Dynamically allocated memory was successfully deallocated" << endl;
    cout << "---------------------------------------------------------" << endl;

    }




/* Sample data entry

user_name    likes_count   retweets_count  replies_count  share_video(y/n)
---------    -----------   --------------  -------------  ---------------
 zebaism       595             234               27             n	    
 rohanv	       12	           0	             1	            n
 frank	       15	           2	             0	            n	
 desibrah      39	           19	             2	            n	
 sheetut       1	           0	             3	            n	


*/

/* Sample execution

---------  Customers records entry ------------------

Enter customer information (to exit, press Enter):
 Enter User name: zebaism
 Enter likes_count: 595
 Enter retweets_count: 234
 Enter replies_count: 27
 Enter share videos (y/n): n

Enter customer information (to exit, press Enter):
 Enter User name: rohanv
 Enter likes_count: 12
 Enter retweets_count: 0
 Enter replies_count: 1
 Enter share videos (y/n): n

Enter customer information (to exit, press Enter):
 Enter User name: frank
 Enter likes_count: 15
 Enter retweets_count: 2
 Enter replies_count: 0
 Enter share videos (y/n): n

Enter customer information (to exit, press Enter):
 Enter User name: desibrah
 Enter likes_count: 39
 Enter retweets_count: 19
 Enter replies_count: 2
 Enter share videos (y/n): y

Enter customer information (to exit, press Enter):
 Enter User name: sheetu
 Enter likes_count: 1
 Enter retweets_count: 0
 Enter replies_count: 3
 Enter share videos (y/n): y

Enter customer information (to exit, press Enter):
 Enter User name:
---------------------------------------------------------
                Users' tweets report
 user name, re-tweets, likes, replies, share videos (y/n)
---------------------------------------------------------
1. zebaism, 595, 234, 27, n

2. rohanv, 12, 0, 1, n

3. frank, 15, 2, 0, n

4. desibrah, 39, 19, 2, y

5. sheetut, 1, 0, 3, y

---------------------------------------------------------
            Report was successfully created
Dynamically allocated memory was successfully deallocated
---------------------------------------------------------

*/

