#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
float taxcalc(char type, float price);
main ()
{
	float price,tax;
	char type;
	cout <<"Enter the vehicle type code (M, E, S, V, T): ";
	cin >> type;
	cout <<"Enter the price of the vehicle: $" ;
	cin >> price;
	tax = taxcalc(type,price);
	cout <<"The final price of the vehicle of type " << type << " after adding the tax is $" << tax;
}
float taxcalc(char type, float price)
{
	float taxamount,finalprice;
	if(type=='M')
	{
		taxamount=price + (price*0.06);
	}
	if (type=='E')
	{
		taxamount=price + (price*0.08);
	}
	if (type=='S')
	{
		taxamount=price + (price*0.1);
		
	}
	if (type=='V')
	{
		taxamount=price + (price*0.12);
	}
	if (type=='T')
	{
		taxamount=price + (price*0.15);
	}
	return taxamount;
}