#include<iostream>
#include<windows.h>
#include<conio.h>


using namespace std;


//Header
string header();
void inGameHeader();
void loading();
void gameOver();
void Win();
void instructionHeader();
void Instructions();

void hideCursor();
/// Maze
void printMaze();
//Player print
void printPlayer();
//erase
void erasePlayer();
///Player Movement
void movePlayerLeft();
void movePlayerRight();
void movePlayerUp();
void movePlayerDown();
/////Enemy Print
void printEnemy1();
void printEnemy2();
void printEnemy3();
void printEnemy4();
/////Enemy Erase
void eraseEnemy1();
void eraseEnemy2();
void eraseEnemy3();
void eraseEnemy4();
/////Move Enemy
void moveEnemy1();
void moveEnemy2();
void moveEnemy3();
void moveEnemy4();
///check Bullet Hits Enemy
void checkIfFireHitsEnemy(int [], int []);
/// 
void reduceEnemy1Health(); 
void reduceEnemy2Health();
void reduceEnemy3Health();
void reduceplayerHealth();
/// Updates the score
void updatescore();
string setColor(unsigned short color);
void gotoxy(int, int);
char getCharAtxy(short int,short int);
/// Health Player & Enemy
void health();
void enemyHealth();
////Create Fire
void generateFire();
//Erase Fire
void eraseFire(int fireX,int fireY);
//Bullet Go Inactive
void bulletGoInactive(int);
//Print Fire
void printFire(int fireX,int fireY);
// Delete Fire from Array
void deleteFireFromArray(int);
///move fire
void moveFire(int fireX[],int fireY[]);

////Randomness
bool isPositionEmpty(int pillX, int pillY)
{
    if (getCharAtxy(pillX,pillY) == ' ')
    {
        return true;
    }
    return false;
}
void generateScorePill()
{
    int pillX = rand() % 56;   
    int pillY = rand() % 120;      

    setColor(2);
    if (isPositionEmpty(pillX, pillY))   
    {
        gotoxy(pillY, pillX);       
        cout << '$';                   
    }
    else
    {
        generateScorePill();     
    }
    setColor(15);

}
//// 
void e1FIREkrdo();
void e1MoveFIRE();
void e2FIREkrdo();
void e2MoveFIRE(); 
void e3FIREkrdo();
void e3MoveFIRE();
/// Score Increment
void addScore();

/// Array for Fire
int fireX       [10000];
int fireY       [10000];
bool isFireActive [10000];
int fireCount =  0;

/////For Enemies
bool moveHorizontal = false; // for change of direction
bool moveVertical = false;   // for change of direction
bool moveDiagnol = false;    // for change of direction
bool moveHorizontal2 = false; // for change of direction

/////Health & Score
int score = 0;
int playerHealth = 100;
int E1Health = 100;
int E2Health = 100;
int E3Health = 100;

///// Variables for Player & Enemy
int eX1 = 49, eY1 = 4;///E1
int eX2 = 2, eY2 = 20;//E2
int eX3 = 98, eY3 = 27;//E3


int pX = 3, pY = 2;//Player


int e1Bx = 0, e1By = 0;
bool e1Fired = false;

int e2Bx = 0, e2By = 0;
bool e2Fired = false;

int e3Bx = 0, e3By = 0;
bool e3Fired = false;

