#include <iostream>
using namespace std;
void tpchecker(int people,int roll);

main()
{	int people,roll;
	cout << "Number of people in the household: ";
	cin >> people;
	cout << "Number of rolls of TP: ";
	cin >> roll;
	tpchecker(people,roll);
}

void tpchecker(int people,int roll)
{	int days,difference;
	int tp,lasts;
	tp = people*(57 * 14);
	days = (roll*500);
	lasts = days/(people*57);
	difference = days - tp;
	if (difference >= 0)
	{	cout << "Your TP will last " << lasts << " days, no need to panic!";	} 
	if (difference < 0)
	{	cout << "Your TP will only last " << lasts << " days, buy more!";	} 



}