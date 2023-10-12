#include <iostream>
#include <windows.h>
using namespace std;
int parityAnalysis(int n1);
main ()
{
    int n1,get;
    cout <<"Enter a 3-digit number: ";
    cin >> n1;
    get= parityAnalysis(n1);
    cout<<get;
}
int parityAnalysis(int n1)
{
    int num1,num2,num3,sum;
    num1= n1 % 10;
    n1 = n1 / 10;
    num2= n1 % 10;
    n1= n1/ 10;
    num3= n1 % 10;
    sum=num1+num2+num3;
    if (n1%2 == sum%2)
    {
       return true;
    }
    else
    {
        return false;
    }
}