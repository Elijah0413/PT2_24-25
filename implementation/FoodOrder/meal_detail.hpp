#ifndef MEAL_DETAIL_H
#define MEAL_DETAIL_H

#define MAX_NUMBER 100
#include <string>
using namespace std;
class Meal
{
    private:
    string Menu[MAX_NUMBER];
    double price[MAX_NUMBER];
    string description[MAX_NUMBER];
    string ingredient[MAX_NUMBER];
    string availability[MAX_NUMBER];
    int number;
    public:
    Meal(int num);

    //mutator method
    void setMeal(int num);
    void setPrice(int num);
    void setDescription(int num);
    void setIngredient(int num);
    void setAvailability(int num);

    //accessor method
    string getMeal(int num)const;
    double getPrice(int num)const;
    string getDescription(int num)const;
    string getIngredient(int num)const;
    string getAvailability(int num)const;
    void displayMenu(int num)const;
};

#endif