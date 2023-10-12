#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
string vol (float l,float w,float h,string unit);
main ()
{
	float l,w,h;
	string unit,volume;
	cout << "Enter the length of the pyramid (in meters): ";
	cin >> l;
	cout<<"Enter the width of the pyramid (in meters): ";
	cin >> w;
	cout<< "Enter the height of the pyramid (in meters): ";
	cin >> h;
	cout << "Enter the desired output unit (millimeters, centimeters, meters, kilometers): ";
	cin >> unit;
	volume=vol(l,w,h,unit);
	cout << "The volume of the pyramid is: "<< volume ;
}
string vol (float l,float w,float h,string unit)
{
		float vol=l*w*h/3;
		string result;
		if (unit=="meters")
		{
			result=to_string(vol) + " cubic meters";
		}
		if (unit=="centimeters")
		{
			vol=vol*100*100*100;
			result=to_string(vol) + " cubic centimeters";
			
		}
		if(unit=="millimeters")
		{
			vol=vol*1000*1000*1000;
			result=to_string(vol) + " cubic millimeters";
		}
		if (unit=="kilometers")
		{
			vol=vol/(1000*1000*1000);
			result=to_string(vol) + " cubic kilometers";
		}
			return result;
}