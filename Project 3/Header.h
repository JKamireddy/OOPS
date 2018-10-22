/*******************************************
COURSE: CSCI689
NAME: SAHITHI KAMIREDDY
ZID: z1831177
INSTRUCTOR: KIRK DUFFIN
TA : NITHIN DEVANG
*******************************************/

/*********** ASSIGNMENT 3 *************/
//header files for assign3
#include<vector>
#include<fstream>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
using namespace std;


#include "Country.h"
#include "Sport.h"
#include "Athelete.h"
#include "Event.h"

void print_countries(vector<Country>&);
void print_sports(vector<Sport>&);
void print_atheletes_by_country(vector<Athelete>&, vector<Country>& );
void print_atheletes_by_name(vector<Athelete>&, vector<Country>& );
int select_sport(vector<Sport>&,int);
void print_ranking_by_sport(int,const vector<Country>&,const vector<Sport>&,const vector<Athelete>&,const vector<Event>&);
