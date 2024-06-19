#include <iostream>
#include <fstream>
#include "login_detail.hpp"
using namespace std;

Login::Login()
{
    userID=0;
    userPassword=0;
    userIndex=0;
}

void Login::userInput()
{
    int id,pass;
    cout<<"------------------------------"<<endl;
    cout<<"       Merchant LOG IN"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"\n\nPlease enter your ID : ";
    cin>>id;
    cin.ignore();
    userID=id;
    cout<<"\n\nPlease enter your password : ";
    cin>>pass;
    cin.ignore();
    cout<<endl;
    cout<<endl;
    userPassword=pass;
}

bool Login::adminValidityCheck()const
{
    bool validityID=false,validityPass=false;
    fstream adminID("adminList.txt",ios::in);
    fstream adminPass("adminPass.txt",ios::in);
    int tempID,tempPass,num=0;
    while (!adminID.eof())
    {
        adminID>>tempID;
        if(tempID==userID)
        {
            validityID=true;
            break;
        }
        num++;
    }

    if(validityID)
    {
        for(int i=0;i<=num;i++)
        {
            adminPass>>tempPass;
        }
        if(tempPass==userPassword)
        {
            validityPass=true;
        }else{
            cout<<"Wrong userID/Password!"<<endl;
            return false;
        }
    }else{
        cout<<"Wrong userID/Password!"<<endl;
        return false;
    }

    if(validityPass==true)
    {
        cout<<"Success Login"<<endl;
        return true;
    }
    return false;
}

bool Login::customerValidityCheck()const
{
    bool validityID=false,validityPass=false;
    fstream customerID("customerList.txt",ios::in);
    fstream customerPass("customerPass.txt",ios::in);
    int tempID,tempPass,num=0;
    while (!customerID.eof())
    {
        customerID>>tempID;
        if(tempID==userID)
        {
            validityID=true;
            break;
        }
        num++;
    }

    if(validityID)
    {
        for(int i=0;i<=num;i++)
        {
            customerPass>>tempPass;
        }
        if(tempPass==userPassword)
        {
            validityPass=true;
        }else{
            cout<<"Wrong userID/Password!"<<endl;
            return false;
        }
    }else{
        cout<<"Wrong userID/Password!"<<endl;
        return false;
    }

    if(validityPass==true)
    {
        cout<<"Success Login"<<endl;
        return true;
    }
    return false;
}