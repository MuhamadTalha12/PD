#include <iostream>
using namespace std;
main ()
{
	int days,years;
	cout <<"Enter your age in years: ";
	cin >> years;
	days=365*years;
	cout << "Your age in days is approximately " << days << " days.";
}