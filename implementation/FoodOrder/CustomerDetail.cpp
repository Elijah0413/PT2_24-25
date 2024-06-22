#include "CustomerDetail.hpp"
#include <iostream>

using namespace std;

void Customer::registerCustomer() {
    int action;
    cout << "PLEASE FILL UP THE INFO NEEDED\n";
    cout << "1. CUSTOMER NAME: ";
    cin >> name;
    cout << "2. CUSTOMER PHONE NO: ";
    cin >> phoneNo;
    cout << "3. CUSTOMER GENDER: ";
    cin >> gender;
    cout << "4. CUSTOMER EMAIL: ";
    cin >> email;
    cout << "5. PASSWORD: ";
    cin >> password;
    cout << "Registration successful!\n";
    
}
