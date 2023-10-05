#include <iostream>
using namespace std;
void score();
main ()
{
	score ();	
}
void score()
{
	cout <<"Enter your score: ";
	int score;
	cin >> score;
	if (score > 50)
{
	cout << "Pass";
}
	if (score <=50)
{
	cout << "Fail";
}
}