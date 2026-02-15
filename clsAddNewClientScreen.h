#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;
 
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"



class clsAddNewClientScreen : protected clsScreen
{
 

public:

    static void ShowAddClientScreen()
    {
  
        string Title = "\t  Add New Client Screen";
        _DrawScreenHeader(Title);

        string AccountNumber = "";

        cout << "\n\t\t\t\t\tPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadAccountNumber();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n\t\t\t\t\t" << RED << "Account Number (" << AccountNumber << ") already exists, Choose another: " << RESET;
            AccountNumber = clsInputValidate::ReadAccountNumber();
        }

     
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


         _ReadClientInfo(NewClient);


        char Answer = 'n';
        cout << "\n\t\t\t\t\tAre you sure you want to add this client? " << GREEN << "y" << RESET << "/" << RED << "n" << RESET << "? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            clsBankClient::enSaveResults SaveResult;
            SaveResult = NewClient.Save();

            switch (SaveResult)
            {
            case clsBankClient::svSucceeded:
            {
                cout << "\n\t\t\t\t\t" << GREEN << "Client Added Successfully! Here are the details:" << RESET;
                _PrintSubClientCard(NewClient);

                break;
            }
            case clsBankClient::svFaildEmptyObject:
            {
                cout << "\n\t\t\t\t\t" << RED << "Error: Account was not saved because it's empty." << RESET << endl;
                break;
            }
            case clsBankClient::svFaildAccountNumberExist:
            {
                cout << "\n\t\t\t\t\t" << RED << "Error: Account Number already exists!" << RESET << endl;
                break;
            }
            }
        }
        else
        {
            cout << "\n\t\t\t\t\t" << YELLOW << "Client Add Operation Cancelled." << RESET << endl;
        }
    }
};
