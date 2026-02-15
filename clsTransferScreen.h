#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

 #define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

class clsTransferScreen : protected clsScreen
{
private:
    static string _Indent() { return "\t\t\t\t"; }

    static void _PrintClientCard(clsBankClient Client)
    {
        string Indent = _Indent();
        cout << "\n" << Indent   << "\t  ____________________________________" ;
        cout << "\n" << Indent << "\t  | " << setw(15) << left << "Full Name" << ": " <<  Client.FullName()  ;
        cout << "\n" << Indent   << "\t  | " << setw(15) << left << "Acc. Number" << ": "  << Client.AccountNumber  ;
        cout << "\n" << Indent   << "\t  | " << setw(15) << left << "Balance" << ": "   << Client.AccountBalance  ;
        cout << "\n" << Indent   << "\t  ____________________________________"  << endl;
    }

public:

    static void ShowTransferScreen()
    {
        string Indent = _Indent();

       
        _DrawScreenHeader("\t    Transfer Screen");

        // ---------------------------------------------------------
        // 1. Transfer From (Sender)
        // ---------------------------------------------------------
        cout << "\n\t " << Indent << MAGENTA << "=== Transfer From (Sender) ===" << RESET << "\n";

        string SourceAccountNumber = "";
        cout << Indent << "\tEnter Account Number: ";
        SourceAccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(SourceAccountNumber))
        {
            cout << Indent << RED << "\t(!) Account not found, try again: " << RESET;
            SourceAccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient SourceClient = clsBankClient::FindClientByAccountNumber(SourceAccountNumber);
        _PrintClientCard(SourceClient);


        // ---------------------------------------------------------
        // 2. Transfer To (Receiver)
        // ---------------------------------------------------------
        cout << "\n" << Indent << MAGENTA << "\t === Transfer To (Receiver) ===" << RESET << "\n";

        string DestinationAccountNumber = "";
        cout << Indent << "\t Enter Account Number: ";
        DestinationAccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(DestinationAccountNumber) || DestinationAccountNumber == SourceAccountNumber)
        {
            if (DestinationAccountNumber == SourceAccountNumber)
                cout << Indent << RED << "\t (!) Cannot transfer to same account: " << RESET;
            else
                cout << Indent << RED << "\t (!) Account not found, try again: " << RESET;

            DestinationAccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient DestinationClient = clsBankClient::FindClientByAccountNumber(DestinationAccountNumber);
        _PrintClientCard(DestinationClient);


        // ---------------------------------------------------------
        // 3. Amount
        // ---------------------------------------------------------
        double Amount = 0;
        cout << "\n" << Indent << "\t Enter Amount to Transfer: ";
        Amount = clsInputValidate::ReadNumber<double>();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << Indent << RED << "\t (!) Amount Exceeds Balance [" << SourceClient.AccountBalance << "]" << RESET;
            cout << "\n" << Indent << "\t Enter Valid Amount: ";
            Amount = clsInputValidate::ReadNumber<double>();
        }


        // ---------------------------------------------------------
        // 4. Execution
        // ---------------------------------------------------------
        char Answer = 'n';
        cout << "\n" << Indent << RESET << "Are you sure you want to transfer " << Amount << "? (" << GREEN << "Y" << RESET << "/" << RED << "N" << RESET << "): ";        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
            {
                cout << "\n" << Indent << GREEN << "\t * Transfer Done Successfully *" << RESET << "\n";

              
                _PrintClientCard(SourceClient);
                cout << Indent << "\t   " << RED << "(- " << Amount << ")" << RESET << endl;

                _PrintClientCard(DestinationClient);
                cout << Indent << "\t   " << GREEN << "(+ " << Amount << ")" << RESET << endl;

              

            }
            else
            {
                cout << "\n" << Indent << RED << "\t (!) Transfer Failed." << RESET << "\n";
            }
        }
        else
        {
            cout << "\n" << Indent << RED << "\t Operation Cancelled." << RESET << "\n";
        }
    }
};