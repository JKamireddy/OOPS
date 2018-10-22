/*******************************************
COURSE: CSCI689
NAME: SAHITHI KAMIREDDY
ZID: z1831177
INSTRUCTOR: KIRK DUFFIN
TA : NITHIN DEVANG
*******************************************/

/*********** ASSIGNMENT 3 *************/

#include "Header.h"
#include "functions.cc"



int main()
{
	string filename;
	cout<<"Enter the file name: ";
	cin>>filename;
	
	//Error checking for user given file using ifstream
	ifstream inp;
	inp.open(filename.c_str(),ios::binary);
	if(inp.fail())
	{
		cerr<<"Invalid File";
		exit(0);
	}

//initializing vectors and objects for vectors country sport athelete and event
	vector<Country> countries;
	Country country;

    vector<Sport> sports;
	Sport sport;
	
	vector<Athelete> atheletes;
	Athelete athelete;
    
    vector<Event> events;
    Event event;
    
    // records of country are read into vector countries taking address(reference) of country  and size of vector by for loop
	int cvalue;
	inp.read((char *) &cvalue, sizeof (cvalue));
	for(int i=0;i<cvalue;i++)
	{
	inp.read((char *) &country, sizeof (country));
	countries.push_back(country);
	}
    // records of sport are read into vector sports taking address(reference) ofsport  and size of vector by for loop
	int svalue;
	inp.read((char *) &svalue, sizeof (svalue));
	for(int i=0;i<svalue;i++)
	{
	inp.read((char *) &sport, sizeof (sport));
	sports.push_back(sport);
	}
    // records of athelete are read into vector atheletes taking reference  and size of vector by for loop
	int avalue;
	inp.read((char *) &avalue, sizeof (avalue));
	for(int i=0;i<avalue;i++)
	{
	inp.read((char *) &athelete, sizeof (athelete));
	atheletes.push_back(athelete);
	}
    // records of event are read into vector events taking reference  and size of vector by for loop
	int evalue;
	inp.read((char *) &evalue, sizeof (evalue));
	for(int i=0;i<evalue;i++)
	{
	inp.read((char *) &event, sizeof (event));
	events.push_back(event);
	}
	//closing the opened file after reading it
	inp.close();

    /*Printing the choices to user 
     the options are given to user unless he chooses q using while loop
     using switch statement records from dat file are printed according to user choice
    */
    char choice;

	while(choice != 'Q' && choice != 'q') {
        cout<<"1)print countries"<<endl;
        cout<<"2)print sports"<<endl;
        cout<<"3)print athelete by name"<<endl;
        cout<<"4)print athelete by country"<<endl;
        cout<<"5)print ranking by sport"<<endl;
        cout<<"q)uit"<<endl;
        cout<<"choice?"<<endl;
    	cin >> choice;
        switch(choice)
        {
            case '1':
            {
            	//Calling the funciton called print_countries that prints records of country 
                print_countries(countries);
                break;
            }
            case '2':
                {
                 //Calling the function called print_sports that prints records of sport
                print_sports(sports);
                break;
                }
            case '3':
				{
				//calling function called print_atheletes_by_name that prints records of atheletes by name
				print_atheletes_by_name(atheletes,countries);		
                break;
           		 }
            case '4':
				{
				//calling function called print_atheletes_by_country that prints records of atheletes by country
				print_atheletes_by_country(atheletes,countries);		
				break;
				}
            case '5':
				{
			    /*calling function called select_sports that provides user to choose
				particular sport which return position of their choosed sport and position
				of choosen sport is obtained by calling fuunction print_ranking_by_sport 
				which return  name of the identified sport, and then extracts the starting 
				event index value from the same sport
			    */
				int choice=select_sport(sports,sports.size());
				print_ranking_by_sport(choice,countries,sports,atheletes,events);
				
				}
            case 'q':
            case 'Q': {
                cout << endl;
                break;
                }
            default: 	
                cerr << "Invalid Choice"<< endl;
                break;
                // Priting error message for invalid choice using cerr
        }
	}

	return 0;
}

