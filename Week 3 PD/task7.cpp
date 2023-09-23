#include <iostream>
using namespace std;
main() {
	string n;
	int atp,ctp,sat,sct,per;
	int total,donation,remain;
	cout << "Enter the movie name: ";
	cin >> n;
	cout << "Enter the adult ticket price: $";
	cin >> atp ;
	cout << "Enter the child ticket price: $";
	cin >> ctp;
	cout << "Enter the number of adult tickets sold: ";
	cin >> sat;
	cout << "Enter the number of child tickets sold: ";
	cin >> sct;
	cout << "Enter the percentage of the amount to be donated to charity: ";
	cin >> per;
	total= atp*sat + ctp*sct;
	donation=(total/per);
	remain=total - donation;
	cout << endl;
	cout <<"Movie: " << n <<endl;
	cout << "Total amount generated from ticket sales: $" << total <<endl ;
	cout << "Donation to charity (" << per <<"%): $" << donation <<endl;
	cout << "Remaining amount after donation: $" << remain;
	}