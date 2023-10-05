#include <iostream>
using namespace std;
void isequal(int x,int y);

main()
{	int x;
	int y;
	cout << "Enter the first number: " ;
	cin >> x;
	cout << "Enter the second number: " ;
	cin >> y;
	isequal(x,y);
}

void isequal(int x,int y)
{
	
	if (x == y)
	{	cout << "true";	}
	if (x != y)
	{	cout << "false";}
}