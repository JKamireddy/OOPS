/*******************************************
COURSE: CSCI689
NAME: SAHITHI KAMIREDDY
ZID: z1831177
INSTRUCTOR: KIRK DUFFIN
TA : NITHIN DEVANG
*******************************************/

/*********** ASSIGNMENT 3 *************/

#ifndef SPORT_H
#define SPORT_H
#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::cerr;
  
   //creating  class called sport which has const size as 60
   
const int SPORT_NAME_SIZE = 60;

class Sport {
	//declaring datamembers
	char sport_name[SPORT_NAME_SIZE];
	int index_of_an_event;

public:
	//declaring  methods as public 
	char* get_sport_name(void);
	int get_index_of_an_event(void);
	void print();
};
#endif
