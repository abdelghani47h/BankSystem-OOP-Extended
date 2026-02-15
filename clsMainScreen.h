#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUserScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"

using namespace std;

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

class clsMainScreen : protected clsScreen
{

private:
    enum enMainMenueOptions {
        eListCients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister=8, eCurrencyExchange=9,eExit = 10
    };   

    static short _ReadMainMenueOption()
    {
        cout << "\n\t\t\t\tChoose what do you want to do? [1 to 10]? ";
        short Num = clsInputValidate::ReadNumberBetween(1, 10, "\n\t\t\t\tPlease Enter Number Between [1-10]: ");
        return Num;
    }

    static void _ShowClientsList()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientScreen()
    {
        clsAddNewClientScreen::ShowAddClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionScreen()
    {
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenueScreen()
    {
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeScreen() {

        clsCurrencyExchangeScreen::ShowCurrencyExchangeMenu();

    }

    static void _GoBackToMainMenue()
    {
        cout << RED<<setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Main Menue...\n"<<RESET;
        system("pause>0");
  
    }

    static void _PrintMainScreen() 
    {
        system("cls");
        _DrawScreenHeader("\t    Show Main Menue");

        cout << BLUE << "\n\n\n\t\t\t\t======================================================\n\n" << RESET;
        cout << "\t\t\t\t\t\t    " << RED << "Main Menue" << RESET << "\n\n";
        cout << BLUE << "\t\t\t\t======================================================\n\n\n" << RESET;

        cout << "\t\t\t\t" << GREEN << "[1]" << RESET << " Show Clients List.\n";
        cout << "\t\t\t\t" << GREEN << "[2]" << RESET << " Add New Clients.\n";
        cout << "\t\t\t\t" << GREEN << "[3]" << RESET << " Delete Client.\n";
        cout << "\t\t\t\t" << GREEN << "[4]" << RESET << " Update Client Info.\n";
        cout << "\t\t\t\t" << GREEN << "[5]" << RESET << " Find Clients.\n";
        cout << "\t\t\t\t" << GREEN << "[6]" << RESET << " Transactions.\n";
        cout << "\t\t\t\t" << GREEN << "[7]" << RESET << " Manage Users.\n";
        cout << "\t\t\t\t" << GREEN << "[8]" << RESET << " Login Register.\n";
        cout << "\t\t\t\t" << GREEN << "[9]" << RESET << " CurrencyExchange.\n";
        cout << "\t\t\t\t" << GREEN << "[10]" << RESET << " Logout.\n";

        cout << BLUE << "\n\n\t\t\t\t======================================================\n" << RESET;


    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }

    static bool _CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\n\n\n\n\n\t\t\t\t__________________________________________________";
            cout << "\n\n\t\t\t\t  " << RED << "   Access Denied! Contact your Admin." << RESET;
            cout << "\n\t\t\t\t__________________________________________________\n\n";
            system("pause>0");        
            return false;
        }
        else
        {
            return true;
        }
    }

    

    static void _PerformMainMenueOption()
    {
        bool RunMainMenu = true;  
        while (RunMainMenu)
        {
            _PrintMainScreen();
            enMainMenueOptions MainMenue = enMainMenueOptions(_ReadMainMenueOption());

            switch (MainMenue)
            {



            case clsMainScreen::eListCients:  
            {
                system("cls");
                if (_CheckAccessRights(clsUser::enPermissions::pListClients))
                {
                    _ShowClientsList();
                }
                _GoBackToMainMenue();
                break;
            }

            case clsMainScreen::eAddNewClient:
            {
                system("cls");
                if (_CheckAccessRights(clsUser::enPermissions::pAddNewClient))
                {
                   _ShowAddNewClientScreen();
                }
                _GoBackToMainMenue();
                break;
            }

            case clsMainScreen::eDeleteClient:
            {
                system("cls");
                if (_CheckAccessRights(clsUser::enPermissions::pDeleteClient))
                {
                  _ShowDeleteClientScreen();
                }
                _GoBackToMainMenue();
                break;
            }
            case clsMainScreen::eUpdateClient:
            {
                system("cls");
                if (_CheckAccessRights(clsUser::enPermissions::pUpdateClients))
                {
                    _ShowUpdateClientScreen();
                }
                _GoBackToMainMenue();
                break;
            }

            case clsMainScreen::eFindClient:
            {
                system("cls");
                if (_CheckAccessRights(clsUser::enPermissions::pFindClient))
                {
                    _ShowFindClientScreen();
                }
                _GoBackToMainMenue();
                break;
            }

           

            case clsMainScreen::eShowTransactionsMenue:
            {
                system("cls");
                if (_CheckAccessRights(clsUser::enPermissions::pTranactions))
                {
                    _ShowTransactionScreen();
                }
                
                break; 
            }

            case clsMainScreen::eManageUsers:
            {
                system("cls");
                if (_CheckAccessRights(clsUser::enPermissions::pManageUsers))
                {
                    _ShowManageUsersMenueScreen();
                }
             
                break;
            }

            case clsMainScreen::eLoginRegister:
            {
                system("cls");
                if (_CheckAccessRights(clsUser::enPermissions::pLoginRegister))
                {
                    _ShowLoginRegisterScreen();
                }
                _GoBackToMainMenue();
                break; 
            }
             
            case clsMainScreen::eCurrencyExchange:
            {
                system("cls");
                if (_CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
                {
                    _ShowCurrencyExchangeScreen();
                }
                _GoBackToMainMenue();
                break; 
            }

            case clsMainScreen::eExit:
            {
                system("cls");
                _Logout();
                RunMainMenu = false;  
                break;
            }
            }
        }
    }

public:

    static void ShowMainMenue()
    {
 
        _PerformMainMenueOption( );

        cout << "\t\t\t\t  End Programing ";

    }
};