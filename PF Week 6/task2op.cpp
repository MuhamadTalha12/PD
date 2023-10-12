#include <iostream>
#include <windows.h>
using namespace std;
int greaterNumber(int n1,int n2);
main ()
{
    int n1,n2,get;
    cout <<"Enter the first number: ";
    cin >> n1;
    cout <<"Enter the second number: ";
    cin >> n2;
    get = greaterNumber(n1,n2);
    cout << get;
}
int greaterNumber(int n1, int n2)
{
    if(n1>n2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}