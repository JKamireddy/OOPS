//Header file for AmenityHelper class
#ifndef Amenity_Helper
#define Amenity_Helper
#include "Amenity.h"
#include <iostream>
#include <vector>
#include <iomanip>
using std::vector;
using std::setw;
using std::right;
using std::left;
const int January_Temperature=1;
const int January_Sunshine=2;
const int Avg_July_Temperature=3;
const int Avg_July_Humidity=4;
const int Landform=5;
const int Terrain=6;
const int Composite_Amenity=7;
class AmenityHelper
{
  int id;
 public:
  AmenityHelper();
  void set_Id(int value);
  int get_Id();
  void operator ()(Amenity &ref);
  bool operator ()(const Amenity &ref1,const Amenity&ref2);

};
  void print_top_bottom_n(vector <Amenity> &obj,int n,AmenityHelper &inst);
#endif
