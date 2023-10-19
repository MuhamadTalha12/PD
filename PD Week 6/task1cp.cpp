#include <iostream>
#include <windows.h>
using namespace std;
string decideActivity (string temperature,string humidity);
main ()
{
    string temperature,humidity,get;
    cout<<"Enter temperature (warm or cold): ";
    cin >> temperature;
    cout<<"Enter humidity (dry or humid): ";
    cin >> humidity;
    get = decideActivity (temperature,humidity);
    cout <<"Recommended activity: " << get;
}
string decideActivity (string temperature,string humidity)
{
    if (temperature=="warm")
    {
        if(humidity=="dry"){
        return "Play tennis";}
        if(humidity=="humid"){
        return "Swim";}
    }
     if (temperature=="cold")
    {
        if(humidity=="dry"){
        return "Play basketball";}
        if(humidity=="humid"){
        return "Watch TV";}
    }
}
    