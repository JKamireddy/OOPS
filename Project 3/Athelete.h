/*******************************************
COURSE: CSCI689
NAME: SAHITHI KAMIREDDY
ZID: z1831177
INSTRUCTOR: KIRK DUFFIN
TA : NITHIN DEVANG
*******************************************/

/*********** ASSIGNMENT 3 *************/
#ifndef ATHELETE_H
#define ATHELETE_H

     //Creating class named athelete which has a const size of 30

const int SIZE=30;
class Athelete
{
	//declaring datamembers of athelete class
	char firstname [SIZE];
	char lastname [SIZE];
	int country;
	int next_by_name;
	int next_by_country;
	//declaring methods  of this class as public
	public:
		char* get_firstname(void);
		char* get_lastname(void);
		int get_country(void);
		int get_next_by_name(void);
		int get_next_by_country(void);
		void print();
};
#endif 
