//Header file for Data class
//Hedaer Guards
#ifndef Data_H
#define Data_H
//including the header files required
#include <iostream>
#include <string>
//declaring the standard namespace variables
using std::string;
using std::ostream;
//Class with data members integer,string and constructors
class Data
{
  //Private Data Members
  int iv;
  string sv;
  //Public members
  public:
  //Data();//Default constructor
  Data(int x,string y);//parameterized constructor
  string operator [](int index)const;//subscript operator overloading that takes integer as an argument but doesn't use that
  bool operator <(const Data &a)const;//overloading comparison opeartor that takes 2 argument that are references to the Data class
  friend ostream& operator <<(ostream & ostr,const Data &b);//Overloading output stram operator that takes 2 arguments that are reference to ostream and constant reference to Data class.This is a friend fucntion
  
};
#endif
//End of header file Data_H
