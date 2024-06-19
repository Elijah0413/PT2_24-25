#include <iostream>
#include "payment_detail.hpp"
using namespace std;

Payment::Payment()
{
    bankNum="24196210310";
    tngNum="01116596391";
    qrPath="https://nkf.org.my/wp-content/uploads/2020/10/tngo-ewallet.jpg";
    
}

void Payment::setBank()
{
    cout<<"\nEnter the new bank number : ";
    cin>>bankNum;
    cout<<endl;
    cin.clear();
}

void Payment::setTNG()
{
    cout<<"\nEnter the new TNG number : ";
    cin>>tngNum;
    cout<<endl;
    cin.clear();
}

void Payment::setQR()
{
    cout<<"\nEnter the new path of QR code : ";
    cin>>qrPath;
    cout<<endl;
    cin.clear();
}

string Payment::getBank()const
{
    return bankNum;
}

string Payment::getTNG()const
{
    return tngNum;
}

string Payment::getQR()const
{
    return qrPath;
}

void Payment::displayDetail()const
{
    string bank,tng,qr;
    bank=getBank();
    tng=getTNG();
    qr=getQR();
    cout<<endl;
    cout<<"******************************"<<endl;
    cout<<"       PAYMENT DETAIL"<<endl;
    cout<<"******************************"<<endl;
    cout<<"\n\nBank num : "<<bank<<endl;
    cout<<"TNG num : "<<tng<<endl;
    cout<<"QR CODE : "<<qrPath<<endl;
    system("start https://nkf.org.my/wp-content/uploads/2020/10/tngo-ewallet.jpg");
}