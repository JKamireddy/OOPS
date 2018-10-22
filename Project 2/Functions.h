/*Header Guard*/
/*******************************************
COURSE: CSCI689
NAME: SAHITHI KAMIREDDY
ZID: z1831177
INSTRUCTOR: KIRK DUFFIN
TA : NITHIN DEVANG
*******************************************/

/*********** ASSIGNMENT 2 *************/

#ifndef FUNCTIONS_H

#define FUNCTIONS_H

#include <iostream>
#include <iomanip>

using std::cout;

using std::cin;

using std::endl;

using std::setw;

/*Function declarations */

bool IsALeapYear( int year);

int NoOfDaysInMonth ( int year, int month);


int NoOfDaysInWeek(const int year, const int month);

void DisplayCal( int year,  int month);

#endif/*FUNCTIONS_H*/
