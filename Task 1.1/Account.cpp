#include "Account.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

 int Account :: Sign_In(int x) // When guest is old and his ID is stored in system
 {
     int flag =0;// Flag is used as return int value which help in main function in sign in/out section
     if (x == ID)// Comparison between stored ID and the entered one
     {
       flag = 1;
     }
     return flag;
 }
  void Account :: Sign_up() // This function is executed only once when guest is new
  {   srand(time(0));
     while(type != 1 && type != 2)// Used to prevent the user from entering other than 'h' or 'm'
      {
      cout<<"1.human services "<<endl<<"2.monster services"<<endl;
      cin >> type ;// Storing type of user
      }
      cout << "Enter your name please :";
      cin >> name;// Storing user name
      ID = rand() % 9999;// Generating a random ID so that no two guests will have the same ID
      cout << endl <<"Here is your ID : "<<ID<<endl;// Printing ID so that user can memorize it
  }
  void Account :: Display_Profile() // used for test purpose nothing more
  {
      cout << "\nYour type sir is ";
      if(type == 1)
        cout << "Human";
      else if(type == 2)
        cout << "Monster";
      cout << "\nYour name sir is "<<name;
      cout << "\nYour ID sir is "<<ID;
  }
