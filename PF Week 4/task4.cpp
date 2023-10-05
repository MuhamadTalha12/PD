#include <iostream>
using namespace std;
void add (float n1,float n2);
void sub (float n1,float n2);
void mul  (float n1,float n2);
void div (float n1,float n2);
main ()
{
	cout <<"Enter 1st number: ";
	float n1,n2;
	cin >> n1;
	cout <<"Enter 2nd number: ";
	cin >> n2;
	cout <<"Enter an operator (+, -, *, /): ";
	char op;
	cin >> op;
	if ( op == '+')
	{
	add(n1,n2);
	}
	if ( op == '-')
	{
	sub (n1,n2);
	}
	if ( op == '*')
	{
	mul (n1,n2);
	}
	if ( op == '/')
	{
	div (n1,n2);
	}
}
void mul(float n1 , float n2)
{
	cout << "Multiplication: " << n1*n2 ;
}
void sub (float n1, float n2)
{
	cout << "Subtraction: " << n1-n2;	
}
void add (float n1,float n2)
{
	cout <<"Addition : " <<n1+n2;
}
void div (float n1,float n2)
{
	cout <<"Division: " << n1/n2;
}