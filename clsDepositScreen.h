#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

 
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
 

class clsDepositScreen : protected clsScreen
{
private:
 
    static bool _IsMultipleOf5(double Amount )
    {

        return (((int)Amount % 5 == 0));
    }

public:

    static void ShowDepositScreen()
    {
        cout << "\n\n";

        string Title = "\t   Deposit Screen";
        clsScreen::_DrawScreenHeader(Title);

        string AccountNumber = "";

        cout << "\n\n\t\t\t\t\t" << YELLOW << "Please enter Account Number: " << RESET;
        AccountNumber = clsInputValidate::ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\n\t\t\t\t\t" << RED << "Client [" << AccountNumber << "] not found. Enter another: " << RESET;
            AccountNumber = clsInputValidate::ReadAccountNumber();
        }

        clsBankClient Client1 = clsBankClient::FindClientByAccountNumber(AccountNumber);
        clsScreen::_PrintFullClientCard(Client1);

        double DepositAmount = 0;
        cout << "\n\t\t\t\t\t" << YELLOW << "Please enter deposit amount: " << RESET;
        DepositAmount = clsInputValidate::ReadNumber<double>();

     
        while (DepositAmount <= 0 || !_IsMultipleOf5( DepositAmount ))
        {
            cout << "\n\t\t\t\t\t" << RED << "Invalid Amount. Must be positive and multiple of 5: " << RESET;
            DepositAmount = clsInputValidate::ReadNumber<double>();
        }

        char Answer = 'n';
        cout << "\n\t\t\t\t\t" << "Are you sure you want to deposit " << GREEN << DepositAmount << RESET << " ? " << GREEN << "y" << RESET << "/" << RED << "n" << RESET << "? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            Client1.Deposit(DepositAmount);

            cout << "\n\t\t\t\t\t" << GREEN << "-----------------------------------------" << RESET;
            cout << "\n\t\t\t\t\t" << GREEN << " Deposit Completed Successfully! :-) " << RESET;
            cout << "\n\t\t\t\t\t" << GREEN << "-----------------------------------------" << RESET;

            cout << "\n\t\t\t\t\t" << "New Balance Is: " << GREEN << Client1.AccountBalance << RESET << endl;
        }
        else
        {
            cout << "\n\t\t\t\t\t" << RED << "Operation Cancelled." << RESET << endl;
        }
    }
};

