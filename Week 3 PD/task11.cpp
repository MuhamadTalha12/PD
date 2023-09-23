#include <iostream>
using namespace std;
main() {
 	int age,mov,avg,total;
	cout << "Enter the person's age: ";
	cin >> age;
	cout << "Enter the number of times they've moved: ";
	cin >> mov;
	total=mov+1;
	avg=age/total;
	cout <<"Average number of years lived in the same house: "<< avg;
	}