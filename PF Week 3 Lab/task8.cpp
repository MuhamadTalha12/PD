#include <iostream>
using namespace std;
main ()
{
	float v,i,p;
	cout << "Enter voltage (in volts): ";
	cin >> v;
	cout << "Enter current (in amperes): ";
	cin >> i;
	p = v*i;
	cout << "The power is " << p << " watts.";
}	