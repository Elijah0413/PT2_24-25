#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_NUMBER = 100;

class Customer {
private:
    string name;
    string phone;
    string customerId; // Using name as customer ID
    string password;   // Using phone number as password
public:
    Customer();
    Customer(const string& newName, const string& newPhone); // Constructor for existing customers
    void userInput();
    string getName() const;
    string getPhone() const;
    string getCustomerId() const;
    string getPassword() const;
    void display() const;
};

class Meal {
private:
    string Menu[MAX_NUMBER];
    double price[MAX_NUMBER];
    string description[MAX_NUMBER];
    string ingredient[MAX_NUMBER];
    string availability[MAX_NUMBER];
    int number;
public:
    Meal();
    void setMeal(int index);
    void setPrice(int index);
    void setDescription(int index);
    void setIngredient(int index);
    void setAvailability(int index);
    string getMeal(int index) const;
    double getPrice(int index) const;
    string getDescription(int index) const;
    string getIngredient(int index) const;
    string getAvailability(int index) const;
    void displayMenu() const;
    void initializeMenu();
    int getNumber() const;
    void increaseNumber();
    void modifyDish();
};

class Payment {
private:
    string bankNum;
    string tngNum;
    string qrPath;
public:
    Payment();
    void setBank();
    void setTNG();
    void setQR();
    string getBank() const;
    string getTNG() const;
    string getQR() const;
    void displayDetail() const;
};

class Login {
private:
    string userID;   // Customer ID (name)
    string password; // Customer password (phone number)
public:
    Login();
    void userInput();
    bool adminValidityCheck() const;
    bool customerValidityCheck() const;
};

// Function prototypes
void adminMenu(Meal& meals, Payment& pay, Login& user, Customer customers[], int& numCustomers);
void customerMenu(Meal& meals, Payment& pay, Login& user, Customer customers[], int numCustomers);
void dishModify(Meal& meals);
void menuSetup(Meal& meals);
void paymentDetail(Payment& pay);
void makeOrder(Meal& meals, int order[], int& numOrder, double& sum);
void reviewOrder(Meal& meals, int order[], int& numOrder, double& sum);
void checkout(Meal& meals, Payment& pay, int order[], int& numOrder, double& sum);
Customer* searchCustomerByName(Customer customers[], int size, const string& name);
Customer* searchCustomerByPhone(Customer customers[], int size, const string& phone);
void manageCustomers(Customer customers[], int& numCustomers);

