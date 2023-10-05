#include <iostream>
using namespace std;
void rubikcube();
main ()
{
	rubikcube();
}
void rubikcube()
{
	cout <<"Enter the side length of the Rubik's Cube: ";
	int sides,faces;
	cin >> sides;
	faces=sides*sides*6;
	cout <<"Number of stickers needed: " << faces;
}