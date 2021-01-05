

/*********** ASSIGNMENT 2 *************/


#include"Functions.h"
//Header File that includes the Declarations of Required Functions


int main ()
{
	int month, year;
	cout << "Month and Year? ";
	cin >> month >> year;

    if (month <= 0 || month>12 ) 
	{
        cout << "Invalid data. Month should be between 1-12" << endl;
        return 0;
    }
    
    if(year<=0)
    {
	cout<<"Year must be positive"<<endl;
    return 0;
	}
	
	
   


	DisplayCal(year, month);

    int days = NoOfDaysInMonth(year, month);
    int ndw = NoOfDaysInWeek(year, month);

	int j=0;
	while (j<ndw) {
		cout << setw(4) << " ";
		j++;
	}
	
	int i=1;
	while (i<=days) {
		cout << setw(2) << i << " ";
		i++;
        if (ndw>=6) {
            cout << endl;
        }
        else {
            cout << " ";
        }
        ndw++;
        if (ndw==7) {
            ndw=0;
        }		
	}
	
    cout << endl;	
	
    return 0;
}
