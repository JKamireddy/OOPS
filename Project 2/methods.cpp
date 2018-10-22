#include<vector>
#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
#include "Header.h"
char* Country::get_countrycode(void)
{
	return countrycode;
}

char* Country::get_countryfullname(void)
{
	return countryfullname;
}

void Country::print()
{
	cout<<get_countrycode()<< " "<<get_countryfullname();
}
print_countries(vector<Country> &countries) {
	
for(int i=0;i<countries.size();i++)
{
	countries [i].print();
}
	
}
