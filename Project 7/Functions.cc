#include "Amenity.h"
# include "assign8.h"
int input(string file_name,vector<Amenity> &ref)
{
  ifstream inp;
  vector<string> lines;
  char ch;
  int k=0;
  int commas[9]={0};
  string temp_string;
  string id,landform,temp,sunshine,july_temp,july_humidity,terrain,abbr,name;
  inp.open(file_name);
  int id_found=0,abbr_found=0,name_found=0,temp_found=0,sunshine_found=0;
  int july_temp_found=0,humidity=0,terrain_found=0,landform_found=0;
  if(!inp.is_open())
    {
      cerr<<"\n Unable to open file.Please make sure the file exists";
      return -1;
 }
  while(!inp.eof())
    {
	  std::getline(inp,temp_string);
	  if(temp_string!="")
	  lines.push_back(temp_string);
   
    }
  cout<<"\n"<<lines.size()<<" records input.\n" ;
  for(auto i=lines.begin();i!=lines.end();++i)
    {
      for(int s=0;s<(*i).size();s++)
	{
	  if((*i)[s]!=','&&commas[0]==0)
	    {
	      id+=(*i)[s];
	    }
	  else if((*i)[s]==',')
	    {
	      commas[k]=1;
	      k++;
	    }
	  else if(commas[1]==0&&(*i)[s]!=',')
	    {
	      abbr+=(*i)[s];
	    }
	  else if(commas[2]==0&&(*i)[s]!=',')
	    {
	      name+=(*i)[s];
	    }
	  
	  else if(commas[3]==0&&(*i)[s]!=',')
	    {
	      temp+=(*i)[s];
	    }
	  else if(commas[4]==0&&(*i)[s]!=',')
	    {
	      sunshine+=(*i)[s];
	    }
	  else if(commas[5]==0&&(*i)[s]!=',')
	    {
	      july_temp+=(*i)[s];
	    }
	  else if(commas[6]==0&&(*i)[s]!=',')
	    {
	      july_humidity+=(*i)[s];
	    }
	  else if(commas[7]==0&&(*i)[s]!=',')
	    {
             landform+=(*i)[s];
	    }
	  else if(commas[8]==0&&(*i)[s]!=',')
	    {
	      terrain+=(*i)[s];
	    }
	  else
	    {
	    }
	      
	      
	}
      commas[0]=0;commas[1]=0;commas[2]=0;
      commas[3]=0;commas[4]=0;commas[5]=0;
      commas[6]=0;commas[7]=0;commas[8]=0;
      Amenity obj(std::stoi(id),abbr,name,std::stof(temp),std::stof(sunshine),std::stof(july_temp),std::stof(july_humidity),std::stoi(landform),std::stof(terrain));
      ref.push_back(obj);
      //obj.print();
      id.clear();
      landform.clear();
      temp.clear();
      sunshine.clear();
      july_temp.clear();
      july_humidity.clear();
      terrain.clear();
      abbr.clear();
      name.clear();
      k=0;
      
    }
  
  return 0;
}
void Composite_amenity(vector<Amenity> &ref)
{
  vector<float> vector_floats;
  vector_floats.resize(3073);
  transform(ref.begin(),ref.end(),vector_floats.begin(),[](Amenity obj){return obj.get_jan_temp();});
  /*  for(auto i=vector_floats.begin();i!=vector_floats.end();++i)
    cout<<*i<<"\n";
    cout<<"\n size of vector is "<<vector_floats.size();*/
    float amenity1_average=calculate_Average(vector_floats);
    // cout<<"\n Amentiry 1 average is "<<amenity1_average;
    float amenity1_sd=calculate_StandardDeviation(vector_floats,amenity1_average);
    // cout<<"\n Amenity 1 standard deviation is "<<std::setprecision(7)<<amenity1_sd;
    transform(ref.begin(),ref.end(),vector_floats.begin(),[](Amenity obj){return obj.get_jan_sunshine();});
    float amenity2_average=calculate_Average(vector_floats);
    // cout<<"\n Amentiry 2 average is "<<amenity2_average;
    float amenity2_sd=calculate_StandardDeviation(vector_floats,amenity2_average);
    // cout<<"\n Amenity 2 standard deviation is "<<amenity2_sd;
    transform(ref.begin(),ref.end(),vector_floats.begin(),[](Amenity obj){return obj.get_avg_july_temp();});
    float amenity3_average=calculate_Average(vector_floats);
    // cout<<"\n Amentiry 3 average is "<<amenity3_average;
    float amenity3_sd=calculate_StandardDeviation(vector_floats,amenity3_average);
    // cout<<"\n Amenity 3 standard deviation is "<<amenity3_sd;
    transform(ref.begin(),ref.end(),vector_floats.begin(),[](Amenity obj){return obj.get_avg_july_humidity();});
    float amenity4_average=calculate_Average(vector_floats);
    // cout<<"\n Amentiry 4 average is "<<amenity4_average;
    float amenity4_sd=calculate_StandardDeviation(vector_floats,amenity4_average);
    // cout<<"\n Amenity 4 standard deviation is "<<amenity4_sd;
    transform(ref.begin(),ref.end(),vector_floats.begin(),[](Amenity obj){return obj.get_landform();});
    float amenity5_average=calculate_Average(vector_floats);
    // cout<<"\n Amentiry 5 average is "<<amenity5_average;
float amenity5_sd=calculate_StandardDeviation(vector_floats,amenity5_average);
//cout<<"\n Amenity 5 standard deviation is "<<amenity5_sd;
 transform(ref.begin(),ref.end(),vector_floats.begin(),[](Amenity obj){return log(obj.get_terrain()*100);});
    float amenity6_average=calculate_Average(vector_floats);
     //cout<<"\n Amentiry 6 average is "<<amenity6_average;
    float amenity6_sd=calculate_StandardDeviation(vector_floats,amenity6_average);
        //cout<<"\n Amenity 6 standard deviation is "<<amenity6_sd;
    float composite_value;
    for(auto i=ref.begin();i!=ref.end();++i)
      {
	composite_value=(((*i).get_jan_temp()-amenity1_average)/amenity1_sd)+(((*i).get_jan_sunshine()-amenity2_average)/amenity2_sd)+(((*i).get_avg_july_temp()-amenity3_average)/amenity3_sd)+(((*i).get_avg_july_humidity()-amenity4_average)/amenity4_sd)+((log((*i).get_terrain()*100)-amenity5_average)/amenity5_sd)+(((*i).get_landform()-amenity6_average)/amenity6_sd);

	(*i).set_Comp_Amenity_Value(composite_value);
	}
    //Printing the composite Amneity values
    /*    for(auto i=ref.begin();i!=ref.end();++i)
      {
	cout<<"\n"<<(*i).get_Comp_Amenity_Value();
	}*/
}
