#include <iostream>
using namespace std;
void number(int n1);
main ()
{
	cout <<"Enter a number: ";
	int n1;
	cin >>n1;
	number (n1);
}
void number(int n1)
{
	if (n1%2==0)
	{
		cout <<"Number " << n1 << " is even";
	}
	if (n1%2!=0)
	{
		cout <<"Number " << n1 << " is odd";
	}
}