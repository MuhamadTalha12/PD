#include <iostream>
#include <windows.h>
using namespace std;
float calculateAverage (float marksEnglish, float marksMath, float marksChemistry, float marksSocialScience, float marksBiology);
string calculateGrade (float average);
main ()
{
    float marksEnglish,marksMath,marksChemistry,marksSocialScience,marksBiology;
    float average,percentage;
    string name,grade,getstr;
    cout <<"Enter student name: ";
    cin >> name;
    cout<< "Enter marks for English: ";
    cin >> marksEnglish;
    cout<<"Enter marks for Maths: ";
    cin >> marksMath;
    cout<<"Enter marks for Chemistry: ";
    cin >> marksChemistry;
    cout<<"Enter marks for Social Science: ";
    cin>>marksSocialScience;
    cout<<"Enter marks for Biology: ";
    cin>>marksBiology;
    average=calculateAverage ( marksEnglish, marksMath, marksChemistry, marksSocialScience, marksBiology);
    getstr=calculateGrade (average);
    cout<<"Student Name: "<<name<<endl;;
    cout<<"Percentage: "<<average<<"%"<<endl;
    cout<<"Grade: " <<getstr<<endl;


}
float calculateAverage (float marksEnglish, float marksMath, float marksChemistry, float marksSocialScience, float marksBiology)
{
    float avg;
    avg = (marksEnglish + marksMath + marksChemistry + marksSocialScience + marksBiology) / 5;
    return avg;
}
string calculateGrade (float average)
{
    float percentage;
    percentage=average;
    if (percentage>=90)
    {
        return "A+";
    }
    if (percentage>=80 && percentage<90)
    {
        return "A";
    }
    if (percentage>=70 && percentage<80)
    {
        return "B+";
    }
    if (percentage>=60 && percentage<70)
    {
        return "B";
    }
    if (percentage>=50 && percentage<60)
    {
        return "C";
    }
    if (percentage>=40 && percentage<50)
    {
        return "D";
    }
    if (percentage<40)
    {
        return "F";
    }
}