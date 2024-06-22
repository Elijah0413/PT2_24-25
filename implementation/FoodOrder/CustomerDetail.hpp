#ifndef CUSTOMER_DETAIL_HPP
#define CUSTOMER_DETAIL_HPP
using namespace std;
#include <string>

class Customer {
public:
    void registerCustomer();

private:
    string name;
    string phoneNo;
    string gender;
    string email;
    string password;
};

#endif // CUSTOMER_DETAIL_HPP
