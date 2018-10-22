#ifndef ATHELETE_H
#define ATHELETE_H

const int SIZE=30;
class Athelete
{
	char firstname [SIZE];
	char lastname [SIZE];
	int country;
	int next_by_name;
	int next_by_country;
	public:
		char* get_firstname(void);
		char* get_lastname(void);
		int get_country(void);
		int get_next_by_name(void);
		int get_next_by_country(void);
		void print();
};
#endif
