#include <iostream>
#include <windows.h>
using namespace std;

string checkPointPosition(float height, int x_co, int y_co);

main() {
    float height, x_co, y_co;
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter x coordinate: ";
    cin >> x_co;
    cout << "Enter y coordinate: ";
    cin >> y_co;
    string get = checkPointPosition(height, x_co, y_co);
    cout << get;
}

string checkPointPosition(int height, int x_co, int y_co)
{
    bool onBorder = (x_co >= 0 && x_co <= 3 * height && (y_co == 0 || y_co == height)) || (y_co >= 0 && y_co <= 4 * height && (x_co == 0 || x_co == 2 * height)) || (x_co == height && y_co >= height && y_co <= 3 * height);

    if (onBorder)
    {
        return "Border";
    }
        else if (x_co > 0 && x < 2 * height && y_co > 0 && y_co < 4 * height) 
    {
        return "Inside";
    } 
        else 
    {
        return "Outside";
    }
}
