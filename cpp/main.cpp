/*
Contact Book Application

Description:
This program implements a simple contact book in C++.
It allows the user to add, search, remove, and display contacts.

Features:
- Read contacts from a text file
- Add new contacts
- Search for existing contacts
- Remove contacts
- Save updated contacts back to file

Notes:
- Contact data is stored in contacts.txt
- The project is organized across multiple source files
*/
#include <iostream> 
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "massam.h"

using namespace std;

//main function for contact book
int main()
{
    vector <string> fullname, phone_num, email, birthday, address;

    ifstream input;
    ofstream output;

    //declares variable
    string term;
    string choice;

    input.open("contacts.txt"); //inputfile open

    while(getline(input,term))
    {
        fullname.push_back(term);

        getline(input,term);
        birthday.push_back(term);

        getline(input,term);
        phone_num.push_back(term);

        getline(input,term);
        address.push_back(term);

        getline(input,term);
        email.push_back(term);
    }
    input.close();

    do
    {
        
     //do
     while(true)
     {
        cout << "Contact book:" << endl;
        cout << "Press 1 To Add Contact:" << endl;
        cout << "Press 2 To Search Contact:" << endl;
        cout << "Press 3 To Remove Contact:" << endl;
        cout << "Press 4 To DisplayContact:" << endl;
        cout << "Press 5 To Exit:" << endl;
        cout << "Enter Transaction" << endl;
        cin >> choice;


        if(choice=="1")
        {
            addContact(fullname, phone_num, email, birthday, address);
            break;
        }
        else if(choice=="2")
        {
            searchContact(fullname, phone_num, email, birthday, address);
            break;
        }
        else if(choice=="3")
        {
            removeContact(fullname,  phone_num, email, birthday, address);
            break;
        }
        else if(choice=="4")
        {
            displayContact(fullname, phone_num, email, birthday, address);
            break;
        }
        else if(choice=="5")
        {
            self_exit();
            break;
        }
        else
        {
            cout << "Invalid Input" << endl;
            break;
        } 
      }//while (true);  
    }
   while(choice != "5");
   
    output.open("contacts.txt");

    for(int i = 0; i < fullname.size(); i++)
    {
        output << fullname[i] << endl;
        output << birthday[i] << endl;
        output << phone_num[i]  << endl;
        output << address[i]  << endl;
        output << email[i]  << endl;
    }
    output.close(); 
    return 0;
}
