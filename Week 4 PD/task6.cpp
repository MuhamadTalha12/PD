#include <iostream>
using namespace std;
void longesttime(int min,int hour,int minhours);

main()
{
	int min,hour,minhours;
	cout << "Enter the number of hours: ";
	cin >> hour;
	cout << "Enter the number of minutes: ";
	cin >> min;
	longesttime(min,hour,minhours);
}

void longesttime(int min,int hour,int minhours)
{
	minhours = hour * 60;
	if (minhours < min)
	{	cout << min;	}
	if (minhours > min)
	{	cout << hour;	} 
}