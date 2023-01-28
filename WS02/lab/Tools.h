#ifndef SDDS_TOOLS_H_
#define SDDS_TOOLS_H_

namespace sdds {
	int openFile_r(const char filename[]); // Provided
	void closefile(); // Provided
	int noOfTraces(); // Provided

	// ADD: Declare read prototypes (4 prototypes)
    int read(char* package_name);
    int read(int &user_time);
    int read(double &time_in_hours);
	int read(char &day_of_week);


	void strCpy(char* des, const char* src); // Provided
	int strLen(const char* s); // Provided
}
#endif 
