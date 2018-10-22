#ifndef SPORT_H
#define SPORT_H

 const char sportname [60];

class Sport
{
	char sportname [CCSIZE];

	public:
		char* get_sportname(void);
		void print();
};
#endif
