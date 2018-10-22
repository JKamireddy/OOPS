/*******************************************
COURSE: CSCI689
NAME: SAHITHI KAMIREDDY
ZID: z1831177
INSTRUCTOR: KIRK DUFFIN
TA : NITHIN DEVANG
*******************************************/

/*********** ASSIGNMENT 2 *************/

#include"Functions.h"
//Header File that includes the Declarations of Required Functions

bool IsALeapYear( int year) 
{
   
   if ((year%400==0) || (year%4==0 && year%100!=0)) {
   	return 1;
   }
   else {
   	return 0;
   }
}
// Bool Function that tests for a leapyear

int NoOfDaysInMonth ( int year, int month) {
    int x;

x = month + 11;
x = x * 7;
x = x % 12;

    if (month==2) {
        int y=IsALeapYear(year);
        if (y==1) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (x< 7) {
        return 31;
    }
    else {
        return 30;
    }
}

//return no of days for a given month
int NoOfDaysInWeek(const int year, const int month) {
    int yr = year-1;
    int mn = ((month * 367)-362)/12;
    int flag=0;
    if (month<=2) {
        flag=0;
    }
    else {
        int y=IsALeapYear(year);
        if (y==1) {
            flag=-1;
        }
        else {
            flag=-2;
        }
    }
    return ((yr * 365) + (yr / 4) - (yr/100) + (yr/400) + mn + 1 + flag)%7;
}
//return daysof a month 
void DisplayCal( int year,  int month) {
	
	if ( month == 1)
       cout << "January";
    else if ( month == 2)
       cout << "February";
    else if ( month == 3)
       cout << "March";
    else if ( month == 4)
       cout << "April";
    else if ( month == 5)
       cout << "May";
    else if ( month == 6)
       cout << "June";
    else if ( month == 7)
       cout << "July";
    else if ( month == 8)
       cout << "August";
    else if ( month == 9)
       cout << "September";
    else if ( month == 10)
       cout << "October";
    else if ( month == 11)
       cout << "November";
    else if ( month == 12)
       cout << "December";


    cout << ", " << year << "\n";
    // Displays year header using ifelse statement

    
	cout << " S   M  Tu   W  Th   F   S" << endl;
	
	//Displays days in week
}
//Function that displays calender header with given month and year
