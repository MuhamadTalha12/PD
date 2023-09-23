#include <iostream>
using namespace std;
main ()
{
	float mb,b;
	cout << "Enter the size in megabytes (MB): ";
	cin >> mb;
	b=mb*1024;
	b=b*1024*8;
	cout << mb << " MB is equivalent to " << b << " bits.";
}