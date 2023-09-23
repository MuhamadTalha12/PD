#include <iostream>
using namespace std;
main ()
{
	int c,m,d;
	cout << "Enter the current world population: ";
	cin >> c;
	cout << "Enter the monthly birth rate (number of births per month): ";
	cin >> m;
	d=30*12*m+c;
	cout << "The population in three decades will be: " << d ;
}