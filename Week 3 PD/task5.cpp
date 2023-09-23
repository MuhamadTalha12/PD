#include <iostream>
using namespace std;
main() {
	string n;
	float weightloss,days;
	cout << "Enter the Name of the Person: ";
	cin >> n;
	cout << "Enter the target weight loss in kilograms: ";
	cin >> weightloss ;
	days=weightloss * 15;
	cout << n << " will need " << days <<" days to lose " << weightloss << " kg of weight by following the doctor's suggestions" ;
	}