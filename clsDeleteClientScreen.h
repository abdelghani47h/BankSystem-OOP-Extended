#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>


#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

class clsDeleteClientScreen : protected clsScreen
{

 
public:

    static void ShowDeleteClientScreen()
    {
        string Title = "\t  Delete Client Screen";
        clsScreen::_DrawScreenHeader(Title);

        string AccountNumber = "";

        cout << "\n\n\t\t\t\t\tPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n\t\t\t\t\t" << RED << "Account Number (" << AccountNumber << ") is not found, choose another: " << RESET;
            AccountNumber = clsInputValidate::ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::FindClientByAccountNumber(AccountNumber);
        _PrintFullClientCard(Client);

        char Answer = 'n';
        cout << "\n\n\t\t\t\t\tAre you sure you want to delete this client? " << GREEN << "y" << RESET << "/" << RED << "n" << RESET << "? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (Client.Delete())
            {
                cout << "\n\t\t\t\t\t" << GREEN << "Client Deleted Successfully." << RESET << endl;

                _PrintFullClientCard(Client); 
            }
            else
            {
                cout << "\n\t\t\t\t\t" << RED << "Error: Client was not deleted." << RESET << endl;
            }
        }
        else
        {
            cout << "\n\t\t\t\t\t" << RED << "Delete Operation Cancelled." << RESET << endl;
        }
    }
};