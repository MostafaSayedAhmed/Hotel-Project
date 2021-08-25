#include "Services.h"
#include "Account.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int avaliable_rooms_monsters=15 , avaliable_rooms_humans=5 ,flag =0;
int check =0;
int main()
{
   Services List_of_guest[20];
   int k=0;
   while(flag ==0)
    {
        int input_dial=0;
        while(input_dial != 1 && input_dial != 2 )
        {
        cout<<"Welcome sir to Transylvania hotel "<<endl;
        cout<<"for new guests services , type 1 "<<endl;
        cout<<"for old guests services , type 2 "<<endl;
        cin>>input_dial;
        while(check == 0)
        {
        if(input_dial == 1 )
        {
           for(int i=0;i<20;i++)
              {
                  if(!List_of_guest[i].ID)
                  {
                      k=i;
                      check = 1;
                      break;
                  }
              }
            List_of_guest[k].Sign_up();
        }
        else if (input_dial == 2)
        {
            for(int i=0;i<20;i++)
              {
                  if(List_of_guest[i].Sign_In())
                  {
                      k=i;
                      check = 1;
                      break;
                  }
              }

        }
        }
    }
    check = 0;
    input_dial =0 ;
    while(input_dial != 1 && input_dial != 2 && input_dial != 3 && input_dial != 4)
        {
        cout<<"\nWelcome "<<List_of_guest[k].name<<endl;
        cout<<"How can i help you :"<<endl;
        cout<<"1.New reservation"<<endl;
        cout<<"2.Extend reservation"<<endl;
        cout<<"3.Additional services"<<endl;
        cout<<"4.Cancel reservation"<<endl;
        cin>>input_dial;
        if(input_dial == 1)
        {
            List_of_guest[k].New_rev();
            if(List_of_guest[k].type == 'h' && avaliable_rooms_humans < List_of_guest[k].numberofrooms)
            {
                cout<<"\nSorry the number of rooms required isn't available ";
                cout<<"\nPlease change the entered number";
                List_of_guest[k].New_rev();
            }
            else if (List_of_guest[k].type == 'm' && avaliable_rooms_monsters < List_of_guest[k].numberofrooms)
            {
                cout<<"\nSorry the number of rooms required isn't available ";
                cout<<"\nPlease change the entered number";
                List_of_guest[k].New_rev();
            }
            if(List_of_guest[k].type == 'h')
            {
                avaliable_rooms_humans -= List_of_guest[k].numberofrooms;
            }
            else
            {
                avaliable_rooms_monsters -=List_of_guest[k].numberofrooms;
            }
        }
       else if(input_dial == 2)
       {
           List_of_guest[k].Ex_rev();
       }
       else if(input_dial == 3)
       {
           List_of_guest[k].Add_ser();
       }
       else if(input_dial == 4)
       {
           List_of_guest[k].Cancel_rev();
            if(List_of_guest[k].type == 'h')
            {
                avaliable_rooms_humans += List_of_guest[k].numberofrooms;
            }
            else
            {
                avaliable_rooms_monsters +=List_of_guest[k].numberofrooms;
            }
       }
        }
       cout << "\nAny other service i can offer ? type 1 for yes or 0 for no";
       cin>>input_dial;
       if(input_dial==1)
       {
                  cout<<"How can i help you :"<<endl;
        cout<<"1.New reservation"<<endl;
        cout<<"2.Extend reservation"<<endl;
        cout<<"3.Additional services"<<endl;
        cout<<"4.Cancel reservation"<<endl;
        cin>>input_dial;
        if(input_dial == 1)
        {
            List_of_guest[k].New_rev();
            if(List_of_guest[k].type == 'h' && avaliable_rooms_humans < List_of_guest[k].numberofrooms)
            {
                cout<<"\nSorry the number of rooms required isn't available ";
                cout<<"\nPlease change the entered number";
                List_of_guest[k].New_rev();
            }
            else if (List_of_guest[k].type == 'm' && avaliable_rooms_monsters < List_of_guest[k].numberofrooms)
            {
                cout<<"\nSorry the number of rooms required isn't available ";
                cout<<"\nPlease change the entered number";
                List_of_guest[k].New_rev();
            }
            if(List_of_guest[k].type == 'h')
            {
                avaliable_rooms_humans -= List_of_guest[k].numberofrooms;
            }
            else
            {
                avaliable_rooms_monsters -=List_of_guest[k].numberofrooms;
            }
        }
       else if(input_dial == 2)
       {
           List_of_guest[k].Ex_rev();
       }
       else if(input_dial == 3)
       {
           List_of_guest[k].Add_ser();
       }
       else if(input_dial == 4)
       {
           List_of_guest[k].Cancel_rev();
            if(List_of_guest[k].type == 'h')
            {
                avaliable_rooms_humans += List_of_guest[k].numberofrooms;
            }
            else
            {
                avaliable_rooms_monsters +=List_of_guest[k].numberofrooms;
            }
       }
       }
    }
    return 0;
}
