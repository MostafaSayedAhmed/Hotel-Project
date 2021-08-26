#include "Services.h"
#include "Account.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void Services:: New_rev()// New reservation
{
    cout<<"\nHow many rooms do you want to reserve ? ";
    cin >> numberofrooms;// User enter the number of rooms he/she/it wishes to reserve
    cout<<"\nHow many nights will you stay ? ";
    cin >> numberofnights;// User enter the number of nights he/she/it wishes to reserve
    if(type == 1)// Humans cost calculation section
    {
        total_cost = 500*numberofnights *numberofrooms;// Total cost for humans
    }
    else if (type == 2)
        {
          total_cost = 200*numberofnights *numberofrooms;// Total cost for monsters
        }
    cout<<"Total cost = "<<total_cost<<endl;// Printing the total cost
}

void Services::Ex_rev()// Extend reservation
{
    int extendednights;// Number of nights that will be extended
    cout <<"\nfor how long would you like to extend your accommodation ?";
    cin >> extendednights;
        if(type == 1)// Humans cost calculation section
    {
         total_cost += 500*extendednights *numberofrooms;// Total cost for humans
         cout<<"The Extension cost = "<<500*extendednights *numberofrooms<<endl;
    }
    else if (type == 2)// Monsters cost calculation section
        {
         total_cost += 200*extendednights *numberofrooms;// Total cost for monsters
         cout<<"The Extension cost = "<<200*extendednights *numberofrooms<<endl;
        }
    numberofnights += extendednights;// Calculating the total nights
    cout<<"Total cost = "<<total_cost<<endl;// Printing the total cost
}

void Services:: Add_ser()// Additional services
{
    int service = 0;
    cout <<"\nHere are the services we can offer : \n";
    cout <<"1.Dry cleaning\n";
    cout <<"2.Spa\n";
    cout <<"0.None of them\n";
    cout<<"Please enter the number of service you want : ";
    cin>>service;
    if(service == 1){// Dry cleaning service
    if(type == 1) // Humans cost calculation section
    {
        total_cost += 70*numberofnights;// Total cost for humans
        cout<<"The Additional Services cost = "<<70*numberofnights<<endl;// Additional cost for humans
    }
    else if (type == 2)// Monsters cost calculation section
        {
          total_cost += 30*numberofnights;// Total cost for monsters
          cout<<"The Additional Services cost = "<<30*numberofnights<<endl; // Additional cost for monsters
        }
    }
    else if (service == 2) // Spa service
    {
    if(type == 1) // Humans cost calculation section
    {
        total_cost += 100*numberofnights;// Total cost for humans
       cout<<"The Additional Services cost = "<<100*numberofnights<<endl;// Additional cost for humans
    }
    else if (type == 2)// Monsters cost calculation section
        {
          total_cost += 50*numberofnights;// Total cost for monsters
          cout<<"The Additional Services cost = "<<50*numberofnights<<endl;// Additional cost for monsters
        }
    }
  cout<<"Total cost = "<<total_cost<<endl;// Printing the total cost
}

void Services:: Cancel_rev()// Reservation cancellation section
{
    cout<<"\nYour total cost = "<<total_cost<<endl;// Printing the total cost
}
void Services::Display_Profile()// Access by Receptionist to check residents list
{
    cout<<"User name : " <<name<<endl ;// Display user name
    cout<<"User ID : " <<ID<<endl ;// Display user ID
    cout<<"User Number of rooms : " <<numberofrooms<<endl ;// Display user number of rooms
    cout<<"User Number of nights : " <<numberofnights<<endl ;// Display user number of nights
    cout<<"User total cost : " <<total_cost<<endl ;// Display user total cost
}
