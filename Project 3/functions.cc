/*******************************************
COURSE: CSCI689
NAME: SAHITHI KAMIREDDY
ZID: z1831177
INSTRUCTOR: KIRK DUFFIN
TA : NITHIN DEVANG
*******************************************/

/*********** ASSIGNMENT 3*************/

#include "Header.h"
//function that returns country code taking reference from country class
char* Country :: get_countrycode(void)
{
	return countrycode;
}
//function that returns country fullname taking reference from country class
char* Country :: get_countryfullname(void)
{
	return countryfullname;
}
//method that prints countrycode and countryfullname
void Country :: print()
{
	cout<<get_countrycode()<<" "<<get_countryfullname()<<endl;
}
//function that returns sportname
char* Sport :: get_sport_name(void) {
	return sport_name;
}
//function that returns index of an event
int Sport :: get_index_of_an_event(void) {
	return index_of_an_event;
}
//funciton that prints sportname
void Sport :: print() {
	cout << sport_name << endl;
}
//function that prints records of country
void print_countries(vector<Country>& countries){
	for(unsigned int i=0;i<countries.size();i++) {
		countries[i].print();
	}
	cout << endl;
}
//funciton that prints records of sport
void print_sports(vector<Sport>& sports) {
	for(unsigned int i=0;i<sports.size();i++) {
		sports[i].print();
	}
	cout << endl;
}
//function that returns firstname of athelete class taking reference from athelete class
char* Athelete :: get_firstname(void) {
	return firstname;
}
//function that returns lastname of athelete class taking reference from athelete class
char* Athelete ::  get_lastname(void)
{
 	return lastname;
}
//function that returns country from athelete class
int Athelete :: get_country(void)
{
	return country;
}
//function that returns athelete by name
int Athelete :: get_next_by_name(void)
{
	return next_by_name;
}
//function that returns athelete by country
int Athelete :: get_next_by_country(void)
{
return next_by_country;
}
//function that prints lastname along with firstname from athelete class
void Athelete :: print(void)
{
	cout<<lastname<<", "<<firstname;

}
//function that prints firstname and lastname by using country and  index
void print_atheletes_by_country(vector<Athelete>& atheletes, vector<Country>& countries )
{
	int index=atheletes[0].get_next_by_country();
	for(int i=0;i<atheletes.size();i++)
	{
		if (index<0){ break; }
		int ccodenum=atheletes[index].get_country();
		char* ccode=countries[ccodenum].get_countrycode();
		char* fname=atheletes[index].get_firstname();
		char* lname=atheletes[index].get_lastname();

		cout<<ccode <<" "<<fname<<", "<<lname<<endl;
		index=atheletes[index].get_next_by_country();
	}
}
//function that prints athelete firstname ,lastname,countrycode by name of athelete and index

void print_atheletes_by_name(vector<Athelete>& atheletes, vector<Country>& countries )
{
	int index=atheletes[0].get_next_by_name();
	for(int i=0;i<atheletes.size();i++)
	{
		if (index<0){ break; }
		int ccodenum=atheletes[index].get_country();
		char* ccode=countries[ccodenum].get_countrycode();
		char* fname=atheletes[index].get_firstname();
		char* lname=atheletes[index].get_lastname();

		cout<<fname<<", "<<lname<<" "<<ccode <<endl;
		index=atheletes[index].get_next_by_name();
	}
}
//function that returns next event by index

 int Event :: get_next_event_index(void)
{
	return next_event_by_index;
}

//function that prints athelete lastname and firstname by using object of class country
void Event :: print(const vector<Athelete>& atheletes, const vector<Country>& countries)

{
	Country Obj=countries[country];
	cout << Obj.get_countrycode()<<" ";
	cout << setw(3) << numrank << " "  << setw(3) << numscore<<" " ;
	int i=0;

	while(i<ASIZE) {
		if (athelete[i] !=-1) {
		Athelete AObj=atheletes[athelete[i]];
		cout<<AObj.get_lastname()<<", ";
		cout<<AObj.get_firstname()<<";";
		}
		i++;
	}

	cout << endl;
}
//function that prints sportname with index
int select_sport(vector<Sport>& sports,int elements)

{
	int choice,i=0;
	for(;i<elements;i++)
	{
		cout<<i<<") "<<sports[i].get_sport_name()<<endl;
	}
	//for loop only when the choice is true to select another choice to check rank
	for (;;) {
		cout << endl << "Sport to view";
		cin >> choice;
		//using if loop to print error message with cerr
		if (choice >=0 && choice < i) {
			return choice;
		}

		cerr << "Invalid choice" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}

}

//function that prints that rank of the choosen sport by user using object of sport class  and event index

void print_ranking_by_sport(int choice,const vector<Country>& countries,const vector<Sport>& sports,const vector<Athelete>& atheletes,const vector<Event>& events)

{
	Sport sObj=sports[choice];
	cout<<sObj.get_sport_name()<<endl;
	int event_index= sObj.get_index_of_an_event();

	while(event_index!=-1)
	{
		Event Oevent=events[event_index];
		Oevent.print(atheletes,countries);
		event_index=Oevent.get_next_event_index();

	}

}
