#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

using namespace std;


class Account
{
    public:
      int type ;// 1 for humans , 2 for monsters
      int ID=0 ;
      // ID of guest , initialized 0 to help in user fetching and prevention of overwriting process
      string name ;// User name
      int Sign_In(int x); // Accessed In case the guest is old
      void Sign_up(); // Accessed once only if the guest is new
      void Display_Profile();// Used for testing purpose (not found in program)

};

#endif // ACCOUNT_H
