#include <iostream>
#include <windows.h>
using namespace std;
float calculateFruitPrice (string fruit, string dayOfWeek, double quantity);


main ()
{
    string fruit,dayOfWeek;
    double quantity,get;
    cout<<"Enter the fruit name: ";
    cin >> fruit;

    cout <<"Enter the day of the week (e.g., Monday, Sunday): ";
    cin >> dayOfWeek;
    
    cout<<"Enter the quantity: ";
    cin >>  quantity;

    get=calculateFruitPrice (fruit, dayOfWeek, quantity);
     if (fruit =="banana" || fruit =="kiwi" || fruit =="grapefruit" || fruit =="grapes" || fruit =="apple" || fruit =="orange" || fruit =="pineapple" )
    {
        cout<<get;
    }
        
    if (fruit !="banana" && fruit !="kiwi" && fruit !="grapefruit" && fruit != "grapes" && fruit !="apple" && fruit !="orange" && fruit !="pineapple" )
    {
        cout<<"error";
    }
}
float calculateFruitPrice (string fruit, string dayOfWeek, double quantity)
{
    float price;
    if (dayOfWeek=="Monday" || dayOfWeek=="Tuesday" || dayOfWeek=="Wednesday" || dayOfWeek=="Thursday" || dayOfWeek=="Friday")
    {
        if(fruit=="banana")
        {
            price=quantity*2.50;
            return price;
        }
        if(fruit=="apple")
        {
            price=quantity*1.20;
            return price;
        }
        if(fruit=="orange")
        {
            price=quantity*0.85;
            return price;
        }
        if(fruit=="grapefruit")
        {
            price=quantity*1.45;
            return price;
        }
        if(fruit=="kiwi")
        {
            price=quantity*2.70;
            return price;
        }
        if(fruit=="pineapple")
        {
            price=quantity*5.50;
            return price;
        }
        if(fruit=="grapes")
        {
            price=quantity*3.85;
            return price;
        }
    }
    if (dayOfWeek=="Saturday" || dayOfWeek=="Sunday")
    {
         if(fruit=="banana")
        {
            price=quantity*2.70;
            return price;
        }
        if(fruit=="apple")
        {
            price=quantity*1.25;
            return price;
        }
        if(fruit=="orange")
        {
            price=quantity*0.90;
            return price;
        }
        if(fruit=="grapefruit")
        {
            price=quantity*1.60;
            return price;
        }
        if(fruit=="kiwi")
        {
            price=quantity*3.00;
            return price;
        }
        if(fruit=="pineapple")
        {
            price=quantity*5.60;
            return price;
        }
        if(fruit=="grapes")
        {
            price=quantity*4.20;
            return price;
        }
    }
}