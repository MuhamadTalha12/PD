#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy (int x,int y);
void printmaze();
void printenemy1();
void printenemy2();
void printenemy3();
void eraseenemy1();
void eraseenemy2();
void eraseenemy3();
void printplayer();
void eraseplayer();
void moveenemy1();
void moveenemy2();
void moveenemy3();
void moveplayerleft();
void moveplayerright();
void moveplayerup();
void moveplayerdown();
char getCharAtxy(short int x, short int y);
bool movehorizontal = false;
bool movevertical = false;
bool movediagnol = false;
int x,y,x1=48,x2=2,x3=98,Y1=6,Y2=20,Y3=27,m=4,n=4;
main ()
{
    system("cls");
    printmaze();
    printenemy1();
    printenemy2();
    printenemy3();
    printplayer(); 
    while(true)
	{ if(GetAsyncKeyState(VK_LEFT))
    {
         moveplayerleft();
    }
    if(GetAsyncKeyState(VK_RIGHT))
    { 
        moveplayerright();
    }
    if(GetAsyncKeyState(VK_UP))
    { 
        moveplayerup();
    }
    if(GetAsyncKeyState(VK_DOWN))
    { 
        moveplayerdown();
    }
    moveenemy1();
    moveenemy2();    
    moveenemy3();
    Sleep(150);
    }
}


void printmaze() 

{
 
 
     cout<<"----------------------------------------------------------------------------------------------------------------------------------"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|==========================================|                                                                                     |"<<endl;
     cout<<"|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|                                                                                     |"<<endl;
     cout<<"|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|                                                                                     |"<<endl;
     cout<<"|==========================================|                                                                                     |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                             |===============|                                                                  |"<<endl;
     cout<<"|                                             |%%%%%%%%%%%%%%%|                                                                  |"<<endl;
     cout<<"|                                             |===============|                                                                  |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                               |================================================================|"<<endl;
     cout<<"|                                                               |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|"<<endl;
     cout<<"|                                                               |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|"<<endl;
     cout<<"|                                                               |================================================================|"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                            |================|                                                                  |"<<endl;
     cout<<"|                                            |%%%%%%%%%%%%%%%%|                                                                  |"<<endl;
     cout<<"|                                            |================|                                                                  |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                                |"<<endl;
     cout<<"|                                                                                                                |============|  |"<<endl;
     cout<<"|                                                                                                                |    YOU     |  |"<<endl;
     cout<<"|=========================================|                                                                      |    WIN     |  |"<<endl;
     cout<<"|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|                                                                      |============|  |"<<endl;
     cout<<"|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|                                                                                   |  |"<<endl;
     cout<<"|=========================================|                                                                                   |  |"<<endl;
     cout<<"                                                                                                                                 |"<<endl;
     cout<<"----------------------------------------------------------------------------------------------------------------------------------"<<endl;

}

void printenemy1()
{
    gotoxy (x1,Y1);
    cout <<" ^^^^^^^^^^^ ";
    gotoxy (x1,Y1+1);
    cout <<"|===========|";
    gotoxy (x1,Y1+2);
    cout <<" vvvvvvvvvvv ";    
}
void eraseenemy1()
{
    gotoxy (x1,Y1);
    cout<<"                 ";
    gotoxy (x1,Y1+2);
    cout<<"                 ";
    gotoxy (x1,Y1+2);
    cout<<"                 ";
}
void moveenemy1()
  {
    eraseenemy1();
    if(!movevertical)
    {
        Y1=Y1+1;
    if (Y1>=12)
        movevertical = true;
    }
    if (movevertical)
     {
        Y1 = Y1 -1;
        if(Y1 < 2)
        movevertical =false;
     }
    
    printenemy1();
}
void printenemy2()
{
    gotoxy (x2,Y2);
    cout <<"<<=||=>>";
    gotoxy (x2,Y2-1);
    cout<<"<<=||=>>";
    gotoxy (x2,Y2-2);
    cout<<"<<=||=>>";    
}
void eraseenemy2()
{
    gotoxy (x2,Y2);
    cout<<"        ";
    gotoxy (x2,Y2-1);
    cout<<"        ";
    gotoxy(x2,Y2-2);
    cout<<"        ";
}
void moveenemy2()
{
     eraseenemy2();
     if(!movehorizontal)
     {
      x2=x2+1;
     if (x2==110)
        movehorizontal=true;
     }
     if (movehorizontal)
     {
        x2 = x2 -1;
        if(x2 <4)
        movehorizontal=false;
     }
     printenemy2();
}
void printenemy3()
{
    gotoxy (x3,Y3);
    cout<<"xXXX||XXXx";
    gotoxy (x3,Y3+1);
    cout<<"xXXX||XXXx";
    gotoxy (x3,Y3+2);
    cout<<"xXXX||XXXx";
}
void eraseenemy3()
{
    gotoxy (x3,Y3);
    cout<<"          ";
    gotoxy (x3,Y3+1);
    cout<<"          ";
    gotoxy (x3,Y3+2);
    cout<<"          ";
}
void moveenemy3()
{
    eraseenemy3();
    if (!movediagnol)
    {
        x3=x3-1;
        Y3=Y3+1;
    if (x3<=84 && Y3>=20)
        movediagnol=true;
    }
    if (movediagnol)
    {
        x3=x3+1;
        Y3=Y3-1;
        if (x3>=94 && Y3<=27)
        movediagnol = false;
    }
    printenemy3();

}
void printplayer()
{
    gotoxy(m,n);
    cout<<"  ***  ";
    gotoxy(m,n+1);
    cout<<" *   * ";
    gotoxy(m,n+2);
    cout<<"  ***  ";
}
void eraseplayer()
{
    gotoxy(m,n);
    cout<<"       ";
    gotoxy(m,n+1);
    cout<<"       ";
    gotoxy(m,n+2);
    cout<<"       ";
}
void gotoxy (int x,int y)
{
    COORD coordinates;
    coordinates.X=x;
    coordinates.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
CHAR_INFO ci;
COORD xy = {0, 0};
SMALL_RECT rect = {x, y, x, y};
COORD coordBufSize;
coordBufSize.X = 1;
coordBufSize.Y = 1;
return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
: ' ';
}
void moveplayerleft()
{
    if(getCharAtxy(m-1,n)==' ')
    {
        eraseplayer();
        m=m-1;
        printplayer();
    }
}
void moveplayerright()
{
    if(getCharAtxy(m+7,n)==' ')
    {
        eraseplayer();
        m=m+1;
        printplayer();
    }
}
void moveplayerup()
{
    if(getCharAtxy(m,n-1)==' ')
    {
        eraseplayer();
        n=n-1;
        printplayer();
    }
}
void moveplayerdown()
{
    if(getCharAtxy(m,n+3)==' ')
    {
        eraseplayer();
        n=n+1;
        printplayer();
    }
}