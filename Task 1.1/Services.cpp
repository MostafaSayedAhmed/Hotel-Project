#include "Services.h"
#include "Account.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void Services:: New_rev()
{
    cout<<"\nHow many rooms do you want to reserve ? ";
    cin >> numberofrooms;
    cout<<"\nHow many nights will you stay ? ";
    cin >> numberofnights;
    if(type == 'h')
    {
        total_cost = 500*numberofnights *numberofrooms;
    }
    else
        {
          total_cost = 200*numberofnights *numberofrooms;
        }
}

void Services::Ex_rev()
{
    int extendednights;
    cout <<"\nfor how long would you like to extend your accommodation ?";
    cin >> extendednights;
        if(type == 'h')
    {
         total_cost += 500*extendednights *numberofrooms;
    }
    else
        {
         total_cost += 200*extendednights *numberofrooms;
        }
    numberofnights += extendednights;
}

void Services:: Add_ser()
{
    service = 0;
    cout <<"\nHere are the services we can offer : \n";
    cout <<"1.Dry cleaning\n";
    cout <<"2.Spa\n";
    cout <<"0.None of them\n";
    cout<<"Please enter the number of service you want : ";
    cin>>service;
    if(service == 1){
    if(type == 'h')
    {
        total_cost += 70*numberofnights;
    }
    else
        {
          total_cost += 30*numberofnights;;
        }
    }
    else if (service == 2)
    {
    if(type == 'h')
    {
        total_cost += 100*numberofnights;
    }
    else
        {
          total_cost += 50*numberofnights;;
        }
    }

}

void Services:: Cancel_rev()
{
    cout<<"\nYour total cost = ";
    cout<<total_cost;
}
