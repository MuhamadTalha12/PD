#include <iostream>
using namespace std;
main() {
	int q,w,e,r,t,y,u,i,sum;
	cout << "Enter a 4-digit number: ";
	cin >> q;
	w=q%10;
	e=q/10;
	r=e%10;
	t=e/10;
	y=t%10;
	u=t/10;
	i=u%10;
	sum = w+r+y+i;
	cout << "Sum of the individual digits: "<<sum;
	}