#include<vector>
#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;

#include "Header.h"
#include "methods.cpp"

int main()
{
	ifstream inp;
	inp.open("olympic.dat",ios::binary);
	
	vector<Athelete> athelets;
	Athelete objAthelete;
	
	vector<Country> countries;
	Country country;
	
	int cvalue;
	inp.read((char *) &cvalue, sizeof (cvalue));
	for(int i=0;i<cvalue;i++)
	{
	inp.read((char *) &country, sizeof (country));
	countries.push_back(country);
	
	
	}
	
	inp.close();
	print_countries(countries);
	}

