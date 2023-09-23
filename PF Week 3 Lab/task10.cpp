#include <iostream>
using namespace std;
main ()
{
	string team;
	int w,d,l,p,t;
	cout << "Enter the name of the cricket team: ";
	cin >> team;
	cout << "Enter the number of wins: ";
	cin >> w;
	w=w*3;
	cout << "Enter the number of draws: ";
	cin >> d;
	d=d*1;
	cout << "Enter the number of losses: ";
	cin >> l;
	l=l*0;
	t=w+d+l;
	cout << team << " has obtained " << t << " points in the Asia Cup tournament.";
}