// Main function
int main() {
    Meal meals;
    Payment pay;
    Login user;
    Customer customers[MAX_NUMBER];
    int numCustomers = 0;

    // Predefined existing customers
    customers[numCustomers++] = Customer("Ali", "0165093690");
    customers[numCustomers++] = Customer("Ahming", "0189620694");
    customers[numCustomers++] = Customer("Abu", "01113142927");

    int userType;
    do {
        cout << "Welcome to the Restaurant Management System" << endl;
        cout << "Are you an admin or a customer? (0 for exit, 1 for admin, 2 for customer): ";
        cin >> userType;

        if (userType == 0) {
            cout << "Logging out..." << endl;
            break;
        }

        user.userInput();
        if (userType == 1) {
            if (user.adminValidityCheck()) {
                adminMenu(meals, pay, user, customers, numCustomers);
            } else {
                cout << "Invalid admin credentials!" << endl;
            }
        } else if (userType == 2) {
            if (user.customerValidityCheck()) {
                customerMenu(meals, pay, user, customers, numCustomers);
            } else {
                cout << "Invalid customer credentials!" << endl;
            }
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);

    return 0;
}

// Customer class member function definitions
Customer::Customer() : name(""), phone(""), customerId(""), password("") {}

Customer::Customer(const string& newName, const string& newPhone) : name(newName), phone(newPhone), customerId(newName), password(newPhone) {}

void Customer::userInput() {
    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter phone number: ";
    getline(cin, phone);

    // Assign name as customer ID and phone number as password
    customerId = name;
    password = phone;
}

string Customer::getName() const {
    return name;
}

string Customer::getPhone() const {
    return phone;
}

string Customer::getCustomerId() const {
    return customerId;
}

string Customer::getPassword() const {
    return password;
}

void Customer::display() const {
    cout << "Customer ID: " << setw(15) << customerId << " Phone Number: " << phone << endl;
}

// Meal class member function definitions
Meal::Meal() : number(0) {}

void Meal::setMeal(int index) {
    string newName;
    cout << "Enter the name of the dish: ";
    cin.ignore();
    getline(cin, newName);
    Menu[index] = newName;
}

void Meal::setPrice(int index) {
    double newPrice;
    cout << "Enter the price of the dish: ";
    cin >> newPrice;
    price[index] = newPrice;
}

void Meal::setDescription(int index) {
    string newDesc;
    cout << "Enter the description of the dish: ";
    cin.ignore();
    getline(cin, newDesc);
    description[index] = newDesc;
}

void Meal::setIngredient(int index) {
    string newIngr;
    cout << "Enter the ingredients of the dish: ";
    getline(cin, newIngr);
    ingredient[index] = newIngr;
}

void Meal::setAvailability(int index) {
    int newAvailability;
    cout << "Is the dish available? (Yes/No): ";
    cin >> newAvailability;
    availability[index] = newAvailability;
}

string Meal::getMeal(int index) const {
    return Menu[index];
}

double Meal::getPrice(int index) const {
    return price[index];
}

string Meal::getDescription(int index) const {
    return description[index];
}

string Meal::getIngredient(int index) const {
    return ingredient[index];
}

string Meal::getAvailability(int index) const {
    return availability[index];
}

void Meal::displayMenu() const {
    cout << setw(5) << "No." << setw(20) << "Name" << setw(10) << "Price" << setw(15) << "Availability" << setw(20) << "Description" << setw(20) << "Ingredients" << endl;
    cout << setw(5) << "===" << setw(20) << "====" << setw(10) << "=====" << setw(15) << "============" << setw(20) << "=====================" << setw(20) << "=====================" << endl;
    for (int i = 0; i < number; ++i) {
        cout << setw(5) << i + 1 << setw(20) << Menu[i] << setw(10) << fixed << setprecision(2) << price[i] << setw(15) << availability[i] << setw(20) << description[i] << setw(20) << ingredient[i] << endl;
    }
}

void Meal::initializeMenu() {
    string drinks[] = {"Coffee", "Tea", "Juice", "Soda", "Water"};
    double drinksPrice[] = {2.50, 2.00, 3.00, 1.50, 1.00};
    string drinksDesc[] = {"Hot coffee", "Hot tea", "Fresh juice", "Carbonated soda", "Bottled water"};
    string drinksIngr[] = {"Coffee beans", "Tea leaves", "Fruit", "Soda water", "Water"};

    string snacks[] = {"Sandwich", "Salad", "Chips", "Cookies", "Fruit"};
    double snacksPrice[] = {5.00, 4.50, 1.75, 1.25, 2.00};
    string snacksDesc[] = {"Chicken sandwich", "Fresh salad", "Potato chips", "Chocolate cookies", "Fresh fruit"};
    string snacksIngr[] = {"Bread, chicken, lettuce", "Lettuce, tomatoes, dressing", "Potatoes, oil, salt", "Flour, sugar, chocolate chips", "Fresh fruit"};

    for (int i = 0; i < 5; ++i) {
        Menu[number] = drinks[i];
        price[number] = drinksPrice[i];
        description[number] = drinksDesc[i];
        ingredient[number] = drinksIngr[i];
        availability[number] = "1"; // Default availability set to "Yes" for drinks
        number++;

        Menu[number] = snacks[i];
        price[number] = snacksPrice[i];
        description[number] = snacksDesc[i];
        ingredient[number] = snacksIngr[i];
        availability[number] = "1"; // Default availability set to "Yes" for snacks
        number++;
    }
}

int Meal::getNumber() const {
    return number;
}

void Meal::increaseNumber() {
    number++;
}

void Meal::modifyDish() {
    int choice;
    do {
        cout << "Which dish number to modify? (0 to exit): ";
        cin >> choice;
        if (choice > 0 && choice <= number) {
            cout << "Modifying dish: " << Menu[choice - 1] << endl;
            cout << "1. Modify Name" << endl;
            cout << "2. Modify Price" << endl;
            cout << "3. Modify Description" << endl;
            cout << "4. Modify Ingredients" << endl;
            cout << "5. Modify Availability" << endl;
            cout << "6. Exit" << endl;
            int option;
            cin >> option;
            switch (option) {
                case 1:
                    setMeal(choice - 1);
                    break;
                case 2:
                    setPrice(choice - 1);
                    break;
                case 3:
                    setDescription(choice - 1);
                    break;
                case 4:
                    setIngredient(choice - 1);
                    break;
                case 5:
                    setAvailability(choice - 1);
                    break;
                case 6:
                    cout << "Exiting modification..." << endl;
                    break;
                default:
                    cout << "Invalid option. Please try again." << endl;
                    break;
            }
        } else if (choice != 0) {
            cout << "Invalid dish number. Please try again." << endl;
        }
    } while (choice != 0);
}

// Payment class member function definitions
Payment::Payment() : bankNum(""), tngNum(""), qrPath("") {}

void Payment::setBank() {
    cout << "Enter bank account number: ";
    cin.ignore();
    getline(cin, bankNum);
}

void Payment::setTNG() {
    cout << "Enter Touch 'n Go number: ";
    cin.ignore();
    getline(cin, tngNum);
}

void Payment::setQR() {
    cout << "Enter QR path: ";
    cin.ignore();
    getline(cin, qrPath);
}

string Payment::getBank() const {
    return bankNum;
}

string Payment::getTNG() const {
    return tngNum;
}

string Payment::getQR() const {
    return qrPath;
}

void Payment::displayDetail() const {
    cout << "Bank Account: " << bankNum << endl;
    cout << "Touch 'n Go: " << tngNum << endl;
    cout << "QR Path: " << qrPath << endl;
}

// Login class member function definitions
Login::Login() : userID(""), password("") {}

void Login::userInput() {
    cout << "Enter user ID (Customer ID): ";
    cin.ignore();
    getline(cin, userID);
    cout << "Enter password (Phone number): ";
    getline(cin, password);
}

bool Login::adminValidityCheck() const {
    return (userID == "admin" && password == "adminpass");
}

bool Login::customerValidityCheck() const {
    // Example: Verify against existing customer list
    return true; // Placeholder for validation logic with actual customer data
}

// Function definitions for admin menu operations
void adminMenu(Meal& meals, Payment& pay, Login& user, Customer customers[], int& numCustomers) {
    int choice;
    do {
        cout << "\n--- Admin Menu ---" << endl;
        cout << "1. Setup Menu" << endl;
        cout << "2. Modify Menu" << endl;
        cout << "3. View Customers" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                menuSetup(meals);
                break;
            case 2:
                dishModify(meals);
                break;
            case 3:
                manageCustomers(customers, numCustomers);
                break;
            case 4:
                cout << "Exiting admin menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);
}

void menuSetup(Meal& meals) {
    meals.initializeMenu();
    cout << "Menu has been set up." << endl;
}

void dishModify(Meal& meals) {
    meals.modifyDish();
}

void manageCustomers(Customer customers[], int& numCustomers) {
    cout << "\n--- Customer List ---" << endl;
    for (int i = 0; i < numCustomers; ++i) {
        customers[i].display();
    }
}

// Function definitions for customer menu operations
void customerMenu(Meal& meals, Payment& pay, Login& user, Customer customers[], int numCustomers) {
    int choice;
    int order[MAX_NUMBER]; // Array to store order indices
    int numOrder = 0;      // Number of items in current order
    double sum = 0.0;      // Total sum of the order

    do {
        cout << "\n--- Customer Menu ---" << endl;
        cout << "1. View Menu" << endl;
        cout << "2. Make Order" << endl;
        cout << "3. Review Order" << endl;
        cout << "4. Checkout" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                meals.displayMenu();
                break;
            case 2:
                makeOrder(meals, order, numOrder, sum);
                break;
            case 3:
                reviewOrder(meals, order, numOrder, sum);
                break;
            case 4:
                checkout(meals, pay, order, numOrder, sum);
                break;
            case 5:
                cout << "Exiting customer menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);
}

void makeOrder(Meal& meals, int order[], int& numOrder, double& sum) {
    int dishIndex;
    do {
        bool available = false; // Flag to check if selected dish is available
        meals.displayMenu();
        cout << "Enter dish number to order (0 to exit): ";
        cin >> dishIndex;
        
        if (dishIndex > 0 && dishIndex <= meals.getNumber()) {
            // Check availability of the selected dish
            available = (meals.getAvailability(dishIndex - 1) == "1");
            
            if (available) {
                order[numOrder++] = dishIndex - 1;
                sum += meals.getPrice(dishIndex - 1);
                cout << "Dish added to order." << endl;
            } else {
                cout << "Sorry, this dish is currently unavailable. Please choose another dish." << endl;
            }
        } else if (dishIndex != 0) {
            cout << "Invalid dish number. Please try again." << endl;
        }
    } while (dishIndex != 0);
}

void reviewOrder(Meal& meals, int order[], int& numOrder, double& sum) {
    cout << "--- Your Order ---" << endl;
    if (numOrder == 0) {
        cout << "No items in order." << endl;
    } else {
        cout << setw(5) << "No." << setw(20) << "Name" << setw(10) << "Price" << endl;
        cout << setw(5) << "===" << setw(20) << "====" << setw(10) << "=====" << endl;
        for (int i = 0; i < numOrder; ++i) {
            cout << setw(5) << i + 1 << setw(20) << meals.getMeal(order[i]) << setw(10) << fixed << setprecision(2) << meals.getPrice(order[i]) << endl;
        }
        cout << "Total: " << fixed << setprecision(2) << sum << endl;
    }
}

void checkout(Meal& meals, Payment& pay, int order[], int& numOrder, double& sum) {
    if (numOrder == 0) {
        cout << "No items in order. Please order first." << endl;
    } else {
        cout << "--- Checkout ---" << endl;
        cout << "Your order total: " << fixed << setprecision(2) << sum << endl;
        cout << "Payment options:" << endl;
        cout << "1. Bank Transfer" << endl;
        cout << "2. Touch 'n Go" << endl;
        cout << "3. Scan QR Code" << endl;
        int option;
        cout << "Enter payment option: ";
        cin >> option;
        switch (option) {
            case 1:
                pay.setBank();
                break;
            case 2:
                pay.setTNG();
                break;
            case 3:
                pay.setQR();
                break;
            default:
                cout << "Invalid payment option." << endl;
                break;
        }
        cout << "Payment successful!" << endl;
        numOrder = 0; // Clear order after successful checkout
        sum = 0.0;
    }
}

// Utility functions
Customer* searchCustomerByName(Customer customers[], int size, const string& name) {
    for (int i = 0; i < size; ++i) {
        if (customers[i].getName() == name) {
            return &customers[i];
        }
    }
    return nullptr;
}

Customer* searchCustomerByPhone(Customer customers[], int size, const string& phone) {
    for (int i = 0; i < size; ++i) {
        if (customers[i].getPhone() == phone) {
            return &customers[i];
        }
    }
    return nullptr;
}

