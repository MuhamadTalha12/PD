#include <iostream>
using namespace std;
void required (int distance,int fuel);
main ()
{
	cout <<"Enter the distance: ";
	int distance ;
	cin >> distance;
	int fuel;
	fuel=10*distance;
	required (distance , fuel);
}
void required (int distance,int fuel)
{
	
	if (fuel>=100)
	{
		cout << "Fuel needed: " << fuel;
	}
	if (fuel<100)
	{
		cout <<"Fuel needed: " << "100";
	}
}