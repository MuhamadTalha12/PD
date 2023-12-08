#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

//Headers
void header();
string mainpage();
void adminheader();
void clientheader();
//////////////////////////////////////////////////////////Admin Start//////////////////////////////////////////////////////////////////
string Adminmenu();//////Admin Options
void addNewItem(string Items[],int Price[],int Quantity[],string DeliveryArea[],int &productCount,string item, int price, int quantity);//1
void delItem(string Items[],int Price[], int Quantity[],string DeliveryArea[], int &productCount, int &del, int &num);//2
void viewProducts(string Items[],int Price[], int Quantity[],string DeliveryArea[], int &productCount, int &del); //3
void updatePrices(string Items[],int Price[], int Quantity[],string DeliveryArea[], int &productCount, int &del ,int idProduct, int price1);//4
void updateStock(string Items[],int Price[], int Quantity[],string DeliveryArea[], int &productCount , int &del, int idProduct, int quantity1);///5
void checkReview(string Items[],int Price[], int Quantity[], string Reviews[],string DeliveryArea[], int &productCount, int &del, int Rev);//6
void addDeliveryArea(string Items[],int Price[], int Quantity[], string DeliveryArea[], int &productCount, int &del,int No, string area);//7
void removeDeliveryArea(string Items[],int Price[], int Quantity[], string DeliveryArea[], int &productCount, int &del,int No2);//8
void changePassword(string PasswordDB[], int &usercount, int idx,string currentPass, string newPass);//9
// Logout 10
//////////////////////////////////////////////////////////Admin Complete//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////Client Start////////////////////////////////////////////////////////////////
string Clientmenu();//////Client Options
////////     1       View products
void addCart(string Items[], int Price[], int Quantity[],string DeliveryArea[], int &productCount, int &del, int &idx1 , string productCart[], int quantityCart[], int [],int n2,int added,int quant,int cidx,int prc,string name3);//2
int viewCart(string productCart[], int quantityCart[], int &idx1, int Price[], int);//3
void checkPrice(string Items[],int Price[], int &productCount);//4
void checkStock(string Items[],int Quantity[], int &productCount);//5
void reviewProduct(string Items[],int Price[],int Quantity[],string DeliveryArea[], int &productCount, int &del , string Reviews[],int no,string revi);//7
void checkDeliveryArea(string Items[],string DeliveryArea[], int &productCount);//7
void viewBill(string productCart[], int quantityCart[], int &idx1 , int priceCart[], int &);
///         9 Change Password
////       10 LogOut 

void storeData(string NameDB[100],string PasswordDB[100],string RoleDB[100],int usercount);
//////////////////////////////////////////////////////////Client Complete////////////////////////////////////////////////////////////////
///////Sign Up
void createUser(string NameDB[],string PasswordDB[] , string RoleDB[] ,int &usercount,string username,string password ,string role);
bool contineSignup(string role);
///////Log In
string LogIn(string NameDB[],string PasswordDB[] , string RoleDB[] ,int &usercount,string username1,string password1);
/// bool foor checking Signup
bool checkUserName(string name, string NameDB[], int usercount);


