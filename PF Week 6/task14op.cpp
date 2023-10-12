#include <iostream>
using namespace std;
string calculateCost(float budget,string category,int numPeople);
main()
{
    int numPeople;
    string category;
    float budget;
    string get;
    cout << "Enter the budget: ";
    cin >> budget;
    cout << "Enter the category (VIP/Normal): ";
    cin >> category;
    cout << "Enter the number of people in the group: ";
    cin >> numPeople;
    get = calculateCost(budget,category, numPeople);
    cout << get ;
}

string calculateCost(float budget,string category,int numPeople)
{
    float remBudget;
    float transportExpense;
    float ticketPrice;
    float difference;
    string result;
    if (numPeople >= 1 && numPeople <= 4)
    {
        transportExpense = budget * 75 / 100;
    }
    if (numPeople >= 5  && numPeople <= 9)
    {
        transportExpense = budget * 60 / 100;
    }
    if (numPeople >= 10 && numPeople <= 24)
    {
        transportExpense = budget * 50 / 100;
    }
    if (numPeople >= 25 && numPeople <= 49)
    {
        transportExpense = budget * 40 / 100;
    }
    if (numPeople >= 50)
    {
        transportExpense = budget * 25 / 100;
    }

    remBudget = budget - transportExpense;
    if (category == "VIP")
    {
        ticketPrice = 499.99 * numPeople;
    }
    if (category == "Normal")    
    {
        ticketPrice = 249.99 * numPeople;
    }

    difference = (remBudget - ticketPrice) + 0.000005;
    if (difference > 0.0 )
    {
        result = "Yes! You have " + to_string(difference) + " leva left." ;
    }
    else{
        result = "Not enough money! You need " + to_string(-difference) + " leva.";
    }
    return result;
}