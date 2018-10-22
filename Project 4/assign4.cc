#include "data.h"
#include "assign4.h"

int main(int argc,char *argv[])
{
  
  string copy;
  
  set<Data> dataset;
  
  if(argc!=2)
    {
      cerr<<"\n Wrong input";
      return -1;
    }
  
  ifstream inp;
  //Opening the file using ifstream taking as input
  inp.open(argv[1]);
  //Error Checking for  the file  whether it is opened Properly or not 
  if(!inp.is_open())
    {
      cerr<<"\n Please make sure that the file exists \n";
      return -1;
    }
  // variable declarations
  int sf=0; //initially taking space found is 0
  string iv="", sv=""; //Initially setting  the integer value  and string value to empty strings
  
  //reading  the values until end of file 
  while(!inp.eof())
    {
      //reading each  data element 
      char element=inp.get();
      //If the data element found is not a space and space found is not set to 1
      if(element!=' '&&sf!=1)
	{
	  iv=iv+element;
	}
      //If character is space,then set the space found to 1
      else if(element==' ')
	{
	  sf=1;
	}
      //If the space found  is 1,and if the new line character is found,then add the values of iv and sv to class and insert that instance to set
      else if(sf==1)
	{
	  //If the new line character found is  '10' then it is the ASCII value of new line
	  if(int(element)==10)
	    {
	      //set the space found to zero
	      sf=0;
	      //calling the parameterized constructor to initialize the values
	      Data p(std::stoi(iv),sv);
              //Inserting the instances into set
	      dataset.insert(p);
	      //setting the iv and sv to empty strings after every new line by taking  separate integer and string values
	      iv="";
	      sv="";
	    }
	  
	  else
	    {
	      sv=sv+element;
	    }
	}
     
      else
	{
	}
      
    }//End of While loop

 
  inp.close();
  
  cout<<"\n"; 
  for(auto i=dataset.begin();i!=dataset.end();++i)
    {
      //copying the string stored in the object into variable created above 
      copy=(*i)[1];  // here the overloaded subscript operator is called which returns a string

      //If the string is "\n" then print a new line character
      if(copy=="\\n")
  {
    cout<<"\n";
  }
      //If the string is not a new line ,then just  print it
      else
  {
    cout<<(*i)<<" ";
  }
    }
  cout<<"\n ";//printing new line after output
  return 0;
}
  

