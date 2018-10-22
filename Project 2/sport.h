#ifndef SPORT_H
#define SPORT_H

 const char name [60];
 const int event[];

class Sport
{
	char sportname [60];
	int event[];
	

	public:
		char* get_sportname(void);
		int* get_sportevent(void);
		void print();
};
#endif
