#include <iostream>
#include <string>
#include <iomanip>
#include "meal_detail.hpp"
using namespace std;

Meal::Meal(int num):number(num){}
void Meal::setMeal(int num)
{
    string meals;
    cout<<"Enter the meal to be added : ";
    getline(cin,meals);
    Menu[num]=meals;
}

void Meal::setPrice(int num)
{
    double prices;
    cout<<"Enter the price of the meal : ";
    cin>>prices;
    price[num]=prices;
    cin.ignore();
}

void Meal::setDescription(int num)
{
    string descriptions;
    cout<<"Enter the description of the meal : ";
    getline(cin,descriptions);
    description[num]=descriptions;
}

void Meal::setIngredient(int num)
{
    string ingredients;
    cout<<"Enter the ingredient of the meal : ";
    getline(cin,ingredients);
    ingredient[num]=ingredients;
}

void Meal::setAvailability(int num)
{
    string available;
    cout<<"The meal is available? : ";
    getline(cin,available);
    availability[num]=available;
}


string Meal::getMeal(int num) const
{
    return Menu[num];
}

string Meal::getDescription(int num) const
{
    return description[num];
}

string Meal::getIngredient(int num) const
{
    return ingredient[num];
}

double Meal::getPrice(int num) const
{
    return price[num];
}

string Meal::getAvailability(int num) const
{
    return availability[num];
}

void Meal::displayMenu(int num)const
{
    string menu,descriptions,ingredients,availabilities;
    double prices;
    cout << "**Updated Menu**" << endl;
    cout << left;
    cout << setw(10) << "No." << setw(20) << "Meal name" << setw(15) << "Price($)" <<setw(30)<<"Description"<<setw(30)<<"Ingredients"<<setw(20)<<"Availability"<<endl;
    for (int i = 0; i < num; i++) {
        menu=Menu[i];
        prices = price[i];
        descriptions = description[i];
        ingredients = ingredient[i];
        availabilities = availability[i];
        cout << left;
        cout << setw(10) << i + 1 << setw(20) << menu << setw(15) << prices <<setw(30)<<descriptions<<setw(30)<<ingredients<<setw(20)<<availabilities<< endl;
    }
}