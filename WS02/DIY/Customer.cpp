#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {

    // complete
    void EmptyRecord(Customers customer){
        customer.likes_count    = 0;
        customer.replies_count  = 0;
        customer.retweets_count = 0;
        customer.share_videos   = 0;
        memset(customer.user_name, 0, 21);
    }

    void EmptyRecord(CustomersRecord customerRecord) {
        delete[] customerRecord.ptr_rec;
        customerRecord.noOfRecords = 0;
    }

    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }
    
    // complete
   bool read(Customers& rec) {
        char inputString[21] = {'\0'};
        bool returnValue = true;
        cout << "user name: ";
        read(inputString, 21);
        if (inputString[0] != '\0') {
            strCpy(rec.user_name, inputString);
            cout << " Enter likes_count: ";
            cin >> rec.likes_count;
            cout << " Enter retweets_count: ";
            cin >> rec.retweets_count;
            cout << " Enter replies_count: ";
            cin >> rec.replies_count;
            cout << " Enter share videos (y/n): ";
            cin >> rec.share_videos;
        }
        else
            returnValue = false;
        return returnValue;
   }

    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {
        int numberOfRecords = t_rec.noOfRecords + 1;
        Customers *tempRecords = new Customers[numberOfRecords];

        for(int i = 0; i < numberOfRecords - 1; i++)
            tempRecords[i] = t_rec.ptr_rec[i];

        sdds::EmptyRecord(t_rec);
        
        t_rec.ptr_rec = tempRecords;
        t_rec.noOfRecords = numberOfRecords;

        t_rec.ptr_rec[numberOfRecords-1] = c_rec;
    }

    void display(const Customers& c_rec) {
        cout << c_rec.user_name << ", " << c_rec.likes_count << ", " 
             << c_rec.retweets_count << ", " << c_rec.replies_count 
             << ", " << c_rec.share_videos << endl;
    }

    void display(const CustomersRecord& t_rec) {
        for(int i = 0; i < t_rec.noOfRecords; i++) {
            cout << i + 1 << ". ";
            display(t_rec.ptr_rec[i]);
            cout << endl;
        }
    }
  }

