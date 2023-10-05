#include <iostream>
using namespace std;
void finalprice(string x, float price,float discount);

main()
{	string x;
	float price;
	float discount;
	cout << "Enter the country's name: ";
	cin >> x;
	cout << "Enter the ticket price in dollars: $";
	cin >> price;
	finalprice(x,price,discount);
	
	
}

void finalprice(string x, float price,float discount)
{
	if (x == "Pakistan")
	{	 discount = price-(price*5/100);	}
	if (x == "Ireland")
	{	 discount = price-(price*10/100);	}
	if (x == "India")
	{	 discount = price-(price*20/100);	}
	if (x == "England")
	{	 discount = price-(price*30/100);	}
	if (x == "Canada")
	{	 discount = price-(price*45/100);	}
	cout << "Final ticket price after discount: $" << discount;
}