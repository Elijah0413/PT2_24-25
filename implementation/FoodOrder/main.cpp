#include <iostream>
#include <iomanip>
#include <fstream>
#include "meal_detail.hpp"
#include "login_detail.hpp"
#include "payment_detail.hpp"
#define MAX_NUMBER 100
using namespace std;

int main(){
    string desciptions,ingredients;
    double prices;
    int num,loginAnswer,adminChoice,dishNo,customerChoice,numOrder=0;
    char ans = 'F';
    string Menu;
    Meal meals(num);
    int order[MAX_NUMBER];
    Payment pay;
    Login user;
    double sum=0;
    char answerBack='P';
    

Login:
{
    cout<<"----------------------------------------"<<endl;
    cout<<"  Restaurant ordering//payment system"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"\n\n\t 1. Merchant"<<endl;
    cout<<"\t 2. Customer"<<endl;
    cout<<"\t 3. Exit"<<endl;
    cout<<"\nEnter the action to perform : ";
    cin>>loginAnswer;
    cout<<endl;
    system("cls");

    switch (loginAnswer)
    {
    case 1:
        goto adminLogin;
        break;
    case 2:
        goto customerLogin;
        break;
    default:
        goto end;
    }
}
    goto end;


    //Log in as admin
adminLogin:
    {
        bool loginAnswer=false;
        user.userInput();
        loginAnswer=user.adminValidityCheck();
        if(!loginAnswer)
        {
            cout<<endl;
            cout<<endl;
            goto adminLogin;
        }
        cout<<endl;
        
    }
    goto adminMenu;

adminMenu:
    {
        char answerBack='P';
        cout<<right;
        cout<<setw(15)<<"Menu"<<endl;
        cout<<endl;
        cout<<left;
        cout<<"1. Modifying dish detail"<<endl;
        cout<<"2. Modifying customer type"<<endl;
        cout<<"3. Payment detail"<<endl;
        cout<<"4. Menu setup"<<endl;
        cout<<"5. Back the Main Menu"<<endl;
        cout<<"\n\nEnter the action to perform : ";
        cin>>adminChoice;

        switch (adminChoice)
        {
        case 1:
            goto DishModify;
        case 3:
            goto PaymentDetail;
        case 4:
            goto MenuSetup;
            break;
        case 5:
            goto Login;
        default:
            break;
        }
    }
    //Log in as customer
customerLogin:
    {
        bool loginAnswer=false;
        user.userInput();
        loginAnswer=user.customerValidityCheck();
        if(!loginAnswer)
        {
            cout<<endl;
            cout<<endl;
            goto customerLogin;
        }
        cout<<endl;
    }
    goto customerMenu;

customerMenu:
{
    char answerBack='P';
    cout<<right;
    cout<<setw(15)<<"Menu"<<endl;
    cout<<endl;
    cout<<left;
    cout<<"1. Register"<<endl;
    cout<<"2. Making order"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"\n\nEnter the action to perform : ";
    cin>>customerChoice;

    switch (customerChoice)
    {
    case 1:
        goto DishModify;
    case 2:
        goto MakeOrder;
    default:
        goto end;
        break;
    }        
}

MakeOrder:
{
    char orderChoice='Y';
    int mealNo,mealNum;
    for(int i=0;i<num;i++)
    {
        order[i]=0;
    }
    meals.displayMenu(num);
    cout<<endl;
    cout<<endl;
    while(orderChoice=='Y')
    {
        numOrder++;
        cout<<"\nEnter the meal you want to add : ";
        cin>>mealNo;
        cout<<"How many do you want to order "<<meals.getMeal(mealNo-1)<<" : ";
        cin>>mealNum;
        order[mealNo-1]=mealNum;
        cout<<"Do you want to add on something (Y)/(N) : ";
        cin>>orderChoice;
    }
    
}
    goto MealChecking;


MealChecking:
{
    int checkingOption;
    sum=0;
    cout<<"******************************"<<endl;
    cout<<"       Overview Order"<<endl;
    cout<<"******************************"<<endl;
    cout<<"\n\n"<<setw(5)<<"No."<<setw(20)<<"Meal"<<setw(20)<<"Quantity"<<endl;
    for(int i=0;i<=num;i++)
    {
        if(order[i]!=0)
        {
            cout<<setw(5)<<i+1<<setw(20)<<meals.getMeal(i)<<setw(20)<<order[i]<<endl;
            sum+=order[i]*meals.getPrice(i);
        }
        
    }
    cout<<"\n\nEnter 1 : Proceed to Payment "<<endl;
    cout<<"Enter 2 : Exit"<<endl;
    cout<<"\n\nEnter the action to perform : ";
    cin>>checkingOption;
    if(checkingOption==1)
    {
        cout<<"\n\n\n******************************"<<endl;
        cout<<"        Reciept"<<endl;
        cout<<"******************************"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"Total payment : RM"<<sum<<endl;
        pay.displayDetail();
        cout<<endl;
    }else
        goto customerMenu;
}
    goto end;


MenuSetup:
    {
        cout << "\n\n**Menu setup**" << endl;
        cout << "How many meals do you want to add: ";
        cin >> num;
        cin.ignore();
        cout << endl;
        for (int i = 0; i < num; i++) {
            cout << "Meal " << i + 1 << endl;
            meals.setMeal(i);
            meals.setPrice(i);
            meals.setDescription(i);
            meals.setIngredient(i);
            meals.setAvailability(i);
            cout << endl;
        }
        cout << endl;
        cout << "Do you want to add on meal? (Y/F): ";
        cin >> ans;
        cin.ignore();
        while (ans == 'Y') {
            meals.setMeal(num);
            meals.setPrice(num);
            meals.setDescription(num);
            meals.setIngredient(num);
            meals.setAvailability(num);
            num++;
            cout << "Do you want to add on meal? (Y/F): ";
            cin >> ans;
            cin.ignore();
        }
        cout << endl;
        meals.displayMenu(num);
        cout<<endl;
        cout<<endl;
        cout<<"Enter (Y) to get back to main menu : ";
        cin>>answerBack;
        if(answerBack=='Y')
        {
            goto adminMenu;
        }else{
            goto end;
        }

    }

    goto adminMenu; 

DishModify:
    {
        char option;
        cout<<"******************************"<<endl;
        cout<<"   MODIFYING DISH DETAIL"<<endl;
        cout<<"******************************"<<endl;
        cout<<"\n\nEnter The Dish No. : ";
        cin>>dishNo;
        cout<<"\n\n******************************"<<endl;
        cout<<"\n\nDish No. : "<<dishNo<<endl;
        cout<<"Dish Name : "<<meals.getMeal(dishNo-1)<<endl;
        cout<<"Price : "<<meals.getPrice(dishNo-1)<<endl;
        cout<<"Available : "<< meals.getAvailability(dishNo-1)<<endl;
        cout<<"\n\n******************************"<<endl;
        cout<<"\tWhich detail need to be edit?"<<endl;
        cout<<"\t\tName(N)"<<endl;
        cout<<"\t\tPrice(P)"<<endl;
        cout<<"\t\tAvailability(A)"<<endl;
        cout<<"\nEnter your option -> ";
        cin>>option;
        cin.ignore();

        switch (option)
        {
        case 'N':
            meals.setMeal(dishNo-1);
            break;
        case 'O':
            meals.setPrice(dishNo-1);
            break;
        case 'A':
            meals.setAvailability(dishNo-1);
            break;
        default:
            break;
        }
        cout<<endl;
        cout<<"Changed saved!"<<endl;
        meals.displayMenu(num);
        cout<<endl;
        cout<<endl;
        cout<<"Enter (Y) to get back to main menu : ";
        cin>>answerBack;
        if(answerBack=='Y')
        {
            goto adminMenu;
        }else{
            goto end;
        }
    }
    goto adminMenu;

PaymentDetail:
    {
        char paymentOption;
        pay.displayDetail();
        cout<<"\n\n\nWhich part need to edit?"<<endl;
        cout<<"Bank Num(B)"<<endl;
        cout<<"TNG Num(T)"<<endl;
        cout<<"QR Code(Q)"<<endl;
        cout<<"\n\nEnter your option ->";
        cin>>paymentOption;
        switch (paymentOption)
        {
        case 'B':
            pay.setBank();
            break;
        case 'T':
            pay.setTNG();
            break;
        case 'Q':
            pay.setQR();
            break;   
        default:
            break;
        }

        cout<<endl;
        cout<<endl;
        cout<<"Enter (Y) to get back to main menu : ";
        cin>>answerBack;
        if(answerBack=='Y')
        {
            goto adminMenu;
        }else{
            goto end;
        }
    }
    goto adminMenu;
end:
    {
        system("pause");
        return 0;
    }
    
}
