#include "AmenityHelper.h"
AmenityHelper:: AmenityHelper()
{
  id=0;
}
void AmenityHelper:: set_Id(int value)
{
  id=value;
}
int AmenityHelper:: get_Id()
{
  return id;
}
void AmenityHelper:: operator ()(Amenity &ref)
{
  cout<<setw(15)<<right<<ref.get_country_name()<<setw(4)<<right<<ref.get_state_abbr()<<setw(12)<<right;
  switch(id)
    {
    case January_Temperature:
      cout<<ref.get_jan_temp()<<"\n";
      break;
    case January_Sunshine:
      cout<<ref.get_jan_sunshine()<<"\n";
      break;
    case Avg_July_Temperature:
      cout<<ref.get_avg_july_temp()<<"\n";
      break;
    case Avg_July_Humidity:
      cout<<ref.get_avg_july_humidity()<<"\n";
      break;
    case Landform:
      cout<<ref.get_landform()<<"\n";
      break;
    case Terrain:
      cout<<ref.get_terrain()<<"\n";
      break;
    case Composite_Amenity:
      cout<<ref.get_Comp_Amenity_Value()<<"\n";
      break;
    default:
      cout<<"\n Please do enter valid Choice \n";
      break;
    }
}
bool AmenityHelper:: operator ()(const Amenity &ref1,const Amenity &ref2)
{
  return (ref1.get_Comp_Amenity_Value()>ref2.get_Comp_Amenity_Value());
}
void print_top_bottom_n(vector<Amenity> &obj,int n,AmenityHelper&inst)
{
  int top=1;
  int bottom=n;
  int num=1;
  for_each(obj.begin(),obj.end(),[&n,&inst,&top](Amenity &ref){if(top<=n)inst(ref);top++;});
  cout<<"\n ...\n";
  for_each(obj.begin(),obj.end(),[&inst,&bottom,&num,&obj](Amenity &ref){if((obj.size()-num)<bottom)inst(ref);num++;});
}
