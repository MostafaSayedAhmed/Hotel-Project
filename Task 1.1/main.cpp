#include "Services.h"
#include "Account.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int avaliable_rooms_monsters=15 , avaliable_rooms_humans=5 ;
int flag =0;// Used to check
int x=0;// Used to store id entered by user in sign in section
int check =0;// Used to prevent infinite loop in signing in/up section
int input_dial=0;// Used to access services corresponding to number
int k=0;// The counter of List_of_guest
Services List_of_guest[100];//Defining a list of guests having the maximum possible number of guests
string Pw = "12345";//Password for receptionist access
string trial ;
void customerService();// CustomerService prototype
int main()
{
   while(flag ==0) // Used to make the service loop until receptionist enter 0 at the end
    {
        input_dial=0; // Similar to customer service system
        while(input_dial != 1 && input_dial != 2 && input_dial != 3 ) // Used to prevent customer from entering number other than 1 or 2
        {
            check = 0;
        cout<<"Welcome sir to Transylvania hotel "<<endl;
        cout<<"1.new guests services  "<<endl;
        cout<<"2.old guests services "<<endl;
        cout<<"3.Receptionist"<<endl;
        cin>>input_dial;
        while(check == 0)// Used to prevent repetition of loop for ever if user entered a wrong ID
        {
        if(input_dial == 1 )// New guest section
        {
           for(int i=0;i<100;i++)// Used to prevent Overwriting the other guest accounts
              {
                  if(!List_of_guest[i].ID)// If ID = 0 , means there is no user registered in this element
                  {
                      k=i;
                      List_of_guest[k].Sign_up(); // request name and display ID to memorize it
                      check = 1;
                      break;
                  }
              }
        }
        else if (input_dial == 2) // Old guest section
        {
            x=0;
            cout << "Enter your ID please: ";
            cin >> x;
            for(int i=0;i<100;i++)
              {//Used to fetch for all users and compare the input ID with all the users recorded in the system
                  if(List_of_guest[i].Sign_In(x))// If ID !=0 , then there is user registered in this element
                  {
                      k=i;
                      check = 1;
                      break;
                  }
              }
              if(check ==0)
              {
                  cout<<"\nYou aren't registered in our system ,try new guest option";
                  cout<<" or enter your id again";// This sentence is printed when entered id is wrong or not stored
                  input_dial = 0;
                  check=1;
              }

        }
        else if (input_dial == 3) // Receptionist section
        {
            cout<<"Please enter password for receptionists : ";// For authorization purpose
            cin>>trial;
            if(Pw == trial)// Check if input password is right or not
            {
               cout<<"Access is Granted"<<endl;
               for(int j=0;j<100;j++)
               {
                   if(List_of_guest[j].ID){
                 cout<<"User registration Number :"<<j+1<<endl;// Registration number is element number in the array
                  List_of_guest[j].Display_Profile();
                  cout<<endl;
                   }

               }
                  check = 1;
            }
            else
            {
                cout<<"Access is Denied"<<endl;
                input_dial = 0;
                check = 1;
            }
        }
        }
    }
    while(input_dial)
    customerService();

}
return 0;
}
void customerService()//This function is used for any customer service available
{
    check = 0; // Rest the check for next use
    input_dial =0 ; // Rest input_dial for next use
     while(input_dial != 1 && input_dial != 2 && input_dial != 3 && input_dial != 4)
        {// Used to prevent customer from entering number other than 1 , 2 , 3 or 4
        cout<<"\nWelcome "<<List_of_guest[k].name<<endl;
        cout<<"How can i help you :"<<endl;
        cout<<"1.New reservation"<<endl<<"2.Extend reservation"<<endl;
        cout<<"3.Additional services"<<endl<<"4.Cancel reservation"<<endl;
        cin>>input_dial;
        if(input_dial == 1) // New reservation
        {
            List_of_guest[k].New_rev();
            if(List_of_guest[k].type == 1 && avaliable_rooms_humans < List_of_guest[k].numberofrooms)
            {//Check if available rooms are sufficient for customer request and if he/she was human
                cout<<"\nSorry the number of rooms required isn't available ";
                cout<<"\nPlease change the entered number";
                List_of_guest[k].New_rev();//Perform Reservation process for humans
            }
            else if (List_of_guest[k].type == 2 && avaliable_rooms_monsters < List_of_guest[k].numberofrooms)
            {//Check if available rooms are sufficient for customer request and if it was monster
                cout<<"\nSorry the number of rooms required isn't available ";
                cout<<"\nPlease change the entered number";
                List_of_guest[k].New_rev();//Perform Reservation process for monsters
            }
            // Calculating the remaining available rooms
            if(List_of_guest[k].type == 1)
            {
                avaliable_rooms_humans -= List_of_guest[k].numberofrooms;
            }
            else if (List_of_guest[k].type == 2)
            {
                avaliable_rooms_monsters -=List_of_guest[k].numberofrooms;
            }
        }
       else if(input_dial == 2) // Extend reservation
       {
           List_of_guest[k].Ex_rev();//Perform Reservation extension process
       }
       else if(input_dial == 3) // Additional services
       {
           List_of_guest[k].Add_ser();// Perform Additional services process
       }
       else if(input_dial == 4)// Cancel reservation
       {
           List_of_guest[k].Cancel_rev(); //Perform reservation cancellation process
           // Returning reserved rooms to be free
            if(List_of_guest[k].type == 1)
            {
                avaliable_rooms_humans += List_of_guest[k].numberofrooms;
            }
            else if(List_of_guest[k].type == 2)
            {
                avaliable_rooms_monsters +=List_of_guest[k].numberofrooms;
            }
       }
        }
        input_dial = 0;
        // Asking if any other services are requested from the customer
       cout << "\nAny other service i can offer ? type 1 for yes or 0 for no : ";
       cin>>input_dial;
       // no means this guest services requested by him ended and Receptionist can receive another guest
       cout <<endl;
}
