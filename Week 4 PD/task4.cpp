#include <iostream>
using namespace std;
void Speed(int sp);

main()
{	int sp;
	cout << "Speed: ";
	cin >> sp;
	Speed(sp);
}

void Speed(int sp)
{
	if (sp > 100 )
	{	cout << "Halt... YOU WILL BE CHALLENGED!!!";	}
	if (sp <= 100)
	{	cout << "Perfect! You're going good.";		}
}