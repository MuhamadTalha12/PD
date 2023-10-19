#include <iostream>
#include <windows.h>
using namespace std;
string calculateHotelPrice(string month, int numberOfStays);


main ()
{
    string month,get;
    int numberOfStays;
    cout<<"Enter the month (May, June, July, August, September, October): ";
    cin>>month;
    cout<<"Enter the number of stays: ";
    cin >> numberOfStays;
    get = calculateHotelPrice(month, numberOfStays);
    cout<<get;


}
string calculateHotelPrice(string month, int numberOfStays)
{
float studio;
float appartment;
float price;
if(month=="May" || month=="October")
{
    price=50;
    studio=price;
    appartment=65;
    if(numberOfStays>7)
    {
    studio=price-price*0.05;
    }
}
if(numberOfStays>14)
{
    studio=price-price*0.3;
    appartment=appartment-(appartment*0.1);

}
    studio=studio*numberOfStays;
    appartment=appartment*numberOfStays;
if(month=="June" || month=="September")
{
    price=75.20;
    studio=price;
    appartment=68.70;
    if(numberOfStays>14)
    {
    studio=price-(price*0.2);
    appartment=appartment-(appartment*0.1);
    }


    studio=studio*numberOfStays;
    appartment=appartment*numberOfStays;

}


if(month=="July" || month=="August")
{
    price=76;
    studio=price;
    appartment=77;
    if(numberOfStays>14)
    {
    appartment=appartment-(appartment*0.1);
    }


    studio=studio*numberOfStays;
    appartment=appartment*numberOfStays;

}

    return "Apartment: " +to_string(appartment)+"$.\nStudio: "+to_string(studio)+"$.";


}