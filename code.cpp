#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

#define reset   "\x1B[0m"
#define red     "\x1B[31m"
#define green   "\x1B[32m"
#define yellow  "\x1B[33m"
#define blue    "\x1B[34m"
#define magenta "\x1B[35m"
#define cyan    "\x1B[36m"
#define white   "\x1B[37m"

int main();
void registeer();
void login();
void visitor_menu();
void organiser_menu();

string username , password , company , name , surname ;

void registeer()
{
    cout<<white;
    cout<<"Enter your name:";
    cin>>name;
    cout<<"Enter your surname:";
    cin>>surname;
    cout<<"Enter your password:";
    cin>>password;
    if(password.length() < 8)
    {
        cout<<red<<"Password length should be at least 8 characters,try again"<<endl;
        sleep(1);
        system("clear");
        registeer();
    }
    else
    {
        cout<<"Enter your company name:";
        cin>>company;
        cout<<"Enter your username:";
        cin>>username;
        ifstream filein(username + "data.txt");
        if(!filein.is_open())
        {
            ofstream file(username + "data.txt");
            file << name << " " << surname << " " << password << " " << company << " " << username;
            file.close();
            cout<<green<<"You have succesfully created an account,you can login now"<<endl;
            sleep(1);
            main();
        }
        else
        {
        cout<<red<<"An account under this  username is already up"<<endl;
        sleep(1);
        main();
        }
    }
}

void login()
{
    string nm,sn,pw,cm,un;
    cout<<"Enter your username:";
    cin>>username;
    cout<<"Enter your password:";
    cin>>password;
    ifstream filein(username + "data.txt");
    if(!filein.is_open())
    {
        cout<<red<<"It appears that an account under this username is not found,you can try registering a new account"<<endl;
        sleep(1);
        system("clear");
        main();
    }
    while(filein >> nm >> sn >> pw >> cm >> un)
    {
        if(un == username && pw == password)
        {
            cout<<green<<"You have succesfully logged in your account"<<endl;
            sleep(1);
            system("clear");
            organiser_menu();
        }
        else
        {
            cout<<red<<"Wrong credentials."<<endl;
            sleep(1);
            system("clear");
            login();
        }
    }
}

void organiser_menu()
{
    int r;
    cout<<white;
    cout<<"[1] Login"<<endl;
    cout<<"[2] Register"<<endl;
    cout<<"Enter an option:";
    cin>>r;
    switch(r)
    {
        case 1 : login(); break;
        case 2 : registeer(); break;
        default : cout<<red<<"Enter a valid option."<<endl; sleep(1); system("clear"); main();
    }

}

void visitor_menu()
{

}

int main()
{
    int x;
    system("clear");
    cout<<white;
    cout<<" GUESS event manager"<<endl;
    cout<<endl;
    cout<<"Are you a visitor or an event organiser?"<<endl;
    cout<<"[1] Visitor"<<endl;
    cout<<"[2] Organiser"<<endl;
    cout<<"Select an option:";
    cin>>x;
    switch(x)
    {
        case 1 : cout<<endl; visitor_menu(); break;
        case 2 : cout<<endl; organiser_menu(); break;
        default : cout<<red<<"Enter a valid option."<<endl; sleep(1); system("clear"); main(); 
    }
}
