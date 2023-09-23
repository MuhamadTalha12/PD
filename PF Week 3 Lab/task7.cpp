#include <iostream>
using namespace std;
main ()
{
	int hour,second;
	cout << "Enter the number of hours: " ;
	cin >> hour;
	second = hour *60*60 ;
	cout << hour << " hours is equivalent to " << second << " seconds.";
}