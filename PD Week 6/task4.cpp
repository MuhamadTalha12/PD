#include <iostream>
#include <windows.h>
using namespace std;
float servicedue(char type,char calltime,int mins);
string servicetype(char type);

main ()
{
    char type,calltime;
    int mins;
    float get;
    string getstr;
    cout<<"Enter the service code (R/r for regular, P/p for premium): ";
    cin >> type;
    if (type=='P' || type=='p')
    {
    cout<<"Enter time of the call (D/d for day, N/n for night): ";
    cin >> calltime;
    }
    cout<<"Enter the number of minutes used: ";
    cin >> mins;
    get=servicedue(type,calltime,mins);
    getstr= servicetype(type);
    cout<<"Service Type: "<< getstr <<endl;
    cout<<"Total Minutes Used: "<<mins <<" minutes" <<endl;
    cout<<"Amount Due: $" << get;

}
float servicedue(char type,char calltime,int mins)
{
    float due;
    if (type=='r' || type=='R')
    {
        if (mins>50)
        {
            mins=mins-50;
            due=10 + (0.20*mins);
            return due;
        }
        if (mins<50)
        {
            return 10;
        }
    }
        if ((type=='p' || type=='P') && (calltime=='N' || calltime=='n'))
    {
        if (mins>100)
        {
            mins=mins-100;
            due=25 + (0.05*mins);
            return due;
        }
        if (mins<100)
        {
        return 25;
        }
    }
         if ((type=='p' || type=='P') && ( calltime=='d' || calltime=='D'))
    {
        if (mins>75)
        {
            mins=mins-75;
            due=25 + (0.10*mins);
            return due;
        }
        if(mins<75)
        {
            return 25;
        }
    }
}
    string servicetype(char type)
 {   {
        if (type =='P' || type =='p')
        return "Premium";
        if (type=='r' || type == 'R')
        return "Regular";
    }
}