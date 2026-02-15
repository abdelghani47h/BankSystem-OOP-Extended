#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsShowListCurrenciesScreen.h"
#include "clsShowFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculator.h" 
using namespace std;

 #define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class clsCurrencyExchangeScreen : protected clsScreen
{
private:
    enum enCurrencyExchangeOptions {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculator = 4, eMainMenu = 5
    };

    static short _ReadCurrencyExchangeMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadNumberBetween(1, 5, "\t\t\t\tEnter Number between 1 to 5? ");
        return Choice;
    }

    static void _ShowCurrencyExchangeMenu()
    {
        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Main Menu");

        cout << BLUE << "\n\n\t\t\t\t======================================================\n\n" << RESET;
        cout << "\t\t\t\t\t" << RED << "Currency Exchange Menu" << RESET << "\n\n";
        cout << BLUE << "\t\t\t\t======================================================\n\n\n" << RESET;

        cout << "\t\t\t\t" << GREEN << "[1]" << RESET << " List Currencies.\n";
        cout << "\t\t\t\t" << GREEN << "[2]" << RESET << " Find Currency.\n";
        cout << "\t\t\t\t" << GREEN << "[3]" << RESET << " Update Rate.\n";
        cout << "\t\t\t\t" << GREEN << "[4]" << RESET << " Currency Calculator.\n";
        cout << "\t\t\t\t" << GREEN << "[5]" << RESET << " Main Menu.\n";

        cout << BLUE << "\n\n\t\t\t\t======================================================\n" << RESET;
    }

    static void _GoBackToCurrencyExchangeMenu()
    {
        cout << "\n\n\t\t\t\tPress any key to go back to Currency Exchange Menu...";
        system("pause>0");
        
    }

    static void _ShowListCurrenciesScreen()
    {
        clsShowListCurrenciesScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsShowFindCurrencyScreen::ShowFindCurrencyScreen();

    }

    static void _ShowUpdateRateScreen()
    {
        clsUpdateRateScreen::ShowUpdateRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculator::ShowCurrencyCalculatorScreen ();
    }

    static void _PerformCurrencyExchangeMenuOption(enCurrencyExchangeOptions CurrencyExchangeMenuOption)
    {
        switch (CurrencyExchangeMenuOption)
        {
        case eListCurrencies:
        {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case eMainMenu:
        {
           
            break;
        }
        }
    }

public:

    static void ShowCurrencyExchangeMenu()
    {
        bool KeepInLoop = true;

        while (KeepInLoop)
        {
            _ShowCurrencyExchangeMenu();
            enCurrencyExchangeOptions Choose = (enCurrencyExchangeOptions)_ReadCurrencyExchangeMenuOption();


            if (Choose == eMainMenu)
            {

                KeepInLoop = false;

            }
            else
            {

                _PerformCurrencyExchangeMenuOption(Choose);

            }
        }
    }
};