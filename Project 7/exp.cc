#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using std::ifstream;
using std::vector;
using std::cout;
using std::string;
using std::stof;
using std::fixed;
using std::setprecision;
int main(int argc,char *argv[])
{
  string a="1234.890786543";
  float f=stof(a);
  cout<<"\n the float value obtained is "<<setprecision(10)<<f;
  return 0;
}
