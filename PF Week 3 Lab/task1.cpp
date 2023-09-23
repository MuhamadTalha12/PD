# include <iostream>
using namespace std;
main ()
{
	string name;
	int roll_no;
	float aggregate;
	char section;
	cout << "Enter your name: " ;
	cin >> name;
	cout << "Enter your roll number: " ;
	cin >> roll_no;
	cout << "Enter your aggregate: " ;
	cin >> aggregate;
	cout << "Enter your section: " ;
	cin >> section;
	cout << "Student Information:" << endl ;
	cout << "Name: " << name <<endl ;
	cout << "Roll Number: " << roll_no <<endl;
	cout << "Aggregate: " << aggregate <<endl;
	cout << "Section: " << section << endl;
}