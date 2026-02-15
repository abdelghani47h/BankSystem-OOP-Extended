#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define WHITE   "\033[37m"

class clsShowListCurrenciesScreen : protected clsScreen
{

private:

    static void _PrintCurrencyRecord(clsCurrency Currency)
    {
        cout << setw(8) << left << ""; 

        cout << BLUE << "| " << RESET << setw(30) << left << Currency.Country();

        cout << BLUE << "| " << YELLOW << setw(8) << left << Currency.CurrencyCode() << RESET;

        cout << BLUE << "| " << RESET << setw(40) << left << Currency.CurrencyName();

        cout << BLUE << "| " << GREEN << setw(15) << left << fixed << setprecision(6) << Currency.Rate() << RESET;

        cout << BLUE << "|" << RESET << endl;
    }

    static void _PrintTableLine()
    {
        cout << setw(8) << left << "";
        cout << BLUE << "---------------------------------------------------------------------------------------------------" << RESET << endl;
    }

public:

    static void ShowCurrenciesListScreen()
    {
        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);

    

        _PrintTableLine();

        cout << setw(8) << left << "";
        
        cout << BLUE << "| " << WHITE << left << setw(30) << "Country";
        cout << BLUE << "| " << WHITE << left << setw(8) << "Code";
        cout << BLUE << "| " << WHITE << left << setw(40) << "Name";
        cout << BLUE << "| " << WHITE << left << setw(15) << "Rate/(1$)";
        cout << BLUE << "|" << RESET << endl;

        _PrintTableLine();

      
        if (vCurrencies.size() == 0)
        {
            cout << "\t\t\t\t" << RED << "No Currencies Available In the System!" << RESET;
        }
        else
        {
            for (clsCurrency Currency : vCurrencies)
            {
                _PrintCurrencyRecord(Currency);
            }
        }

       
        _PrintTableLine();
    }
};