/// Main start
main()
{
main:
    header();
    string option;
    cout <<"\t\t\t\t\tPress 1 To Start the Game."<<endl;
    cout <<"\t\t\t\t\tPress 2 to See Instructions."<<endl;   
    cout <<"\t\t\t\t\tPress 3 to Exit."<<endl;
    cout <<"\t\t\t\t\tEnter your Choice :";
    cin >> option;
    Sleep(1500);
    setColor(15);

    if (option == "1")
    {
        int count = 0;
    loading();
    system("cls");
    printMaze();
    inGameHeader();
    hideCursor();
 
    
    printPlayer();
    printEnemy1();
    printEnemy2();
    printEnemy3();
    generateScorePill();

    while (true)
    {
        health();
        enemyHealth();
        updatescore();
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePlayerLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePlayerRight();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            movePlayerUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePlayerDown();
        }
        count ++;
        if(count == 20)
        {
            generateScorePill();

        }
        
        if(count == 40)
        {
            generateScorePill();

        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            generateFire();
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
        if (E1Health != 0)
        {
            moveEnemy1();
        }
        if (E2Health != 0)
        {
            moveEnemy2();
        }
        if (E3Health !=0)
        {
            moveEnemy3();
        }
        moveFire(fireX,fireY);
        checkIfFireHitsEnemy(fireX,fireY);
        ///Enemy fires
        if (!e1Fired)
        {
            if (E1Health>0)
            e1FIREkrdo();
        }
        if (e1Fired)
        {
            e1MoveFIRE();
        }
        if(!e2Fired)
        {
            if (E2Health>0)
            e2FIREkrdo();
        }
        if (e2Fired)
        {
            e2MoveFIRE();
        }
        if (!e3Fired)
        {
            if (E3Health>0)
            e3FIREkrdo();
        }
        if (e3Fired)
        {
            e3MoveFIRE();
        }
        if (playerHealth == 0)
        {
            system("cls");
            gameOver();
            break;
        }
        if (E1Health == 0 && E2Health == 0 && E3Health == 0)
        {
            system("cls");
            Win();
            break;
        }
        Sleep(25);
    }
    
    }
    ///while ends
    else if (option == "2")
    {
        system("cls");
        instructionHeader();
        Instructions();
    }//while get ends
    else if (option == "3")
    {
        exit(0);
    }
    else
    {
        cout << "Invalid Input";
        goto main;
    }
}//main ends
void e1FIREkrdo()
{
    e1Bx = eX1 - 1;
    e1By = eY1 + 1;
    e1Fired = true;
}
void e1MoveFIRE()
{
    setColor(12);
    gotoxy(e1Bx, e1By);
    cout << " ";
    if (getCharAtxy(e1Bx - 1, e1By) == ' ')
    {
        e1Bx = e1Bx - 1;
        gotoxy(e1Bx, e1By);
        cout << "=";
    }
    else if (getCharAtxy(e1Bx - 1, e1By) == '>')
    {
        playerHealth = playerHealth - 10;
        gotoxy(e1Bx, e1By);
        cout << " ";
        e1Fired = false;
    }
    else
    {
        e1Fired = false;   
    }
    setColor(15);
}
void e2FIREkrdo()
{
    e2Bx = eX2 - 1;
    e2By = eY2 - 1;
    e2Fired = true;
}
void e2MoveFIRE()
{
    setColor(6);
    gotoxy(e2Bx, e2By);
    cout << " ";
    if (getCharAtxy(e2Bx - 1, e2By) == ' ')
    {
        e2Bx = e2Bx - 1;
        gotoxy(e2Bx, e2By);
        cout << "e";
    }
    else if (getCharAtxy(e2Bx - 1, e2By) == '>')
    {
        playerHealth = playerHealth - 10;
        gotoxy(e2Bx, e2By);
        cout << " ";
        e2Fired = false;
    }
    else
    {
        e2Fired = false;   
    }
    setColor(15);
}
void e3FIREkrdo()
{
    e3Bx = eX3 - 1;
    e3By = eY3 + 1;
    e3Fired = true;
}
void e3MoveFIRE()
{
    setColor(12);
    gotoxy(e3Bx, e3By);
    cout << " ";
    if (getCharAtxy(e3Bx - 1, e3By) == ' ')
    {
        e3Bx = e3Bx - 1;
        gotoxy(e3Bx, e3By);
        cout << "x";
    }
    else if (getCharAtxy(e3Bx - 1, e3By) == '>')
    {
        playerHealth = playerHealth - 10;
        gotoxy(e3Bx, e3By);
        cout << " ";
        e3Fired = false;
    }
    else
    {
        e3Fired = false;   
    }
    setColor(15);

}
void printFire(int fireX , int fireY)     /////The Index that generates Fire
{
    setColor(11);
    if(getCharAtxy(fireX + 1,fireY) != '|')
    {
        gotoxy(fireX,fireY);
        cout << "o";
    }
    setColor(15);
}
void deleteFireFromArray(int index)
{
    for (int j = index ; j < fireCount - 1; j++)
    {
        fireX[j] = fireX[j+1];
        fireY[j] = fireY[j+1];
        isFireActive[j] = isFireActive[j+1];
    }
    fireCount --;
}
void eraseFire(int fireX,int fireY)
{
    gotoxy(fireX,fireY);
    cout << " ";
}
void generateFire()
{
    fireX[fireCount] = pX + 6;
    fireY[fireCount] = pY ;
    isFireActive[fireCount] = true;
    printFire(fireX[fireCount],fireY[fireCount]);
    fireCount++;
}
void moveFire(int fireX[],int fireY[])///to move fire player
{
    for (int idx = 0 ; idx < fireCount ; idx++)
    {
        if (isFireActive[idx] == true)
        {
        char next = getCharAtxy(fireX[idx] + 1, fireY[idx]);
        if ((next == '|') || (next == '=') || (next == '$') || (next == 'e') || (next == '?') || (next == 'x'))
        {
            eraseFire(fireX[idx],fireY[idx]);
            bulletGoInactive(idx);///bool false
            deleteFireFromArray(idx);
        }
        else
        {
            eraseFire(fireX[idx],fireY[idx]);
            fireX[idx] = fireX[idx] + 1;
            printFire(fireX[idx],fireY[idx]);
        }
        }
    }
}
void bulletGoInactive(int anyIndex)
{
    isFireActive[anyIndex] = false;
}
/////////Collision Detection with Enemy

