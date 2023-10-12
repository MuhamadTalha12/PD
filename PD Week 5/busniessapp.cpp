#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
void header();
void Menu (string choice );
void shopkeeper();
void addproducts();
void viewlist();
int get,quantity1,quantity2,quantity3;
float tax1,tax2,tax3,price1,price2,price3,fprice1,fprice2,fprice3;
string choice,prod1,prod2,prod3;
main ()
{
header();
Menu (choice);
addproducts();
}


void header()
{
    system ("cls");
    cout<<"======================================================================================================================================================================================"<<endl;
    cout<<"**************************************************************************************************************************************************************************************"<<endl;
    cout<<"======================================================================================================================================================================================"<<endl;
    cout<<"|     *****   ********    ******     ******    ******      ***       ***     *****     **     **     *****      ********    ******   ***       ***    ******    **     **   ******** | "<<endl;
    cout<<"|   **     **    **      **    **    **    **  **          **  **  ** **   **     **   ***    **   **     **   **     **    **       **  **  ** **    **        ***    **      **    | "<<endl;
    cout<<"|   **           **      **    **    **    **  **          **    **   **   **     **   ** **  **   **     **   **           **       **    **   **    **        ** **  **      **    | "<<endl;
    cout<<"|    ******      **      **    **    ******    *****       **         **   *********   **  ** **   *********   **   ****    *****    **         **    *****     **  ** **      **    | "<<endl;
    cout<<"|          **    **      **    **    **   **   **          **         **   **     **   **   ** *   **     **   **      **   **       **         **    **        **   ** *      **    | "<<endl;
    cout<<"|   **     **    **      **    **    **    **  **          **         **   **     **   **    ***   **     **   **      **   **       **         **    **        **    ***      **    | "<<endl;
    cout<<"|     *****      **       ******     **     ** *******     **         **   **     **   **     **   **     **    *********   ******   **         **    ******    **     **      **    | "<<endl;
    cout<<"====================================================================================================================================================================================== "<<endl;                                                                                                            
    cout<<"************************************************************************************************************************************************************************************** "<<endl;
    cout<<"====================================================================================================================================================================================== "<<endl;
}
void Menu (string choice )
{
    cout<<"##################################################################################################################  "<<endl;
    cout<<"                                    ***      ***   ******  ***    **  ***   ***                                     "<<endl;
    cout<<"                                    ** **  ** **   **      ** **  **  ***   ***                                     "<<endl;
    cout<<"                                    **   **   **   *****   **  ** **  ***   ***                                     "<<endl;
    cout<<"                                    **        **   **      **   ** *  ***   ***                                     "<<endl;
    cout<<"                                    **        **   ******  **    ***   *******                                      "<<endl; 
    cout<<"##################################################################################################################  "<<endl;
    cout<<"||||||||||||||||||||||||||||||  You are a SHOPKEEPER or CUSTOMER, Please ENTER:  |||||||||||||||||||||||||||||||||| "<<endl;
    cin >> choice;
   while (choice=="SHOPKEEPER")
   {
    system ("cls");
    shopkeeper();
   }
   while (choice=="CUSTOMER")
   {
    system("cls");
    cout <<" NO INPUT HERE!We are Sorry."<<endl;
    Sleep (800);
    system("cls");
    Menu(choice);
   }
    while (choice != "SHOPKEEPER || CUSTOMER")
    {
        system ("cls");
        cout<<"Thank You! Have a Good Day."<<endl;
    }
    
}
void shopkeeper()
{
    cout<<"####################################################################################################################"<<endl;
    cout<<"         *****    **        **   *****   *******   **     ** *******  *******  *******   *******   *******          "<<endl;
    cout<<"       **     **  **        ** **     ** **    **  **   **   **       **       **    **  **        **     **        "<<endl;
    cout<<"       **         **        ** **     ** **    **  ** **     **       **       **    **  **        **     **        "<<endl;
    cout<<"        ******    ************ **     ** *******   ****      ******   ******   ******    ******    *******          "<<endl;
    cout<<"              **  **        ** **     ** **        ** **     **       **       **        **        **   **          "<<endl;
    cout<<"      **      **  **        ** **     ** **        **   **   **       **       **        **        **     **        "<<endl;
    cout<<"        ******    **        **   *****   **        **     ** *******  *******  **        *******   **      **       "<<endl;
    cout<<"####################################################################################################################"<<endl;
    cout<<"||||||||||||||||||||||||||||||||==TO ADD PRODUCTS--------->Enter 1 ==||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"||||||||||||||||||||||||||||||||==TO VIEW PRODUCTS-------->Enter 2 ==||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cout<<"||||||||||||||||||||||||||||||||==BACK TO MENU PAGE------->Enter 0 ==||||||||||||||||||||||||||||||||||||||||||||||"<<endl;
    cin>> get;
    
    if (get == 1)
    {
        system ("cls");
        addproducts();
    }
    if (get == 2)
    {
        system("cls");
        viewlist();
    }
    if (get== 0)
    {
        system("cls");
        Menu (choice);
    }
}
void addproducts()
{
    cout<<"Enter first Product Name: ";
    cin>>prod1;
    cout<<"Enter the price of Product: Rs.";
    cin>>price1;
    cout<<"Enter the tax on Product(%): ";
    cin>>tax1;
    cout<<"Enter the quantity of Product: ";
    cin>>quantity1;
    cout<<"Enter Second Product Name: ";
    cin>>prod2;
    cout<<"Enter the price of Product: Rs.";
    cin>>price2;
    cout<<"Enter the tax on Product(%): ";
    cin>>tax2;
    cout<<"Enter the quantity of Product: ";
    cin>>quantity2;
    cout<<"Enter Third Product Name: ";
    cin>>prod3;
    cout<<"Enter the price of Product: Rs.";
    cin>>price3;
    cout<<"Enter the tax on Product(%): ";
    cin>>tax3;
    cout<<"Enter the quantity of Product: ";
    cin>>quantity3;
    fprice1=price1-(price1*(tax1/100));
    fprice2=price2-(price2*(tax2/100));
    fprice3=price3-(price3*(tax3/100));
    viewlist();
}
void viewlist()
{
    system("cls");
    cout<<"======================================================================================"<<endl;
    cout<<"ProductNo.\tProductName\tPrice\tTax\tQuantity\tFinal Price\n";
    cout<<"1.        \t"<<prod1<<"\t\t"<<price1<<"\t"<<tax1<<"\t"<<quantity1<<"\t\t"<<fprice1<<"\n";
    cout<<"2.        \t"<<prod2<<"\t\t"<<price2<<"\t"<<tax2<<"\t"<<quantity2<<"\t\t"<<fprice2<<"\n";
    cout<<"3.        \t"<<prod3<<"\t\t"<<price3<<"\t"<<tax3<<"\t"<<quantity3<<"\t\t"<<fprice3<<"\n";
    cout<<"======================================================================================"<<endl;
    return shopkeeper();
}