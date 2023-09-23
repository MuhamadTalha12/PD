#include <iostream>
using namespace std;
main() {
	float i,p,c,per;
	cout << "Enter Imposter Count: ";
	cin >> i;
	cout << "Enter Player Count: ";
	cin >> p;
	c=(i/p)*100;
	per=c;
	cout << "Chance of being an imposter: " << per << "%";
	}