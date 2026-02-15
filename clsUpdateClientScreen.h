#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsUpdateClientScreen : protected clsScreen
{
public:
    static void ShowUpdateClientScreen()
    {
        string Title = "\t  Update Client Screen";
        clsScreen::_DrawScreenHeader(Title);

        string AccountNumber = "";

        cout << "\n\n\t\t\t\t\tPlease Enter Client Account Number: ";
        AccountNumber = clsInputValidate::ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n\t\t\t\t\t" << RED << "Account number (" << AccountNumber << ") is not found, choose another one: " << RESET;
            AccountNumber = clsInputValidate::ReadAccountNumber();
        }

        clsBankClient Client = clsBankClient::FindClientByAccountNumber(AccountNumber);
        clsScreen::_PrintFullClientCard(Client);

        char Answer = 'n';
        cout << "\n\n\t\t\t\t\tAre you sure you want to update this client? " << GREEN << "y" << RESET << "/" << RED << "n" << RESET << "? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            system("cls");

            string Sub = "\t  Update Client (" + AccountNumber + ") Info";
            clsScreen::_DrawScreenHeader( Sub);


            clsScreen::_ReadClientInfo(Client);

            clsBankClient::enSaveResults SaveResult;
            SaveResult = Client.Save();

            switch (SaveResult)
            {
            case clsBankClient::enSaveResults::svSucceeded:
                cout << "\n\t\t\t\t\t" << GREEN << "Account Updated Successfully :-)" << RESET << endl;
                clsScreen::_PrintFullClientCard(Client);
                break;

            case clsBankClient::enSaveResults::svFaildEmptyObject:
                cout << "\n\t\t\t\t\t" << RED << "Error: Account was not saved because it's Empty." << RESET << endl;
                break;
            }
        }
        else
        {
            cout << "\n\t\t\t\t\t" << RED << "Update Operation Cancelled." << RESET << endl;
        }
    }
};