int main ()
{
    /////Variables.......
    string NameDB[100];
    string PasswordDB[100];
    string RoleDB[100];
    int usercount = 0;
    ///Admin Variable
    int productCount=3;
    string Items[100] = {"Panadol", "Disprin", "Juice"};
    int Price[100] = {50, 30, 60};
    int Quantity[100] = {4, 6, 2};
    string Reviews[100]={"Expert", "Good" , "Best"};
    string DeliveryArea[100]={"Lahore" , "Karachi" , "SadiqAbad"};
    string productCart[100];
    int quantityCart[100];
    int priceCart[100];
    int idx1=0;
    
    
    ///Delete
    int del = 0;



    // main
    // option main.... for SignUp
    string optionmain="";
    string loginRole;
Logout:
    while(optionmain!="3")
    {
        system("cls");
        header();

        optionmain=mainpage();

        if(optionmain=="3")
        {
        /// Exit
        storeData(NameDB,PasswordDB,RoleDB,usercount);
        return 0;
        }

        if (optionmain == "2")
        ///Sign Up
        {
        string username,password,role;
        cout << "\t\t\t\t\t\tEnter User Name: ";
        cin  >> username;
        if(!checkUserName (username, NameDB , usercount))
        {
        cout << "\t\t\t\t\t\tEnter Password: ";
        cin  >> password;
        cout << "\t\t\t\t\t\tEnter Role (Admin or Client): ";
        cin  >> role;
        if (contineSignup(role))
        {
            createUser(NameDB, PasswordDB , RoleDB , usercount, username, password , role);
        }
        }
        else
        {
        cout << "\t\t\t\t\t\tUser Already Exists\n";
        cout << "\t\t\t\t\t\tPress Any Key to Continue...";
        getch();
        }
        }
          
        if (optionmain == "1")
        {
            // Login
            string username1,password1,role1;
            cout << "\t\t\t\t\t\tEnter Username: ";
            cin >> username1;
            cout << "\t\t\t\t\t\tEnter Password: ";
            cin >> password1;
            loginRole = LogIn(NameDB, PasswordDB, RoleDB, usercount, username1 ,password1);
            if (loginRole != "nill")
            {
            break;
            }
            else
            {
            cout << "\t\t\t\t\t\tInvalid Credentials...\n";
            cout << "\t\t\t\t\t\tPress Any Key to Go Back";
            getch ();
            }
        }
    }

    //Outside Loop   
    if (loginRole == "Admin" || loginRole == "admin")
    {
        // loginAdmin();
            
        while(true)
        {
        // Get what Admin menu returns..
        
        string adminOption = Adminmenu();

        if (adminOption == "1")
        {
            string item;
            int price,quantity;
            cout <<"\t\t\t\t\t\tEnter name of the item: ";
            cin >> item;
            cout <<"\t\t\t\t\t\tEnter price of the item: ";
            cin >> price;
            cout <<"\t\t\t\t\t\tEnter the quantity: ";
            cin >> quantity;
        addNewItem(Items, Price, Quantity,DeliveryArea, productCount , item , price, quantity);
            cout <<"\t\t\t\t\t\tPress Any Key to Continue...";
            getch();
        }
        else if (adminOption == "2")
        {
            del = 1;
            cout << "No.  Products Name\t\tPrice\t\tQuantity\t\tDelivery Areas "<< endl;
            viewProducts(Items, Price, Quantity,DeliveryArea, productCount, del);
            int num;
            cout << "\nEnter the item number you want to remove: ";
            cin >> num;
        delItem(Items, Price, Quantity,DeliveryArea, productCount, del , num);
            del = 0;
            viewProducts(Items, Price, Quantity,DeliveryArea, productCount, del);
        }   
        else if (adminOption == "3")
        {   
            system("cls");
            header();
            cout << "No.  Products Name\t\tPrice\t\tQuantity\t\tDelivery Areas "<< endl;
        viewProducts( Items, Price,  Quantity,DeliveryArea, productCount, del);
            // viewProducts();
            if (del == 0)
        {
            cout << "Press Any Key to Continue.....";
            getch ();
        }
        }
        else if (adminOption == "4")
        {
            int idProduct;
            int price1;
            del = 1;
            cout << "No.  Products Name\t\tPrice\t\tQuantity\t\tDelivery Areas "<< endl;
            viewProducts( Items, Price,  Quantity,DeliveryArea,  productCount, del);
            cout << "Enter the No. of the Item whom you want to update price: ";
            cin >> idProduct;
            cout << "Enter the updated Price: ";
            cin >> price1;
        updatePrices(Items, Price, Quantity,DeliveryArea, productCount, del,idProduct,price1);
            del = 0;
            cout << "Press Any Key to Continue.....";
            getch ();
            // updatePrices()
        }
        else if (adminOption == "5")
        {
            int idProduct;
            int quantity1;
            del = 1;
            cout << "No.  Products Name\t\tPrice\t\tQuantity\t\tDelivery Areas "<< endl;
            viewProducts( Items, Price,  Quantity, DeliveryArea, productCount, del);
            cout << "Enter the No. of the Item whom you want to update: ";
            cin >> idProduct;
            cout << "Enter the updated Stock: ";
            cin >> quantity1;
        updateStock(Items,Price, Quantity,DeliveryArea, productCount , del, idProduct, quantity1);
            del = 0;
            cout << "Press Any Key to Continue.....";
            getch ();
            // updateStock();
        }
        else if (adminOption == "6")
        {
            del=1;
            int Rev;
            cout << "No.  Products Name\t\tPrice\t\tQuantity\t\tDelivery Areas "<< endl;
            viewProducts(Items, Price, Quantity,DeliveryArea,productCount,del);
            cout <<"Enter the No. of Product whom you want to Check Review: ";
            cin >> Rev;
            cout << endl;
        checkReview(Items,Price, Quantity,Reviews,DeliveryArea, productCount,del,Rev);
            cout <<"\nPress Any Key to Continue...";
            getch();
            del = 0;
            // check Review
        }
        else if( adminOption == "7")
        {
            del=1;
            int No;
            string  area;
            cout << "No.  Products Name\t\tPrice\t\tQuantity\t\tDelivery Areas "<< endl;
            viewProducts( Items, Price,  Quantity, DeliveryArea, productCount, del);
            cout <<"Enter the No. of the Product whom you want to Add Delivery Area: ";
            cin >> No;
            cout <<"Enter the Area: ";
            cin >> area;
        addDeliveryArea(Items,Price,Quantity,DeliveryArea,productCount,del, No, area);
             cout <<"Press Any Key to Continue...";
             getch();
             del=0;
        }
        else if (adminOption == "8")
        {
            del=1;
            int No2;
            cout << "No.  Products Name\t\tPrice\t\tQuantity\t\tDelivery Areas "<< endl;
            viewProducts( Items, Price, Quantity, DeliveryArea, productCount, del);
            cout <<"Enter the No. of Item whom you want to remove Delivery Area: ";
            cin >> No2;
        removeDeliveryArea(Items,Price,Quantity,DeliveryArea,productCount,del,No2);
            getch();
            del=0;

        }
        else if (adminOption == "9")
        {
            string currentPass;
            string newPass;
            cout << "\t\t\t\t\t\tEnter current Password: ";
            cin >> currentPass;
            int idx;
        changePassword(PasswordDB,usercount,idx,currentPass,newPass);
            cout << "\n\t\t\t\t\t\tPress Any Key to Continue..";
            getch();
            // changePassword();
        }
        else if (adminOption == "10")
        {
            goto Logout;
        }
        else
        {
            cout << "\t\t\t\t\t\tError...\n";
            cout << "\t\t\t\t\t\tPlease Enter Correct Option....";
            Sleep (1000);
        }
        }
    }
    if (loginRole == "Client" || loginRole == "client")
    {
        // loginClient();

        while(true)
        {
        ////get what Client Menu Returns
        
        string clientOption = Clientmenu();

        if (clientOption == "1")
        {
            system("cls");
            header();
            cout << "No.  Products Name\t\tPrice\t\tQuantity\t\tDelivery Areas "<< endl;
        viewProducts( Items, Price,  Quantity,DeliveryArea, productCount, del);
            // viewProducts();
            if (del == 0)
        {
            cout << "Press Any Key to Continue.....";
            getch ();
        }
        }
        else if (clientOption == "2")
        {
            int n2;
            int added=0;
            int quant=0;
            int cidx =0;
            int prc = 0;

            del =1;
            cout << "No.  Products Name\t\tPrice\t\tQuantity\t\tDelivery Areas "<< endl;
            viewProducts(Items, Price,  Quantity,DeliveryArea, productCount, del);
            cout <<"Enter the item No you want to buy: ";
            cin >> n2;
            string name3="";
            cout << "Enter the Quantity :";
            cin >> added;
            for (int i=0 ; i<productCount ; i++)
            {
                if (i+1 == n2)
                {
                    name3 = Items[i];
                    quant = Quantity[i];
                    prc = Price[i] * added;
                    break;
                }
                cidx ++;
            }
        addCart(Items, Price, Quantity, DeliveryArea,productCount,del,idx1 , productCart, quantityCart, priceCart, n2,added,quant,cidx,prc, name3);
            del =0;
        }   
        else if (clientOption == "3")
        {
            system("cls");
            header();
            int bill =  0;
        viewCart(productCart,quantityCart,idx1, priceCart, del);
            if (del == 0)
            {
                cout << "\t\t\t\t\t\tPress Any Key to Continue....";
                getch();
            }
        
        }
        else if (clientOption == "4")
        {
            
            system("cls");
            header();
            cout <<"\t\t\t\t\t\tProduct Name\t\tPrice\n";
        checkPrice(Items,Price,productCount);
            cout << "\t\t\t\t\t\tPress Any Key to Continue....";
            getch();     
        }
        else if (clientOption == "5")
        {
            system("cls");
            header();
            cout <<"\t\t\t\t\t\tProduct Name\t\tQuantity\n";
        checkStock(Items,Quantity,productCount);
            cout << "\t\t\t\t\t\tPress Any Key to Continue....";
            getch();
        
        
        }
        else if (clientOption == "6")
        {
            system("cls");
            header();
            int no;
            del = 1;
            string revi;
            cout << "No.  Products Name\t\tPrice\t\tQuantity\t\tDelivery Areas "<< endl;
            viewProducts(Items, Price,  Quantity,DeliveryArea, productCount, del);
            cout <<"Enter the No of product you want to review: ";
            cin >> no;
            cout <<"Enter Review: ";
            cin >> revi;
        reviewProduct(Items,Price,Quantity,DeliveryArea,productCount,del ,Reviews,no,revi);
            cout << "\t\t\t\t\t\tPress Any Key to Continue....";
            getch();
            del = 0;
        }
        else if( clientOption == "7")
        {
            
            system("cls");
            header();
            cout <<"\t\t\t\t\t\tProduct Name\t\tDeliveryArea\n";
        checkDeliveryArea(Items,DeliveryArea,productCount);
            cout << "\t\t\t\t\t\tPress Any Key to Continue....";
            getch();
    
        }
        else if (clientOption == "8")
        {
            int payableBill;
            del = 1;
        viewBill(productCart, quantityCart, idx1, priceCart, del);
            cout << "\t\t\t\t\t\tPress Any Key to Continue..";
            getch();
            del = 0;

        }
        else if (clientOption == "9")
        {
            string currentPass;
            string newPass;
            cout << "\t\t\t\t\t\tEnter current Password: ";
            cin >> currentPass;
            int idx;
        changePassword(PasswordDB,usercount,idx,currentPass,newPass);
            cout << "\n\t\t\t\t\t\tPress Any Key to Continue..";
            getch();
        }
        else if (clientOption == "10")
        {
            goto Logout;
        }
        else
        {
            cout << "\t\t\t\t\t\tError... \n";
            cout << "\t\t\t\t\t\tPlease Enter Correct Option....";
            Sleep (1000);
        }
        }
    }

}
// Login Functions.....
string LogIn(string NameDB[],string PasswordDB[] , string RoleDB[] ,int &usercount,string username1,string password1 )
{
    string Role = "nill" ;
    for (int i=0 ; i < usercount ; i++)
    {
        if (NameDB[i] == username1 && PasswordDB[i] == password1)
        {
            Role = RoleDB[i];
        }
    }
    return Role;
}
////Login Menu........
///Admin Menu........
string Adminmenu()
{
    system ("cls");
    adminheader();
                
    string op1 = "" ;
    cout << endl ;
    cout << "\t\t\t\t\t\t1. Add an Item"            << endl;
    cout << "\t\t\t\t\t\t2. Delete an Item"         << endl;
    cout << "\t\t\t\t\t\t3. View Items"             << endl;
    cout << "\t\t\t\t\t\t4. Update Prices"          << endl;
    cout << "\t\t\t\t\t\t5. Update Stock"           << endl;
    cout << "\t\t\t\t\t\t6. Check Reviews"          << endl;
    cout << "\t\t\t\t\t\t7. Add Delivery Areas"     << endl;
    cout << "\t\t\t\t\t\t8. Remove Delivery Areas"  << endl;
    cout << "\t\t\t\t\t\t9. Change Password"        << endl;
    cout << "\t\t\t\t\t\t10. Log Out"               << endl;
    cout <<  endl; 
    cout << "\t\t\t\t\t\tPlease Select an Option...";
    cin >> op1;
    return op1;
}
//////Client Menu..................
string Clientmenu()
{
    system ("cls");
    clientheader();
                
    string op2 = "" ;
    cout << endl ;
    cout << "\t\t\t\t\t\t1. View the list of Available Items" << endl;
    cout << "\t\t\t\t\t\t2. Add an item to Cart"              << endl;
    cout << "\t\t\t\t\t\t3. View cart"                        << endl;
    cout << "\t\t\t\t\t\t4. Check Prices"                     << endl;
    cout << "\t\t\t\t\t\t5. Check Stock"                      << endl;
    cout << "\t\t\t\t\t\t6. Review a Product"                << endl;
    cout << "\t\t\t\t\t\t7. Check Delivery Areas"             << endl;
    cout << "\t\t\t\t\t\t8. Print Bill"                       << endl;
    cout << "\t\t\t\t\t\t9. Change Password"                  << endl;
    cout << "\t\t\t\t\t\t10. Log Out"                         << endl;
    cout <<  endl; 
    cout << "\t\t\t\t\t\tPlease Select an Option...";
    cin >> op2;
    return op2;
}
/// Admin Functions..........
void addNewItem(string Items[],int Price[],int Quantity[],string DeliveryArea[],int &productCount,string item, int price, int quantity)  //1
{
    Items[productCount] = item;
    Price[productCount] = price;
    Quantity[productCount] = quantity;
    productCount ++;
}
void delItem(string Items[],int Price[], int Quantity[],string DeliveryArea[], int &productCount, int &del, int &num) //2
{
    for (int i=num-1; i<productCount; i++)
    {
        Items[i] = Items[i + 1];
        Quantity[i] = Quantity[i + 1];
        Price[i] = Price[i + 1];
        DeliveryArea[i] = DeliveryArea[i + 1];
    }
    productCount--;
}
void viewProducts(string Items[],int Price[], int Quantity[],string DeliveryArea[], int &productCount, int &del) //3
{
    for (int i=0 ; i<productCount ; i++)
    {   
        if (Items[i] != "")
        cout << i+1 << "    " << Items[i] << "\t\t\t" << Price[i] << "\t\t" << Quantity[i] << "\t\t\t" << DeliveryArea[i]<< endl;
    }
}
void updatePrices(string Items[],int Price[], int Quantity[],string DeliveryArea[], int &productCount, int &del,int idProduct, int price1) //4
{
    Price[idProduct - 1] =  price1;
}
void updateStock(string Items[],int Price[], int Quantity[],string DeliveryArea[], int &productCount , int &del, int idProduct , int quantity1) //5
{
    Quantity[idProduct - 1] =  quantity1;
}
void checkReview(string Items[],int Price[], int Quantity[],string Reviews[],string DeliveryArea[], int &productCount, int &del, int Rev)//6
{
    cout <<"\t\t\t\t\t\t"<<Reviews[Rev - 1];
}
void addDeliveryArea(string Items[],int Price[], int Quantity[], string DeliveryArea[], int &productCount, int &del,int No,string area)//7
{
    for (int i=0; i<No ; i++)
    {
    DeliveryArea[No - 1] = area;
    productCount ++;
    }
}
void removeDeliveryArea(string Items[],int Price[], int Quantity[], string DeliveryArea[], int &productCount, int &del,int No2)//8
{
    DeliveryArea[No2 - 1] = "";
}
void changePassword(string PasswordDB[], int &usercount, int idx, string currentPass,string newPass)  //9
{
    for (int i=0; i<usercount; i++)
    {
        idx = usercount-1;
    }
    if (currentPass == PasswordDB[idx])
    {   
        cout << "\t\t\t\t\t\tEnter New Password: ";
        cin >> newPass;
        PasswordDB[idx]= newPass;
        cout << "\t\t\t\t\t\tPassword Changed Successfully...";
    }
    else
        cout << "\t\t\t\t\t\tCurrent Password is Not Correct....";
}
/////Client
void addCart(string Items[], int Price[], int Quantity[],string DeliveryArea[], int &productCount, int &del, int &idx1 , string productCart[], int quantityCart[], int priceCart[],int n2,int added,int quant,int cidx,int prc,string name3)
{
    productCart[idx1] = name3;
    quantityCart[idx1] = added;
    priceCart[idx1] = prc;
    Quantity[cidx] = quant - added;
    idx1++;
}
int viewCart(string productCart[], int quantityCart[], int &idx1 , int priceCart[], int del)
{
    int bill = 0;
    if( productCart[0] == "" )
    {
        cout <<"\t\t\t\t\t\tThe Cart is Empty..."<<endl;
    }
    else
    {
        cout <<"\t\t\t\t\t\tProduct Name\t\tQuantity\t\tPrice\n";
    for (int i=0; i<idx1 ; i++)
    {
        cout << "\t\t\t\t\t\t"<<productCart[i] << "\t\t\t" << quantityCart[i] << "\t\t\t" << priceCart[i] <<"\n";
        bill += priceCart[i];
    }
    }
    return bill;
}
void checkPrice(string Items[],int Price[], int &productCount)
{
    for (int i=0; i < productCount ; i++)
    {
        cout <<"\t\t\t\t\t\t"<<Items[i]<<"\t\t\t"<<Price[i]<<"\n";
    }

}
void checkStock(string Items[],int Quantity[], int &productCount)
{
    for (int i=0; i < productCount ; i++)
    {
        cout <<"\t\t\t\t\t\t"<<Items[i]<<"\t\t\t"<<Quantity[i]<<"\n";
    }
    
}
void reviewProduct(string Items[],int Price[],int Quantity[],string DeliveryArea[], int &productCount, int &del , string Reviews[],int no, string revi)
{
    for (int i=0; i<no; i++)
    {
        Reviews[no - 1] = revi; 
    }
}
void checkDeliveryArea(string Items[],string DeliveryArea[], int &productCount)
{
    for (int i=0; i < productCount ; i++)
    {
        cout <<"\t\t\t\t\t\t"<<Items[i]<<"\t\t\t"<<DeliveryArea[i]<<"\n";
    }
}
void viewBill(string productCart[], int quantityCart[], int &idx1 , int priceCart[],int &del)
{
    int payableBill = viewCart(productCart, quantityCart, idx1 , priceCart, del);    
    cout << "\n\t\t\t\t\t\t##################################################\n"<< endl;
    cout << "\t\t\t\t\t\tYour total Bill is: " << payableBill;
    cout << endl;
}

