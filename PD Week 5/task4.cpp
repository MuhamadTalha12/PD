#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
string projecttime(float hrsneed,float dayswehave,float numberofworkers);

main ()
{
	float hrsneed,dayswehave,numberofworkers;
	string res;
	cout <<"Enter the needed hours: ";
	cin >> hrsneed;
	cout <<"Enter the days that the firm has: ";
	cin >> dayswehave;
	cout << "Enter the number of all workers: ";
	cin >> numberofworkers; 
	res= projecttime(hrsneed,dayswehave,numberofworkers);
	cout << res;

}
string projecttime(float hrsneed,float dayswehave,float numberofworkers)
{
	float trainingdays,workingdays,hrs,overtime,totalhrs,difference,totaltime;
	string output;
	trainingdays= dayswehave*(0.1);
	workingdays=dayswehave-trainingdays;
	hrs=workingdays*8*numberofworkers;
	overtime=workingdays*numberofworkers*2;
	totalhrs=hrs+overtime;
	if (totalhrs>hrsneed)
	{
		difference=totalhrs-hrsneed;
		output="Yes!"+to_string(int (difference))+" hours left.";
	}
	if (totalhrs<=hrsneed)
	{
		difference=hrsneed-totalhrs;
		output="Not enough time!" + to_string(int (difference))+" hours needed.";
	}
		return output;
}	