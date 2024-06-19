#ifndef PAYMENT_DETAIL_H
#define PAYMENT_DETAIL_H
#include <string>
using namespace std;

class Payment
{
    private:
    string bankNum;
    string tngNum;
    string qrPath;
    public:
    Payment();
    void setBank();
    void setTNG();
    void setQR();
    string getBank()const;
    string getTNG()const;
    string getQR()const;
    void displayDetail()const;
};

#endif