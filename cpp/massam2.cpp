/*
Contact Book - Remove and Display Functions

Description:
This file implements functions for removing contacts, displaying all saved contacts,
and exiting the contact book application.

Features:
- Remove a contact by name
- Display all stored contacts
- Show confirmation and basic user interaction messages

Notes:
- Contact data is stored in parallel vectors
- This file is part of a multi-file C++ contact management project
*/


#include <iostream>
#include <fstream>
#include <string>
//#include <sstream>
#include <algorithm>
#include <vector>
#include "massam.h"
using namespace std;



void removeContact(vector<string>& fullname, vector<string>& phone_num, vector<string>& email, vector<string>& birthday, vector<string>& address)
{
    while(true)
    {
        //declare variabel
        string remoname;
        bool found1;
        cout << "Enter the name to remove" << endl;
        cin.ignore();
        getline(cin,remoname); //fill in a name to remove 

        if(remoname.empty())
        {
            cout << "-------" << endl;
        }
        else
        {
          //for(int i = 0; i < fullname.size(); i++)
           //{
               auto us = find(fullname.begin(),fullname.end(), remoname);
                if(us != fullname.end())
                {
                    int poss = distance(fullname.begin(), us); 
                    fullname.erase(fullname.begin() + poss);
                    birthday.erase(birthday.begin() + poss);
                    phone_num.erase(phone_num.begin() + poss);
                    address.erase(address.begin() + poss);
                    email.erase(email.begin() + poss);
                    found1=true;

                    cout << "The contact has been removed successfully:" << endl;
                
                }
                else
                {
                    found1=false;
                }
                
                
            //}
                
        }
        if(found1==true)
        {
            //declare and initialize variable
            string mollimilan="|1 - remove another name: |";
            if(control(mollimilan)) //function anrop
            {
                continue;
            }
            else
            {
                return;
            }  
        }
        if(found1==false)
        {
            cout << "The contact is not exist:" << endl;
        
        }
        
    }
    
}
//To show all contacts in list
void displayContact(vector<string> &fullname, vector<string> &phone_num, vector<string> &email, vector<string> &birthday, vector<string> &address)
{
    while(true)
    {
        string temp;
        for(int i = 0; i < fullname.size(); i++)
        {
            cout << "The full name: " << fullname[i] << endl;
            cout << "The birth of year:  " << birthday[i] << endl;
            cout << "The phone number: " << phone_num[i] << endl;
            cout << "The number of street: " << address[i] << endl;
            cout << "The email address: " << email[i] << endl << endl;

        }
        //declare and initialize variable
        string mollimilan = "|1 - do you want to see the contacts again? |";
        if(control(mollimilan))
        {
            continue;
        }
        else
        {
            return;
        }   
    }   
}

void self_exit()
{
    cout << "Thank you for using" << endl;
    
}
    
