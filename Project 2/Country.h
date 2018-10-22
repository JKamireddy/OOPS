#ifndef COUNTRY_H
#define COUNTRY_H

const int CSIZE=34;
const int CCSIZE=4;
class Country
{
	char countrycode [CCSIZE];
	char countryfullname [CSIZE];
	public:
		char* get_countrycode(void);
		char* get_countryfullname(void);
		void print();
};
#endif
