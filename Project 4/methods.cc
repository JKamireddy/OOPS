//Implementing cmethods declared in class Data
//Including the header file of  Data Class 
#include "data.h"
//Parametrized constructor which takes arguments int and string
Data :: Data(int x,string y)
{
  iv=x;
  sv=y;
} 
/*Overloadig less than operator that compares instances of class
taking one argument reference from class and returns bool
and is constant as the current class instance does not chnage*/
bool Data :: operator <(const Data &a)const
{
 
  return (iv<a.iv);
  
}
/* Overloading subscripting operator 
which takesI one integer argument and returns string*/
string Data :: operator [](int index)const
{
  return(*this).sv;
  
}
/*Overloading output operator taking 2 arguments
one as reference to ostream and second is reference to constant Data class
returns reference to output stream since we are chaining the output.*/
ostream& operator <<(ostream &ostr,const Data &b)
{
  ostr<<(b).sv;
  return ostr;
}
//end of  Data Class implementation
