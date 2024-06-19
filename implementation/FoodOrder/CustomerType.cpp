#include "CustomerType.hpp"
using namespace std;
CustomerType::CustomerType() : type("Regular"), discount(0.0) {}

CustomerType::CustomerType(const string& type, double discount) : type(type), discount(discount) {}

void CustomerType::setType(const string& type) {
    this->type = type;
}

string CustomerType::getType() const {
    return type;
}
