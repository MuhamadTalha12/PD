#include <iostream>
#include <windows.h>
using namespace std;

int calculateVolleyballGames(string yeartype, int holidays, int hometownWeekends);

main()
{
    string yeartype;
    int holidays, hometownWeekends;
    int get;
    cout << "Enter year type: ";
    cin >> yeartype;

    cout << "Enter number of holidays: ";
    cin >> holidays;

    cout << "Enter number of weekends: ";
    cin >> hometownWeekends;

    get = calculateVolleyballGames(yeartype, holidays, hometownWeekends);
    cout << get;
}

int calculateVolleyballGames(string yeartype, int holidays, int hometownWeekends)
{
    int total;
    int n;

    if (yeartype == "leap")
    {
        holidays = holidays * 0.67;
        hometownWeekends = hometownWeekends * 0.75;
        total = holidays + hometownWeekends;
        n = 48 - (48 * 0.15);
        n = n + total + 1;
    }

    else
    {
        holidays = holidays * 0.67;
        hometownWeekends = hometownWeekends * 0.75;
        total = holidays + hometownWeekends;
        n = 48 - (48 * 0.15);
        n = n + total;
        n = n - (n * 0.15);
        if (n >= 44)
            n = n + 2;       
        n = n + 1;    
    }
    return n;
}