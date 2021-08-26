#ifndef SERVICES_H
#define SERVICES_H
#include "Account.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Services : public Account
{
    public:
        int numberofrooms=0; // number of rooms that the user reserve
        int numberofnights=0; // number of nights he will stay in the reserved rooms
        int total_cost=0;// Total cost of the user
        void New_rev();//New reservation
        void Ex_rev();// Extend reservation
        void Add_ser();// Additional service
        void Cancel_rev();// Cancel reservation
        void Display_Profile();// Used only with the receptionist section
};

#endif // SERVICES_H
