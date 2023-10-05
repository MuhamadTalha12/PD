#include <iostream>
using namespace std;
void bonus(int p,int fp,int diff);

main()
{
	int p;
	int fp;
	int diff;
	cout << "Enter your position: ";
	cin >> p;
	cout << "Enter your friend's position: ";
	cin >> fp;
	bonus(p,fp,diff);
}

void bonus(int p,int fp,int diff)
{
	diff = fp - p;
	if (diff <= 6)
	{	cout << "true";	}
	if (diff > 6)
	{	cout << "false";	}
}