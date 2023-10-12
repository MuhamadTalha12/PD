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
int x,y,x1=40,x2=2,x3=98,y1=6,y2=20,y3=27,m=4,n=4;
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
    Sleep(200);
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
     cout<<"----------------------------------------------------------------------------------------------------------------------------------"<<endl;

}

void printenemy1()
{
    gotoxy (x1,y1);
    cout <<"      |_______________|  ";
    gotoxy (x1,y1+1);
    cout<<"      |===============|   ";
    gotoxy (x1,y1+2);
    cout<<"       vvvvvvvvvvvvvvv    ";    
}
void eraseenemy1()
{
    gotoxy (x1,y1);
    cout<<"                          ";
    gotoxy (x1,y1+2);
    cout<<"                           ";
    gotoxy (x1,y1+2);
    cout<<"                           ";
}
void moveenemy1()
{
    eraseenemy1();
    y1=y1+1;
    if (y1>=12)
    {
        y1=1;
    }
    printenemy1();
}
void printenemy2()
{
    gotoxy (x2,y2);
    cout <<"     ||==>>>> ";
    gotoxy (x2,y2-1);
    cout<<"     ||==>>>>  ";
    gotoxy (x2,y2-2);
    cout<<"     ||==>>>>  ";    
}
void eraseenemy2()
{
    gotoxy (x2,y2);
    cout<<"             ";
    gotoxy (x2,y2+1);
    cout<<"             ";
    gotoxy(x2,y2+2);
    cout<<"             ";
}
void moveenemy2()
{
     eraseenemy2();
     x2=x2+1;
     if (x2>=110)
     {
         x2=4;
     }
     printenemy2();
}
void printenemy3()
{
    gotoxy (x3,y3);
    cout<<"      xXXXXXXX||      ";
    gotoxy (x3,y3+1);
    cout<<"      xXXXXXXX||      ";
    gotoxy (x3,y3+2);
    cout<<"      xXXXXXXX||      ";
}
void eraseenemy3()
{
    gotoxy (x3,y3);
    cout<<"                      ";
    gotoxy (x3,y3+2);
    cout<<"                      ";
    gotoxy (x3,y3+2);
    cout<<"                      ";
}
void moveenemy3()
{
    eraseenemy3();
    x3=x3-1;
    y3=y3+1;
    if (x3<=84 && y3>=20)
    {
        x3=98;
        y3=27;
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