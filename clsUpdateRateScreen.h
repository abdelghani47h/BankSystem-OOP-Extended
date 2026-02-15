#pragma once
#include <iostream>
#include <string>
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsScreen.h"

// íİÖá æÖÚ ÇáÃáæÇä İí ãáİ ãäİÕá ãÓÊŞÈáÇğ¡ áßäåÇ ãŞÈæáÉ åäÇ
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define WHITE   "\033[37m"

class clsUpdateRateScreen : protected clsScreen
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

    static void _UpdateCurrency(clsCurrency& Currency)
    {
        string Indent = "\t\t\t\t";

        cout << "\n" << Indent << "Enter New Rate: ";
        float NewRate = clsInputValidate::ReadNumber<float>();

        cout << "\n" << Indent << "Update Currency Rate, are you sure? (y/n)? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Currency.UpdateRate(NewRate);

            // ãáÇÍÙÉ: íÌÈ Ãä íÍÊæí ßáÇÓ ÇáÚãáÉ Úáì ÏÇáÉ Save áíÚãá åĞÇ ÇáÓØÑ ÈÔßá ÕÍíÍ
            Currency.Save();

            cout << "\n" << Indent << GREEN << "Currency Rate Updated Successfully :-)\n" << RESET;
            _PrintCurrencyCard(Currency);
        }
        else
        {
            cout << "\n" << Indent << RED << "Update Cancelled.\n" << RESET;
        }
    }

public:

    static void ShowUpdateRateScreen()
    {
        _DrawScreenHeader("\tUpdate Currency Screen");
        string Indent = "\t\t\t\t";

        cout << "\n" << Indent << "Find By: " << GREEN << "[1]" << RESET << " Code or " << GREEN << "[2]" << RESET << " Country ? ";
        short Answer = clsInputValidate::ReadNumberBetween(1, 2);

        clsCurrency Currency = clsCurrency:: GetEmptyCurrencyObject();

        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\n" << Indent << "Please Enter Currency Code: ";
            CurrencyCode = clsInputValidate::ReadString();
            Currency = clsCurrency::FindByCode(CurrencyCode);
        }
        else
        {
            string Country;
            cout << "\n" << Indent << "Please Enter Country Name: ";
            Country = clsInputValidate::ReadString();
            Currency = clsCurrency::FindByCountry(Country);
        }

        
        if (Currency.IsEmpty())
        {

            cout << "\n" << Indent << RED << "Currency Not Found :-(\n" << RESET;

        }
        else
        {
            
            _PrintCurrencyCard(Currency);
            _UpdateCurrency(Currency);

        }
    }
};