#include <iostream>
using namespace std;
main ()
{
	string name;
	int m,i,ecat;
	float aggregate;
	cout << "Enter the student's name: " ;
	cin >> name;
	cout << "Enter matriculation marks (out of 1100): " ;
	cin >> m ;
	cout << "Enter intermediate marks (out of 550): "  ;
	cin >> i ;
	cout << "Enter Ecat marks (out of 400): " ;
	cin >> ecat;
	aggregate = (ecat* 0.5)/400 + (m* 0.1)/1100 + (i* 0.4)/550;
	aggregate = aggregate * 100 ;
	cout << "Aggregate score for " << name << " in UET is: " << aggregate <<"%";
} 