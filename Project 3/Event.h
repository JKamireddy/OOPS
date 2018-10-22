/*******************************************
COURSE: CSCI689
NAME: SAHITHI KAMIREDDY
ZID: z1831177
INSTRUCTOR: KIRK DUFFIN
TA : NITHIN DEVANG
*******************************************/

/*********** ASSIGNMENT 3 *************/
#ifndef EVENT_H
#define EVENT_H
    
   //Creating a class called sport with constant scoresize as 25 and atheletesize as 4
const int SCORESIZE=25;
const int ASIZE=4;
class Event
{   
    //declaring datamembers of event class
	int sport ;
	int country;
	char numscore[SCORESIZE];
	int athelete[ASIZE];
	int numrank;
	int next_event_by_index;
	//declaring methods as public 
	public:
	int get_next_event_index(void);
	void print(const vector<Athelete>& atheletes,const vector<Country>& countries);
};
#endif 
