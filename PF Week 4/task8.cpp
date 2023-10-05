#include <iostream>
using namespace std;
void discount(string day,float amount);
main ()
{
	cout<< "Enter the day of purchase: ";
	string day;
	cin >> day;
	cout <<"Enter the total purchase amount: $";
	float amount;
	cin >> amount;
	discount (day,amount);
}
 void discount(string day,float amount)
{
	if (day=="Sunday")
{
	amount= amount - (amount * 10/100);
	cout <<"Payable Amount: $" << amount;
}
	if (day !="Sunday")
{
	cout << "Payable Amount: $" << amount;
}
}