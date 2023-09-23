#include <iostream>
using namespace std;
main() {
	float vp,fp;
	int tkv,tkf;
	cout << "Enter vegetable price per kilogram (in coins): ";
	cin >> vp;
	cout << "Enter fruit price per kilogram (in coins): ";
	cin >> fp;
	cout << "Enter total kilograms of vegetables: ";
	cin >> tkv;
	cout << "Enter total kilograms of fruits: ";
	cin >>tkf;
	float rps;
	rps= (tkv*vp)+(tkf*fp);
	rps=rps/1.94;
	cout << "Total earnings in Rupees (Rps): " << rps ;
	}