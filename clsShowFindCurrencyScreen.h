#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define WHITE   "\033[37m"

class  clsShowFindCurrencyScreen  : protected clsScreen
{
private:

    static void _PrintCurrencyCard(clsCurrency Currency)
    {
         
        string Indent = "\t\t\t\t";

        cout << "\n" << Indent << "Currency Details:\n";
        cout << Indent << BLUE << "___________________________________________" << RESET << "\n";

        cout << "\n" << Indent << "Country    : " << WHITE << Currency.Country() << RESET;
        cout << "\n" << Indent << "Code       : " << YELLOW << Currency.CurrencyCode() << RESET;
        cout << "\n" << Indent << "Name       : " << WHITE << Currency.CurrencyName() << RESET;
        cout << "\n" << Indent << "Rate(1$)   : " << GREEN << Currency.Rate() << RESET;

        cout << "\n" << Indent << BLUE << "___________________________________________" << RESET << "\n";
    }

    static void _ShowResults(clsCurrency Currency)
    {
        string Indent = "\t\t\t\t";

        if (!Currency.IsEmpty())
        {
            cout << "\n" << Indent << GREEN << "Currency Found :-)\n" << RESET;
            _PrintCurrencyCard(Currency);
        }
        else
        {
            cout << "\n" << Indent << RED << "Currency Was not Found :-(\n" << RESET;
        }
    }

public:

    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t  Find Currency Screen");

        string Indent = "\t\t\t\t";

        cout << "\n" << Indent << "Find By: " << GREEN << "[1]" << RESET << " Code or " << GREEN << "[2]" << RESET << " Country ? ";
        short Answer = 1;

        Answer=clsInputValidate::ReadNumberBetween(1,2);

        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\n" << Indent << "Please Enter Currency Code: ";
            CurrencyCode = clsInputValidate::ReadString();

            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {
            string Country;
            cout << "\n" << Indent << "Please Enter Country Name: ";
            Country = clsInputValidate::ReadString();

            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency);
        }

    }



};