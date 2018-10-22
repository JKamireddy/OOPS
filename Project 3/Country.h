/*******************************************
COURSE: CSCI689
NAME: SAHITHI KAMIREDDY
ZID: z1831177
INSTRUCTOR: KIRK DUFFIN
TA : NITHIN DEVANG
*******************************************/

/*********** ASSIGNMENT 3*************/
#ifndef COUNTRY_H
#define COUNTRY_H

   //Creating a class called country with constant country size as 34 and countrycode size as 4
const int CSIZE=34;
const int CCSIZE=4;
class Country
{
	//declaring datamembers of country class 
	char countrycode [CCSIZE];
	char countryfullname [CSIZE];
	//declaring methods as public
	public:
		char* get_countrycode(void);
		char* get_countryfullname(void);
		void print();
};
#endif 
