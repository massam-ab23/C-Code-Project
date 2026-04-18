/*
Contact Book - Contact Management Functions

Description:
This file implements the main contact management features for a C++ contact book.
It supports adding contacts, searching contacts, validating phone numbers,
and handling user choices through a simple console menu.

Features:
- Add new contacts
- Search contacts by name
- Validate phone numbers and basic input
- Case-insensitive string comparison
- Control repeated actions through a menu system

Notes:
- Contact data is stored using parallel vectors
- This file is part of a multi-file C++ project
*/

#include <iostream>
#include <fstream>
#include <string>
//#include <sstream>
#include <algorithm>
#include <vector>
#include "massam.h"
using namespace std;


//function definition that allows you to add contacts and it has vectors of the string type as reference variables as input parameters. It is void function that returns nothing.
void addContact(vector<string>& fullname, vector<string>& phone_num, vector<string>& email, vector<string>& birthday, vector<string>& address)
{

    string term;
    while(true)
    { 
        cin.ignore();
        cout << "Enter First Name:" << " ";
        getline(cin,term); // fill in a name

    if(term.empty())
    {
        term = " --- ";
    }
    fullname.push_back(term); // added to the vector

    while(true) //checks if the entry is correct
    { 
        cout << "Now Enter Birthday:" << " ";
        getline(cin,term);
        if(term.empty())
        {
            term = "---";
        }

        //control if the birthday is right 
        for(int i = 0; i <term.size(); i++)
        {
            if(term[i]<'0' || term[i]>'9')
            {
                cout << "invalid signs!" << endl;
                break;
            }
        }

        if((term.size()<8 || term.size()>8) || (term[4]>='2' || term[6]>='4') || 
        (term[4]=='1' && term[5]>='3') || (term[6]=='3' && term[7]>='2'))
        {
            cout << "Invalid birthday!" << endl;
            continue;
        } 
        else
        {
            birthday.push_back(term);
            break;
        }   
    }
    while(true)
    { 
        cout << "Now enter the address :" << " ";
        getline(cin,term); 
        if(term.empty())
        {
            term = " ---- ";
            break;
        }
        auto space = find(term.begin(),term.end(),' ');
        auto atsign = find(term.begin(),term.end(),'@');

        //check if the address writing is correct
        if(space!=term.end() && !(atsign!=term.end()))
        {
            address.push_back(term);
            break;
        }
        else
        {
            cout <<"The address is incorrect, please try again!" << endl;
            continue;
        }  
    }

    //To control the input
    while(true)
    {
        //bool found2;

        cout << " Enter your Email: ";
        getline(cin,term);
        if(term.empty())
        {
            term = " --- ";
            break;
        }
        auto space = find(term.begin(),term.end(),' ');
        auto atsign = find(term.begin(),term.end(),'@');

        //check if the address writing is correct
        if(atsign!=term.end() && !(space!=term.end()))
        {
            address.push_back(term);
            break;
        }
        else
        {
            cout <<"The email is incorrect, please try again:" << endl;
            continue;
        } 
    }          
    
        while(true)
        { 
            //bool found;
            cout << "Enter 10-digit phone number" << " ";
            getline(cin,term);
            if (term.empty())
            {
                term = " --- ";
                break;
            }
            if(check_digits(term)== false)
            {
                cout << "The phone number must contain numbers only" << endl;
                continue;
            }
            if(term.size()==10 )
             {
                phone_num.push_back(term);
                break;
            }
            else
            {
                cout << "The phone number must contain 10 digits" << endl;
                continue;
            }
        } 
        //declare and intialize variable
        string mollimilan = "|1 - add new contact: |";
        if(control(mollimilan)) //anropas functionen
        {
            continue;
        }
        else
        {
            return; //return nothing
        }
     
    }
    
      
}

//function definition that allows searching for contacts

void searchContact(vector<string>& fullname, vector<string>& phone_num, vector<string>& email, vector<string>& birthday, vector<string>& address)
{
    
    while(true)
    {
        //declare variables
        string contacts;
        bool found3;

        cout << "Enter name to search:" << " ";
        cin.ignore();
        getline(cin,contacts); //fill in the name

        if(contacts.empty())
        {
            cout << " --- " << endl;
        }
        else
        {
            for(int i = 0; i < fullname.size(); i++)
            {
                //checks if the name has a larger string
                if(contacts.size()>(fullname[i]).size())
                {
                    cout << "The name is not exist" << endl;
                    break;
                }
                if(contacts.size()<=(fullname[i]).size())
                {
                    //To control if the new string is present in each element
                    for(int k = 0; k < (fullname[i]).size(); k++)
                    {
                        for(int j = 0; j < contacts.size(); j++)
                        {
                            string n3=fullname[i].substr(k,j+1);
                            if(case_insensitive(contacts,n3)) //function anropas
                            {
                                cout << "The full name: " << fullname[i] << endl;
                                cout << "The birth of year: " << birthday[i] << endl;
                                cout << "The phone number: " << phone_num[i] << endl;
                                cout << "The contact address: " << address[i] << endl;
                                cout << "The email address: " << email[1] << endl;
                                found3 = true;
                                break;
                            }
                        }
                        
                    }
                    
                }
                
                
            }
            
        }
        if(found3==true)
        {
            //declare and initialize variable
            string mollimilan="|1 -search for a new contactname:  |";
            if(control(mollimilan)) //function anrop
            {
                found3=false;
                continue;
            }
            else
            {
                return; //return nothing
            }  
        }
        else
        {
            cout << "The contacts name is not exist:" << endl;
        }
    }
    
}
//function definition that makes the string insensitive to characters comparing them.
//It has two input parameters of the string type and it is bool function that returns true or false depending on the imparameters
bool case_insensitive(string n1, string n2)
{
    transform(n1.begin(),n1.end(),n1.begin(),::tolower);
    transform(n2.begin(),n2.end(),n2.begin(),::tolower);
    if(n1.compare(n2)==0)
    {
        return true;;
    }
    else
    {
        return false;
    }
      
}
//function defintion that controls whether to repeat the function or exit and return to the main menu.It has an input parameter of the string type.
bool control(string mollimilan)
{
    //declare variable
    string temp;

    while(true)
    { 

        cout << "That you want" << endl;
        cout << "|--------|" << endl;
        cout << mollimilan << endl;    //prints defferent strings for different functions 
        cout << "|2 - retern to mainmenu: |" << endl;
        cout << "|----------|" << endl;
        cout << "your choise is:" << endl;
        cin >> temp;
        if(temp=="1")
        {
            return true;
        }
        if(temp=="2")
        {
            return false;
        }
        if(temp < "1" || temp > "2")
        {
            cout << "Not such alternative: Enter a new alternative in the menu:";
            continue;
        }
    }

}

bool check_digits(string x)
{
    bool check = true;
    for(int i=0; i < x.length(); i++)
    {
        if(!((x[i]) >= '0' && (x[i]) <= '9'))
        {
            check = false;
            break;
        }
    }

    if(check == true)
    {
        return true;
        
    }
    else
    {
        return false;

    }
}


    
    
