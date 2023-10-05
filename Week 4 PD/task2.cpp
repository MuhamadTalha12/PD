#include <iostream>
using namespace std;
void reverse(string n);

main()
{	string n;
	cout << "Enter 'true' or 'false': ";
	cin >> n;
	reverse(n);
}

void reverse(string n)
{
	if (n == "true")
	{	cout << "false";	}
	if (n == "false")
	{	cout << "true";		}
}