/// Sign Up Functions.........
bool contineSignup(string role)
{
    bool signUp = true;
    if(!(role == "Admin" || role == "admin" || role == "Client" || role == "client" ))
    {
        cout << "\t\t\t\t\t\tInvalid Role\n";
        cout << "\t\t\t\t\t\tPress Any Key to Go Back to Main Page: ";
        signUp = false;
        getch ();
    }
    return signUp;
}

void createUser(string NameDB[],string PasswordDB[] , string RoleDB[] ,int &usercount,string username,string password ,string role)
{
    NameDB[usercount] = username;
    PasswordDB[usercount] = password ;
    RoleDB[usercount] = role;
    usercount ++ ;
    cout << "\t\t\t\t\t\tPress Any Key to Go Back to Main Page: ";
    getch ();
}

bool checkUserName(string name,string NameDB[], int usercount)
{
    for(int i = 0; i<= usercount; i++)
    {
        if(name == NameDB[i])
            return true;
    }
    return false;
}

// Header
void header()
{
cout <<"     ____  _                   __  __                                                   _     ____            _                                   "<<endl;
cout <<"    / ___|| |_ ___  _ __ ___  |  \\/  | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  / ___| _   _ ___| |_ ___ _ __ ___                   "<<endl;
cout <<"    \\___ \\| __/ _ \\|  __/ _ \\ | |\\/| |/ _  |  _ \\ / _  |/ _  |/ _ \\  _   _ \\ / _ \\  _ \\| __| \\___ \\| | | / __| __/ _ \\  _   _ \\     "<<endl;
cout <<"     ___) | || (_) | | |  __/ | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_   ___) | |_| \\__ \\ ||  __/ | | | | |                "<<endl;
cout <<"    |____/ \\__\\___/|_|  \\___| |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__| |____/ \\__, |___/\\__\\___|_| |_| |_|      "<<endl;
cout <<"                                                        |___/                                       |___/                                          "<<endl;
cout << endl << endl;
cout << endl << endl;
}


