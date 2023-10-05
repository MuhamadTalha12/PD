#include <iostream>
using namespace std;
void FShop(int RRose,int WRose,int tulip);

main()
{	int RRose;
	int WRose;
	int tulip;
	cout << "Red Rose: ";
	cin >> RRose;
	cout << "White Rose: ";
	cin >> WRose ;
	cout << "Tulips: ";
	cin >> tulip;
	FShop(RRose,WRose,tulip);
}

void FShop(int RRose,int WRose,int tulip)
{
	float total;
	float discount;
	total = (2*RRose)+(4.10*WRose)+(2.50*tulip);
	if (total > 200)
	{	discount = total - (total*20/100);	
	cout << "Original Price: $" << total << endl;
	cout << "Price after Discount: $" << discount << endl;}
	if (total <= 200)
	{
	cout << "Original Price: $" << total << endl;
	cout << "No discount applied.";}
}