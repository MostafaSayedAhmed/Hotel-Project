#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

using namespace std;


class Account
{
    public:
        char type ;
       int ID=0 ;
      string name ;
      int Sign_In();
      void Sign_up();
      void Display_Profile();
    protected:

    private:
};

#endif // ACCOUNT_H