// MainPage header
string mainpage()
{
    cout <<"\t\t\t\t\t\t  _     _     ___   ____ ___ _   _           "<<endl;
    cout <<"\t\t\t\t\t\t / |   | |   / _ \\ / ___|_ _| \\ | |          "<<endl;
    cout <<"\t\t\t\t\t\t | |   | |  | | | | |  _ | ||  \\| |          "<<endl;
    cout <<"\t\t\t\t\t\t | |_  | |__| |_| | |_| || || |\\  |          "<<endl;
    cout <<"\t\t\t\t\t\t |_(_) |_____\\___/ \\____|___|_| \\_|  _       "<<endl;
    cout <<"\t\t\t\t\t\t|___ \\    / ___|(_) __ _ _ __   | | | |_ __  "<<endl;
    cout <<"\t\t\t\t\t\t  __) |   \\___ \\| |/ _` | '_ \\  | | | | '_ \\ "<<endl;
    cout <<"\t\t\t\t\t\t / __/ _   ___) | | (_| | | | | | |_| | |_) |"<<endl;
    cout <<"\t\t\t\t\t\t|_____(_) |____/|_|\\__, |_| |_|  \\___/| .__/ "<<endl;
    cout <<"\t\t\t\t\t\t _____    _____    |___/              |_|    "<<endl;
    cout <<"\t\t\t\t\t\t|___ /   | ____|_  _(_) |_                   "<<endl;
    cout <<"\t\t\t\t\t\t  |_ \\   |  _| \\ \\/ / | __|                  "<<endl;
    cout <<"\t\t\t\t\t\t ___) |  | |___ >  <| | |_                   "<<endl;
    cout <<"\t\t\t\t\t\t|____(_) |_____/_/\\_\\_|\\__|                  "<<endl;
    cout <<"\t\t\t\t\t\t                                             "<<endl;
    cout << endl << endl;
    cout <<"\t\t\t\t\t\tEnter your Option: ";
    string option;
    cin >> option;
    return option;
}
void adminheader()
{
    cout<<"\t\t\t\t\t  ___ _________  ________ _   _  "<<endl;
    cout<<"\t\t\t\t\t / _ \\|  _  \\  \\/  |_   _| \\ | | "<<endl;
    cout<<"\t\t\t\t\t/ /_\\ \\ | | | .  . | | | |  \\| | "<<endl;
    cout<<"\t\t\t\t\t|  _  | | | | |\\/| | | | | . ` | "<<endl;
    cout<<"\t\t\t\t\t| | | | |/ /| |  | |_| |_| |\\  | "<<endl;
    cout<<"\t\t\t\t\t\\_| |_/___/ \\_|  |_/\\___/\\_| \\_/ "<<endl;                                                     

}
void clientheader()
{
cout<< "\t\t\t\t\t                                         "<<endl;
cout<< "\t\t\t\t\t _____  _     _____ _____ _   _ _____    "<<endl;
cout<< "\t\t\t\t\t/  __ \\| |   |_   _|  ___| \\ | |_   _|   "<<endl;
cout<< "\t\t\t\t\t| /  \\/| |     | | | |__ |  \\| | | |     "<<endl;
cout<< "\t\t\t\t\t| |    | |     | | |  __|| . ` | | |     "<<endl;
cout<< "\t\t\t\t\t| \\__/\\| |_____| |_| |___| |\\  | | |     "<<endl;
cout<< "\t\t\t\t\t \\____/\\_____/\\___/\\____/\\_| \\_/ \\_/     "<<endl;
cout<< "\t\t\t\t\t                                         "<<endl;

}
void storeData(string NameDB[100],string PasswordDB[100],string RoleDB[100],int usercount)
{
    fstream file;
    string data="";
    file.open("User.txt",ios::out);
    for (int x=0; x < usercount; x++)
    {
        data+= NameDB[x] + ", " + PasswordDB[x] + ", " + RoleDB[x] + "\n";
        file << data;
        data = "";
    }
    file.close();
}