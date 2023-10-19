#include <iostream>
#include <windows.h>
using namespace std;
string checkStudentStatus(int examHour, int examMinute, int studentHour, int studentMinute);
main()
{
    int examHour, examMinute, studentHour, studentMinute;
    cout << "Enter Exam Starting Time (hour): ";
    cin >> examHour;
    cout << "Enter Exam Starting Time (minutes): ";
    cin >> examMinute;
    cout << "Enter Student hour of arrival: ";
    cin >> studentHour;
    cout << "Enter Student minutes of arrival: ";
    cin >> studentMinute;
    string get = checkStudentStatus(examHour, examMinute, studentHour, studentMinute);
    cout << get;
}
string checkStudentStatus(int examHour, int examMinute, int studentHour, int studentMinute)
{
    int examtime, arrivetime;
    string out;
    examtime = (examHour * 60) + examMinute;
    arrivetime = (studentHour * 60) + studentMinute;
    if (arrivetime == examtime || (examtime - arrivetime) <= 30)
    {
        out = "On time";

        if ((examtime - arrivetime) <= 30 && (examtime - arrivetime) != 0)
        {
            out = "On time\n" + to_string(examtime - arrivetime) + " minutes before the start";
        }
    }
     if (arrivetime < examtime)
    {
        if (examtime - arrivetime < 60 && (examtime - arrivetime) > 30)
            out = "Early\n" + to_string(examtime - arrivetime) + " minutes before the start";
        if (examtime - arrivetime >= 60)
        {
            int hrs, min;
            int timeremain = examtime - arrivetime;
            int hours = timeremain / 60;
            hrs = hours % 10;
            if (hours == 1)
            {
                min = 0;
            }
            else
            {
            if (timeremain > 60)
            {
                    min = timeremain - (60 * hrs);
            }
            }
            out = "Early\n" + to_string(hrs) + ":" + to_string(min) + " hours before the start";
        }
    }
    if (arrivetime > examtime)
    {
        if (arrivetime - examtime < 60)
        {
            int timeremains = arrivetime - examtime;
            out = "Late\n" + to_string(timeremains) + " minutes after the start";
        }
        if (arrivetime - examtime >= 60)
        {
            int hrs, min;
            int timeremain = arrivetime - examtime;
            int hours = timeremain / 60;
            hrs = hours % 10;
            if (hours == 1)
            {
                min = 0;
            }
            if (timeremain > 60)
            {
                    min = timeremain - (60 * hrs);
            }
            out = "Late\n" + to_string(hours) + ":" + to_string(min) + " hours after the start";
        }
    }
    return out;
}