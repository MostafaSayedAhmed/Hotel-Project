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
        int service;
        int numberofrooms=0;
        int numberofnights=0;
        int total_cost=0;
        void New_rev();
        void Ex_rev();
        void Add_ser();
        void Cancel_rev();
    protected:

    private:
};

#endif // SERVICES_H
