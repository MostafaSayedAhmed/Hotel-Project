#include "Account.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

 int Account :: Sign_In()
 {
     int x=0;
     int flag =0;
     cout << "Enter your ID please: ";
     cin >> x;
     if (x == ID)
     {
       flag = 1;
     }
     else
     {
       flag = 0;
       cout << "\nInvalid ID"<<endl;
     }
     return flag;
 }
  void Account :: Sign_up()
  {   srand(time(0));
      cout<<"For human services , type h. For monster services , type m :";
      cin >> type ;
      cout << "Enter your name please :";
      cin >> name;
      ID = rand() % 9999;
      cout << endl <<"Here is your ID : "<<ID<<endl;
  }
  void Account :: Display_Profile()
  {
      cout << "\nYour type sir is ";
      if(type == 'h')
        cout << "Human";
      else
        cout << "Monster";
      cout << "\nYour name sir is "<<name;
      cout << "\nYour ID sir is "<<ID;
  }
