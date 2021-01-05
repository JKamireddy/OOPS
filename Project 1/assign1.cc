

/******************************************************************************
  *                                                    *
  *                                                     *
  *  Date: 02-01-2018.                                                        *
  *  Description: Printing the Heat Index table using Air Temperatures                                                                         *
  *               and Relative Humidity.
                                                           *
  *                                                                           *
  *                                                                           *
******************************************************************************/

#include<iostream>
#include<iomanip>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::right;
float relhcal(float,float);
void heatindex(float,float,float,float,float,float);

int main()                                               /* main function*/
{
float  temph=0,templ=0,tempi=0;                          /*declaring temperature highrange, lowrange, and increment  values*/
float  rhuml=0, rhumh=0, rhumi=0;                        /*declaring relativehumidity lowrange, highrange and increment values*/
cout<<"PROGRAM TO PRINT HEAT INDEX TABLE "<<endl;
cout<<"Temparature range low value (degrees F) ?";
cin>>templ;
while(cin.fail())                                              /* Performing error checking*/
    {
      cout<<endl<<"PLEASE ENTER VALUES NOT CHARACTERS OR STRINGS OR SYMBOLS";
	cout<<endl;
	return 0;
    }
cout<<"Temparature range high value(degrees F) ?";
cin>>temph;
while(cin.fail())
    {
      cout<<endl<<"PLEASE ENTER VALUES NOT CHARACTERS OR STRINGS OR SYMBOLS";
	cout<<endl;
	return 0;
    }
    while(templ>temph)
{
cout<<endl<<"PLEASE MAKE SURE THAT TEMPERATURE LOW VALUE SHOULD BE LESS THAN TEMPERATURE HIGH VALUE";
cout<<endl;
return 0;

}
cout<<"Temparature range increment value (degree F) ?";
cin>>tempi;
while(tempi<=0 || tempi>temph-templ)
{ cout<<endl<<"PLEASE DO ENTER POSTIVE VALUES NOT NEGATIVE VALUES AND VALUES SHOULDN'T BE GREATER THAN TEMP LOW  AND HIGH RANGES' ";
cout<<endl;
return 0;
}
cout<<endl<<"Relative humidity low range value (%)?";
cin>>rhuml;
while(cin.fail())
{cout<<endl<<" PLEASE  ENTER VALUES NOT CHARACTERS OR STRINGS OR SYMBOLS";
cout<<endl;
return 0;
}
cout<<endl<<" Relative humidity high range value(%)?";
cin>>rhumh;
while (cin.fail())
{cout<<"PLEASE ENTER VALUES NOT CHARACTERS OR STRINGS OR SYMBOLS";
cout<<endl;
return 0;
}
cout<<endl<<"Relative humidity increment value(%)?";
cin>>rhumi;
while(rhumi<=0 || rhumi>rhumh-rhuml)
{cout<<endl<<"PLEASE DO ENTER POSITIVE VALUES NOT NEGATIVE VALUES AND VALUES SHOULDN'T BE GREATER THAN RHUM LOW AND HIGH RANGE ";
cout<<endl;
return 0;
}

heatindex(temph,templ,tempi,rhuml,rhumh,rhumi);       /*function heatindex is called in the main function to print the given values*/
return 0;

}



float heincal(float x1, float y1) /*function to calculate heatindex for airtemparature and relative humidity*/
{
float atmp= x1; float relh=y1;
float hein;
hein= -42.379 + 2.04901523*x1 + 10.1433127*y1 - 0.22475541*x1*y1- 6.83783*pow(10,-3)*pow(x1,2) - 5.481717*pow(10,-2)*pow(y1,2) +1.22874*pow(10,-3)*pow(x1,2)*relh +8.5282*pow(10,-4)*x1*pow(y1,2) - 1.99*pow(10,-6)*pow(x1,2)*pow(y1,2);   /*In the equation we just calculating the relh value*/
return hein;                                                          /*and returning heatindex values*/
}


void heatindex(float temph,float templ,float tempi,float rhuml,float rhumh,float rhumi) //function to print the heatindextable//
{
float i=0,j=0;
int s= ((rhumh-rhuml)/(rhumi)), r=((9*(s+2))-2);
cout<<endl;
cout<<"Heat Index Table"<<endl;
cout<<endl;
cout<<"Relative Humidity"<<endl<<setw(8)<<"(%)";
for(j=rhuml;j<=rhumh;j+=rhumi)                 /* For loop which take temph and templ as wee as the increment value*/
{                                                       /*and print temperature values with setprecision 3*/
cout<<setw(8)<<setprecision(2)<<fixed<<j<<" ";
}
cout<<endl;
for(j=0; j<=r;j++)                            /* for loop for printning the underlines for air temperature values*/
{
cout<<"-";
}
cout<<endl;
cout<<"Temp"<<endl<<setw(2)<<"(deg. F)"<<endl;
for(i=templ;i<=temph;i+=tempi)           /*for loop takes rhum values and increment value and print them*/
{
cout<<setw(7)<<setprecision(2)<<fixed<<i<<"|";
for(j=rhuml;j<=rhumh;j+=rhumi)               /* This loop contain the important logic to print the result takes from hein function*/
{                                                     /* and print the result with the same width and precision.*/
float result=heincal(i,j);
cout<<setw(9)<<setprecision(2)<<fixed<<result;
}
cout<<endl;
}                                                     /*end of program*/
}
