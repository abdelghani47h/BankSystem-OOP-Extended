#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsString.h" 

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

class clsTotalBalancesScreen : protected clsScreen
{

private:

    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
       
        cout << "\t\t\t" << BLUE << "| " << RESET << setw(15) << left << Client.AccountNumber;
        cout << BLUE << "| " << RESET << setw(28) << left << Client.FullName();
        cout << BLUE << "| " << GREEN << setw(24) << left << fixed << setprecision(2) << Client.AccountBalance << RESET;
        cout << BLUE << " |" << RESET << endl;
    }

    static void _PrintTableHeader()
    {
        cout << "\n\t\t\t" << BLUE << "___________________________________________________________________________\n" << RESET;
        cout << "\n\t\t\t" << BLUE << "| " << RED << left << setw(15) << "Account Number";
        cout << BLUE << "| " << RED << left << setw(28) << "Client Name";
        cout << BLUE << "| " << RED << left << setw(24) << "Balance";
        cout << BLUE << " |";
        cout << "\n\t\t\t" << BLUE << "___________________________________________________________________________\n" << RESET;
    }

public:

    static void ShowTotalBalancesScreen()
    {
        vector <clsBankClient> Clients = clsBankClient::LoadClientsDataFromFile();

        string Title = "\t  Total Balances Screen";
        string SubTitle = "\t   (Clients Number: " + to_string(Clients.size()) + ")";

        clsScreen::_DrawScreenHeader(Title, SubTitle);

        _PrintTableHeader();

        double TotalBalances = 0;

        if (Clients.size() == 0)
        {
            cout << "\n\t\t\t\t" << RED << "No Clients Available In the System!" << RESET << endl;
        }
        else
        {
            for (clsBankClient& C : Clients)
            {
                _PrintClientRecordBalanceLine(C);
                TotalBalances += C.AccountBalance;
            }
        }

        cout << "\t\t\t" << BLUE << "___________________________________________________________________________\n" << RESET << endl;

        cout << "\n\t\t\t\t\t\t\t\t\t" << "Total Balances: " << GREEN << fixed << setprecision(2) << TotalBalances << RESET << endl;

        cout << "\n\t\t\t" << BLUE << "( " << YELLOW << clsString::NumberToWords(TotalBalances) << BLUE << " )" << RESET << endl;
    }
};