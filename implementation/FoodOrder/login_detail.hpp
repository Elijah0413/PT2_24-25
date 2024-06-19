#ifndef LOGIN_DETAIL_H
#define LOGIN_DETAIL_H
using namespace std;

class Login{
    private:
    int userID;
    int userPassword;
    int userIndex;
    public:
    Login();
    
    //mutator method
    void userInput();
    bool adminValidityCheck()const;
    bool customerValidityCheck()const;
};

#endif