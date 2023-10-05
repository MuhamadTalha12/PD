#include <iostream>
using namespace std;
void fuel ();
main () {
	fuel ();
}
void fuel ()
{ 
	cout << "Enter the distance: ";
	float distance,fuel;
	cin >> distance;
	fuel = 10 * distance;
	cout << "Fuel needed: " << fuel ;
}