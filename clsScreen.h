#pragma once
#include <iostream>
 
#include <vector>
#include  <iomanip >
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsDate.h"
#include "Global.h"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

using namespace std;
class clsScreen
{


protected:
     

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        clsDate Date;

        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n";


        cout <<YELLOW<< "\t\t\t\t\tUser: " << CurrentUser.UserName << endl;

  
        cout << "\t\t\t\t\tDate: " <<  Date.DateToString( ) << endl<<RESET;
        
    }

    static void _PrintFullClientCard(clsBankClient Client)
    {
   
        cout << YELLOW << "\n\t\t\t\t\tClient Details\n" << RESET;
        cout << "\n\t\t\t\t\t_________________________________________";
        cout << "\n\t\t\t\t\t" << left << setw(15) << "Account Number" << ": " << Client.AccountNumber;
        cout << "\n\t\t\t\t\t" << left << setw(15) << "Full Name" << ": " << Client.FullName();
        cout << "\n\t\t\t\t\t" << left << setw(15) << "Email" << ": " << Client.Email;
        cout << "\n\t\t\t\t\t" << left << setw(15) << "Phone" << ": " << Client.Phone;
        cout << "\n\t\t\t\t\t" << left << setw(15) << "Balance" << ": " << Client.AccountBalance;
        cout << "\n\t\t\t\t\t_________________________________________\n";
    }



    static void _PrintSubClientCard(clsBankClient Client)
    {

        cout << "\n\t\t\t\t\t-----------------------------------------";
        cout << "\n\t\t\t\t\tAccount Number : " << Client.AccountNumber;
        cout << "\n\t\t\t\t\tFull Name      : " << Client.FullName();
        cout << "\n\t\t\t\t\tBalance        : " << Client.AccountBalance;
        cout << "\n\t\t\t\t\t-----------------------------------------\n";
    }

    static void  _ReadClientInfo(clsBankClient& Client)
    {

        cout << "\n\t\t\t\t\t_________________________________________";
        cout << YELLOW << "\n\n\t\t\t\t\tEnter Client Details:\n" << RESET;
       

        cout << "\n\t\t\t\t\t" << left << setw(15) << "First Name" << ": ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\t\t\t\t\t" << left << setw(15) << "Last Name" << ": ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\t\t\t\t\t" << left << setw(15) << "Email" << ": ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\t\t\t\t\t" << left << setw(15) << "Phone" << ": ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\t\t\t\t\t" << left << setw(15) << "Pin Code" << ": ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\t\t\t\t\t" << left << setw(15) << "Balance" << ": ";
        Client.AccountBalance = clsInputValidate::ReadNumber <double>("\t\t\t\t\tInvalid Number, Enter again: ");
        cout << "\n\t\t\t\t\t_________________________________________\n";
    }


   static void _PrintClientRecordLine(clsBankClient Client)
    {

        cout << BLUE << "| " << RESET << setw(15) << left << Client.AccountNumber;
        cout << BLUE << "| " << RESET << setw(20) << left << Client.FullName();
        cout << BLUE << "| " << RESET << setw(12) << left << Client.Phone;
        cout << BLUE << "| " << RESET << setw(40) << left << Client.Email;
        cout << BLUE << "| " << RESET << setw(10) << left << Client.PinCode;
        cout << BLUE << "| " << RESET << setw(12) << left << fixed << setprecision(1) << Client.AccountBalance;
    }



};

