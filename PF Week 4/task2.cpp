#include <iostream>
using namespace std;
void feet ( )
{
	cout <<"Enter the measurement in inches: ";
	float inch,feet;
	cin >> inch;
	feet = inch / 12;
	cout <<"Equivalent in feet: " << feet ;
}
	main ()
{
	feet ();
}