void checkIfFireHitsEnemy(int fireX[], int fireY[])
{
    for (int x = 0 ; x < fireCount ; x++)
    {
        if (isFireActive[x] == true)
        {
        if((fireY[x] >= eY1 && fireY[x] <= eY1+2) && ((fireX[x] == eX1) || (fireX[x] == eX1 + 1) || (fireX[x] == eX1 + 2) || (fireX[x] == eX1 + 3) || (fireX[x] == eX1 + 4) || (fireX[x] == eX1 + 5) || (fireX[x] == eX1 + 6) || (fireX[x] == eX1 + 7) || (fireX[x] == eX1 + 8) || (fireX[x] == eX1 + 9) || (fireX[x] == eX1 + 10)) && E1Health!=0)
        {
        addScore();
        updatescore();
        reduceEnemy1Health();
        eraseFire(fireX[x], fireY[x]);
        isFireActive[x] = false;
        if (E1Health == 0)
            eraseEnemy1();
        deleteFireFromArray(x);
        }
        if((fireY[x] >= eY2 - 2 && fireY[x] <= eY2) && ((fireX[x] == eX2) || (fireX[x] == eX2 + 1) || (fireX[x] == eX2 + 2) || (fireX[x] == eX2 + 3) || (fireX[x] == eX2 + 4) || (fireX[x] == eX2 + 5) || (fireX[x] == eX2 + 6) || (fireX[x] == eX2 + 7) || (fireX[x] == eX2 + 8) || (fireX[x] == eX2 + 9) || (fireX[x] == eX2 + 10)) && E2Health!=0)
        {
        addScore();
        updatescore();
        reduceEnemy2Health();
        eraseFire(fireX[x], fireY[x]);
        isFireActive[x] = false;
        if (E2Health == 0)
            eraseEnemy2();
        deleteFireFromArray(x);
        }
        if((fireY[x] >= eY3 && fireY[x] <= eY3 + 2) && ((fireX[x] == eX3) || (fireX[x] == eX3 + 1) || (fireX[x] == eX3 + 2) || (fireX[x] == eX3 + 3) || (fireX[x] == eX3 + 4) || (fireX[x] == eX3 + 5) || (fireX[x] == eX3 + 6) || (fireX[x] == eX3 + 7) || (fireX[x] == eX3 + 8) || (fireX[x] == eX3 + 9) || (fireX[x] == eX3 + 10)) && E3Health!=0)
        {
        addScore();
        updatescore();
        reduceEnemy3Health();
        eraseFire(fireX[x], fireY[x]);
        isFireActive[x] = false;
        if (E3Health == 0)
            eraseEnemy3();
        deleteFireFromArray(x);
        }
        }
    }
}
//////Health
void health()
{
    setColor(10);
    gotoxy(8, 45);
    cout << "H  E  A  L  T  H";
    gotoxy(10, 47);
    cout << "Health: " << playerHealth << " ";
    setColor(15);
}
void reduceEnemy1Health()
{
    E1Health = E1Health - 1;
}
void reduceEnemy2Health()
{
    E2Health = E2Health - 1;
}
void reduceEnemy3Health()
{
    E3Health = E3Health - 1;
}
void reduceplayerHealth()
{
    playerHealth = playerHealth - 10;

}
void enemyHealth()
{
    setColor(12);
    gotoxy(43,45);
    cout<<"E N E M Y 1";
    setColor(12);
    gotoxy(41,47);
    cout <<"Enemy1Health: " <<E1Health << " ";
    setColor(12);
    gotoxy(75,45);
    cout<<"E N E M Y 2";
    setColor(14);
    gotoxy(73,47);
    cout <<"Enemy2Health: " <<E2Health << " ";
    setColor(12);
    gotoxy(107,45);
    cout<<"E N E M Y 3";
    setColor(9);
    gotoxy(105,47);
    cout <<"Enemy3Health: " <<E3Health << " ";
    setColor(15);
}
///////  
void printPlayer()
{
    setColor(11);
    gotoxy(pX, pY);
    cout << "|(0)>";
    gotoxy(pX, pY + 1);
    cout << "/(0)>";
    setColor(15);
}
void erasePlayer()
{
    gotoxy(pX, pY);
    cout << "     ";
    gotoxy(pX, pY + 1);
    cout << "     ";
}
void updatescore()
{
    gotoxy(30,57);
    cout<<"S C O R E :";
    gotoxy(45,57);
    cout<< score << " ";
}
void addScore()
{
    score = score + 1;
}
void movePlayerLeft()
{
    if (getCharAtxy(pX - 1, pY) == ' ' && getCharAtxy(pX - 1, pY + 1) == ' ')
    {
        erasePlayer();
        pX = pX - 1;
        printPlayer();
    }
    else if (getCharAtxy(pX - 1, pY) == '?' || getCharAtxy(pX - 1, pY + 1) == '?')
    {
        score = score + 10; //scorepill
        erasePlayer();
        pX = pX - 1;
        printPlayer();      
    }
    else if (getCharAtxy(pX - 1, pY) == '$' || getCharAtxy(pX - 1, pY + 1) == '$')
    {
        score = score + 20; //scorepill
        erasePlayer();
        pX = pX - 1;
        printPlayer();      
    }
}
void movePlayerRight()
{
    if (getCharAtxy(pX + 6, pY) == ' ' && getCharAtxy(pX + 6, pY + 1) == ' ')
    {
        erasePlayer();
        pX = pX + 1;
        printPlayer();
    }
    else if (getCharAtxy(pX + 6, pY) == '?' || getCharAtxy(pX + 6, pY + 1) == '?')
    {
        score = score + 10;
        erasePlayer();
        pX = pX + 1;
        printPlayer();
    }
    else if (getCharAtxy(pX + 6, pY) == '$' || getCharAtxy(pX + 6, pY + 1) == '$')
    {
        score = score + 20;
        erasePlayer();
        pX = pX + 1;
        printPlayer();
    }
}
void movePlayerUp()
{
    if (getCharAtxy(pX, pY - 1) == ' ' && getCharAtxy(pX + 1, pY - 1) == ' ' && getCharAtxy(pX + 2, pY - 1) == ' ' &&
        getCharAtxy(pX + 3, pY - 1) == ' ' && getCharAtxy(pX + 4, pY - 1) == ' ' && getCharAtxy(pX + 5, pY - 1) == ' ')
    {
        erasePlayer();
        pY = pY - 1;
        printPlayer();
    }
    else if (getCharAtxy(pX, pY - 1) == '?' || getCharAtxy(pX + 1, pY - 1) == '?' || getCharAtxy(pX + 2, pY - 1) == '?' ||
            getCharAtxy(pX + 3, pY - 1) == '?' || getCharAtxy(pX + 4, pY - 1) == '?' || getCharAtxy(pX + 5, pY - 1) == '?')
    {
        score = score + 10;
        erasePlayer();
        pY = pY - 1;
        printPlayer();
    }
    else if (getCharAtxy(pX, pY - 1) == '$' || getCharAtxy(pX + 1, pY - 1) == '$' || getCharAtxy(pX + 2, pY - 1) == '$' ||
            getCharAtxy(pX + 3, pY - 1) == '$' || getCharAtxy(pX + 4, pY - 1) == '$' || getCharAtxy(pX + 5, pY - 1) == '$')
    {
        score = score + 20;
        erasePlayer();
        pY = pY - 1;
        printPlayer();
    }
}
void movePlayerDown()
{
    if (getCharAtxy(pX, pY + 2) == ' ' && getCharAtxy(pX + 1, pY + 2) == ' ' && getCharAtxy(pX + 2, pY + 2) == ' ' &&
        getCharAtxy(pX + 3, pY + 2) == ' ' && getCharAtxy(pX + 4, pY + 2) == ' ' && getCharAtxy(pX + 5, pY + 2) == ' ')
    {
        erasePlayer();
        pY = pY + 1;
        printPlayer();
    }
    else if (getCharAtxy(pX, pY + 2) == '?' || getCharAtxy(pX + 1, pY + 2) == '?' || getCharAtxy(pX + 2, pY + 2) == '?' ||
            getCharAtxy(pX + 3, pY + 2) == '?' || getCharAtxy(pX + 4, pY + 2) == '?' || getCharAtxy(pX + 5, pY + 2) == '?')
    {
        score = score + 10;
        erasePlayer();
        pY = pY + 1;
        printPlayer();
    }
    else if (getCharAtxy(pX, pY + 2) == '$' || getCharAtxy(pX + 1, pY + 2) == '$' || getCharAtxy(pX + 2, pY + 2) == '$' ||
            getCharAtxy(pX + 3, pY + 2) == '$' || getCharAtxy(pX + 4, pY + 2) == '$' || getCharAtxy(pX + 5, pY + 2) == '$')
    {
        score = score + 20;
        erasePlayer();
        pY = pY + 1;
        printPlayer();
    }
}
void printEnemy1()
{
    setColor(12);
    gotoxy(eX1, eY1);
    cout << "^^^^^^^^^^";
    gotoxy(eX1, eY1 + 1);
    cout << "==========";
    gotoxy(eX1, eY1 + 2);
    cout << "vvvvvvvvvv";
    setColor(15);
}
void eraseEnemy1()
{
    gotoxy(eX1, eY1);
    cout << "          ";
    gotoxy(eX1, eY1 + 1);
    cout << "          ";
    gotoxy(eX1, eY1 + 2);
    cout << "          ";
}
void moveEnemy1()
{
    eraseEnemy1();
    if (!moveVertical)
    {
        eY1 = eY1 + 1;
        if (eY1 >= 12)
            moveVertical = true;
    }
    if (moveVertical)
    {
        eY1 = eY1 - 1;
        if (eY1 < 2)
            moveVertical = false;
    }

    printEnemy1();
}
void printEnemy2()
{
    setColor(6);
    gotoxy(eX2, eY2);
    cout << "<<=||=>>";
    gotoxy(eX2, eY2 - 1);
    cout << "<<=||=>>";
    gotoxy(eX2, eY2 - 2);
    cout << "<<=||=>>";
    setColor(15);
}
void eraseEnemy2()
{
    gotoxy(eX2, eY2);
    cout << "        ";
    gotoxy(eX2, eY2 - 1);
    cout << "        ";
    gotoxy(eX2, eY2 - 2);
    cout << "        ";
}
void moveEnemy2()
{
    eraseEnemy2();
    if (!moveHorizontal)
    {
        eX2 = eX2 + 1;
        if (eX2 == 110)
            moveHorizontal = true;
    }
    if (moveHorizontal)
    {
        eX2 = eX2 - 1;
        if (eX2 < 4)
            moveHorizontal = false;
    }
    printEnemy2();
}
void printEnemy3()
{
    setColor(9);
    gotoxy(eX3, eY3);
    cout << "xXXX||XXXx";
    gotoxy(eX3, eY3 + 1);
    cout << "xXXX||XXXx";
    gotoxy(eX3, eY3 + 2);
    cout << "xXXX||XXXx";
    setColor(15);
}
void eraseEnemy3()
{
    gotoxy(eX3, eY3);
    cout << "          ";
    gotoxy(eX3, eY3 + 1);
    cout << "          ";
    gotoxy(eX3, eY3 + 2);
    cout << "          ";
}
void moveEnemy3()
{
    eraseEnemy3();
    if (!moveDiagnol)
    {
        eX3 = eX3 - 1;
        eY3 = eY3 + 1;
        if (eX3 <= 84 && eY3 >= 20)
            moveDiagnol = true;
    }
    if (moveDiagnol)
    {
        eX3 = eX3 + 1;
        eY3 = eY3 - 1;
        if (eX3 >= 94 && eY3 <= 27)
            moveDiagnol = false;
    }
    printEnemy3();
}
void printMaze()
{
    setColor(10);
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                ?                               |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|##########################################|                                                                                     |" << endl;
    cout << "|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|                                                                                     |" << endl;
    cout << "|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|                                                                                     |" << endl;
    cout << "|##########################################|                                                                                     |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                    ?                                                                                                           |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                             |###############|                                                                  |" << endl;
    cout << "|                                             |%%%%%%%%%%%%%%%|                                                                  |" << endl;
    cout << "|                                             |###############|                                       ?                          |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                               |################################################################|" << endl;
    cout << "|                         ?                                     |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
    cout << "|                                                               |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
    cout << "|                                                               |################################################################|" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|#########################################|                                                                                      |" << endl;
    cout << "|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|                                                                                      |" << endl;
    cout << "|%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|                                                                                      |" << endl;
    cout << "|#########################################|                                                                                      |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                     ?                          |" << endl;
    cout << "|                 ?                                                                                                              |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "|                                                                                                                                |" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                               |                               |                               |                                |" << endl;
    cout << "|                               |                               |                               |                                |" << endl;
    cout << "|                               |                               |                               |                                |" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
    setColor(15);
}
void inGameHeader()
{    
    setColor(1);
    gotoxy (20,50);
    cout <<"                                                                       "<<endl;     
    gotoxy(20,51);
    cout <<"    ______                              __  __            __           "<<endl;
    gotoxy(20,52);
    cout <<"   / ____/___  ___  ____ ___  __  __   / / / /_  ______  / /____  _____"<<endl;
    gotoxy(20,53);
    cout <<"  / __/ / __ \\/ _ \\/ __ `__ \\/ / / /  / /_/ / / / / __ \\/ __/ _ \\/ ___/"<<endl;
    gotoxy(20,54);
    cout <<" / /___/ / / /  __/ / / / / / /_/ /  / __  / /_/ / / / / /_/  __/ /    "<<endl;
    gotoxy(20,55);
    cout <<"/_____/_/ /_/\\___/_/ /_/ /_/\\__, /  /_/ /_/\\__,_/_/ /_/\\__/\\___/_/     "<<endl;
    gotoxy(20,56);
    cout <<"                           /____/                                      "<<endl;
    cout <<"                                                                       "<<endl;
    cout <<"\n\n";                                                               
    setColor(15);
}
string header()
{
    system("cls");
    cout << endl
         << endl;
    setColor(10);
    cout <<"                                                                                                                                                                                                                             "<<endl;   
    cout <<" .----------------.  .-----------------. .----------------.  .----------------.  .----------------.   .----------------.  .----------------.  .-----------------. .----------------.  .----------------.  .----------------. "<<endl;
    cout <<"| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. | | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |"<<endl;
    cout <<"| |  _________   | || | ____  _____  | || |  _________   | || | ____    ____ | || |  ____  ____  | | | |  ____  ____  | || | _____  _____ | || | ____  _____  | || |  _________   | || |  _________   | || |  _______     | |"<<endl;
    cout <<"| | |_   ___  |  | || ||_   \\|_   _| | || | |_   ___  |  | || ||_   \\  /   _|| || | |_  _||_  _| | | | | |_   ||   _| | || ||_   _||_   _|| || ||_   \\|_   _| | || | |  _   _  |  | || | |_   ___  |  | || | |_   __ \\    | |"<<endl;
    cout <<"| |   | |_  \\_|  | || |  |   \\ | |   | || |   | |_  \\_|  | || |  |   \\/   |  | || |   \\ \\  / /   | | | |   | |__| |   | || |  | |    | |  | || |  |   \\ | |   | || | |_/ | | \\_|  | || |   | |_  \\_|  | || |   | |__) |   | |"<<endl;
    cout <<"| |   |  _|  _   | || |  | |\\ \\| |   | || |   |  _|  _   | || |  | |\\  /| |  | || |    \\ \\/ /    | | | |   |  __  |   | || |  | '    ' |  | || |  | |\\ \\| |   | || |     | |      | || |   |  _|  _   | || |   |  __ /    | |"<<endl;
    cout <<"| |  _| |___/ |  | || | _| |_\\   |_  | || |  _| |___/ |  | || | _| |_\\/_| |_ | || |    _|  |_    | | | |  _| |  | |_  | || |   \\ `--' /   | || | _| |_\\   |_  | || |    _| |_     | || |  _| |___/ |  | || |  _| |  \\ \\_  | |"<<endl;
    cout <<"| | |_________|  | || ||_____|\\____| | || | |_________|  | || ||_____||_____|| || |   |______|   | | | | |____||____| | || |    `.__.'    | || ||_____|\\____| | || |   |_____|    | || | |_________|  | || | |____| |___| | |"<<endl;
    cout <<"| |              | || |              | || |              | || |              | || |              | | | |              | || |              | || |              | || |              | || |              | || |              | |"<<endl;
    cout <<"| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' | | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |"<<endl;
    cout <<" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'   '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' "<<endl;
    cout <<"\n\n";
    setColor(15); 
}
void loading()
{
    system("cls");
    // header();
    setColor(8);
    cout <<"                                                                "<<endl;    
    cout <<" /$$                                 /$$ /$$                    "<<endl;
    cout <<"| $$                                | $$|__/                    "<<endl;
    cout <<"| $$        /$$$$$$   /$$$$$$   /$$$$$$$ /$$ /$$$$$$$   /$$$$$$ "<<endl;
    cout <<"| $$       /$$__  $$ |____  $$ /$$__  $$| $$| $$__  $$ /$$__  $$"<<endl;
    cout <<"| $$      | $$  \\ $$  /$$$$$$$| $$  | $$| $$| $$  \\ $$| $$  \\ $$"<<endl;
    cout <<"| $$      | $$  | $$ /$$__  $$| $$  | $$| $$| $$  | $$| $$  | $$"<<endl;
    cout <<"| $$$$$$$$|  $$$$$$/|  $$$$$$$|  $$$$$$$| $$| $$  | $$|  $$$$$$$"<<endl;
    cout <<"|________/ \\______/  \\_______/ \\_______/|__/|__/  |__/ \\____  $$"<<endl;
    cout <<"                                                       /$$  \\ $$"<<endl;
    cout <<"                                                      |  $$$$$$/"<<endl;
    cout <<"                                                       \\______/ "<<endl;
    cout <<"\n\n";
    Sleep(1500);
    setColor(15);
}
void gameOver()
{
    system("cls");
    setColor(12);
    cout <<"                                                                           "<<endl;   
    cout <<" /$$     /$$                        /$$                                    "<<endl;
    cout <<"|  $$   /$$/                       | $$                                    "<<endl;
    cout <<" \\  $$ /$$//$$$$$$  /$$   /$$      | $$        /$$$$$$   /$$$$$$$  /$$$$$$ "<<endl;
    cout <<"  \\  $$$$//$$__  $$| $$  | $$      | $$       /$$__  $$ /$$_____/ /$$__  $$"<<endl;
    cout <<"   \\  $$/| $$  \\ $$| $$  | $$      | $$      | $$  \\ $$|  $$$$$$ | $$$$$$$$"<<endl;
    cout <<"    | $$ | $$  | $$| $$  | $$      | $$      | $$  | $$ \\____  $$| $$_____/"<<endl;
    cout <<"    | $$ |  $$$$$$/|  $$$$$$/      | $$$$$$$$|  $$$$$$/ /$$$$$$$/|  $$$$$$$"<<endl;
    cout <<"    |__/  \\______/  \\______/       |________/ \\______/ |_______/  \\_______/"<<endl;
    cout <<"                                                                           "<<endl;
    cout <<"\n\n";
    cout <<"Press Any Key to Continue......"<<endl;
            getch();
    setColor(15);   
}
string setColor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    return "";
}
void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; // Set cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
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
void Win()
{
    system("cls");
    setColor(14);
    cout <<"                                                              "<<endl;
    cout <<" /$$     /$$                        /$$      /$$ /$$          "<<endl;
    cout <<"|  $$   /$$/                       | $$  /$ | $$|__/          "<<endl;
    cout <<" \\  $$ /$$//$$$$$$  /$$   /$$      | $$ /$$$| $$ /$$ /$$$$$$$ "<<endl;
    cout <<"  \\  $$$$//$$__  $$| $$  | $$      | $$/$$ $$ $$| $$| $$__  $$"<<endl;
    cout <<"   \\  $$/| $$  \\ $$| $$  | $$      | $$$$_  $$$$| $$| $$  \\ $$"<<endl;
    cout <<"    | $$ | $$  | $$| $$  | $$      | $$$/ \\  $$$| $$| $$  | $$"<<endl;
    cout <<"    | $$ |  $$$$$$/|  $$$$$$/      | $$/   \\  $$| $$| $$  | $$"<<endl;
    cout <<"    |__/  \\______/  \\______/       |__/     \\__/|__/|__/  |__/"<<endl;
    cout <<"                                                              "<<endl;
    cout <<"\n\n";
    setColor(15);
}
void instructionHeader()
{    
    setColor(13);
    cout<<"\t\t\t\t _____          _                   _   _                 "<<endl;
    cout<<"\t\t\t\t|_   _|        | |                 | | (_)                "<<endl;
    cout<<"\t\t\t\t  | | _ __  ___| |_ _ __ _   _  ___| |_ _  ___  _ __  ___ "<<endl;
    cout<<"\t\t\t\t  | || '_ \\/ __| __| '__| | | |/ __| __| |/ _ \\| '_ \\/ __|"<<endl;
    cout<<"\t\t\t\t _| || | | \\__ \\ |_| |  | |_| | (__| |_| | (_) | | | \\__ \\"<<endl;
    cout<<"\t\t\t\t \\___/_| |_|___/\\__|_|   \\__,_|\\___|\\__|_|\\___/|_| |_|___/"<<endl;
    cout<<"\t\t\t\t                                                          "<<endl;
    cout<<"\n\n";
    setColor(15);
}
void Instructions()
{
        setColor(13);
        cout <<"\t\t\t\t\tInstructions"<<endl;
        cout <<"\t\t\t\t\t1. Use Arrow Keys to move the player"<<endl;
        cout <<"\t\t\t\t\t========================================="<<endl;
        cout <<"\t\t\t\t\t (Functions)-----------------------(KEYS)"<<endl;
        cout <<"\t\t\t\t\t========================================="<<endl;
        cout <<" \t\t\t\t\tMove Left---------------------------> Left Arrow"<<endl;
        cout <<" \t\t\t\t\tMove Right--------------------------> Right Arrow"<<endl;
        cout <<" \t\t\t\t\tMove Up-----------------------------> Up Arrow"<<endl;
        cout <<" \t\t\t\t\tMove Down---------------------------> Down Arrow"<<endl;        
        cout <<"\t\t\t\t\t========================================="<<endl;
        cout <<"\t\t\t\t\t2. Press Space to fire"<<endl;
        cout <<"\t\t\t\t\t========================================="<<endl;
        cout <<"\t\t\t\t\t (Functions)-----------------------(KEYS)"<<endl;
        cout <<"\t\t\t\t\t========================================="<<endl;
        cout <<" \t\t\t\t\tFire------------------------------> Space"<<endl;
        cout <<"\t\t\t\t\t========================================="<<endl;
        cout <<"\t\t\t\t\t3. Press Esc to exit"<<endl;
        cout <<"\n\n";
        cout <<"\t\t\t\t\tPress Any Key to Go Back to Main Menu :"<<endl;
        getch();
        setColor(15);
}