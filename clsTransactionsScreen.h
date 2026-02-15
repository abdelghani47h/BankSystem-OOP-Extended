#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsShowTransferLogScreen.h"

using namespace std;

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

class clsTransactionsScreen : protected clsScreen
{
private:
    enum enTransactionsMenueOptions {
        eDeposit = 1,
        eWithdraw = 2,
        eTotalBalances = 3,
        eTransfer=4,
        eShowTransfer=5,
        eShowMainMenue = 6
    };

    static void _ShowDepositScreen() 
    {
        clsDepositScreen::ShowDepositScreen();
    }
    static void _ShowWithdrawScreen() 
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    }
        
    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static short _ReadTransactionsMenueOption()
    {
        cout << "\n\t\t\t\tChoose what do you want to do? [1 to 6]? ";
         short Choice = clsInputValidate::ReadNumberBetween(1, 6, "\n\t\t\t\tEnter Number between 1 to 6? ");
        return Choice;
    }

    static void _ShowTransactionsMenue()
    {
        _DrawScreenHeader("\t  Transactions Screen");

        cout << BLUE << "\n\n\n\t\t\t\t======================================================\n\n" << RESET;
        cout << "\t\t\t\t\t\t" << RED << "Transactions Menue" << RESET << "\n";
        cout << BLUE << "\n\t\t\t\t======================================================\n\n" << RESET;

        cout << "\t\t\t\t" << GREEN << "[1]" << RESET << " Deposit.\n";
        cout << "\t\t\t\t" << GREEN << "[2]" << RESET << " Withdraw.\n";
        cout << "\t\t\t\t" << GREEN << "[3]" << RESET << " Total Balances.\n";
        cout << "\t\t\t\t" << GREEN << "[4]" << RESET << " Transfer.\n";
        cout << "\t\t\t\t" << GREEN << "[5]" << RESET << " Transfers Log.\n";
        cout << "\t\t\t\t" << GREEN << "[6]" << RESET << " Main Menue.\n";

        cout << BLUE << "\n\n\t\t\t\t======================================================\n" << RESET;
    }

    static void _GoBackToTransactionsMenue()
    {
        cout <<RED <<"\n\t\t\t\tPress any key to go back to Transactions Menue..."<<RESET;
        system("pause>0");
        ShowTransactionsMenue(); 
    }

    static void _ShowTransferLogScreen() {

        clsShowTransferLogScreen::ShowTransferLogScreen();

    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTotalBalances:
        {
            system("cls");
            _ShowTotalBalancesScreen();
             _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTransfer:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowMainMenue:
        {
          
            break;
        }
        }
    }

public:
  
    
    static void ShowTransactionsMenue()
    {
        system("cls");

        _ShowTransactionsMenue();
        enTransactionsMenueOptions  Option = (enTransactionsMenueOptions)_ReadTransactionsMenueOption();
        _PerformTransactionsMenueOption(Option);
    }


};