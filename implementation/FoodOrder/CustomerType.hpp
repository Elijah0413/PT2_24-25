#ifndef CUSTOMERTYPE_HPP
#define CUSTOMERTYPE_HPP

#include <string>
using namespace std;
class CustomerType {
private:
    string type;
    double discount;  // Discount percentage

public:
    CustomerType();
    CustomerType(const string& type, double discount);
    
    void setType(const string& type);
    string getType() const;
    
    void setDiscount(double discount);
    double getDiscount() const;
};

#endif
