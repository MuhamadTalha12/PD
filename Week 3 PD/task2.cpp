#include <iostream>
using namespace std;
main() {
	float nom,fps,total;
	cout << "Number of Minutes: ";
	cin >> nom;
	cout << "Frames per Second: ";
	cin >> fps;
	total= nom*fps*60;
	cout << "Total Number of Frames: " << total ;
	}