#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

//  ⁄—Ì› «·√·Ê«‰
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define WHITE   "\033[37m"
#define CYAN    "\033[36m"

class clsCurrencyCalculator : protected clsScreen
{

private:

     
    static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Details:")
    {
        string Indent = "\t\t\t\t";

        cout << "\n" << Indent << Title << "\n";
        cout << Indent << BLUE << "___________________________________" << RESET << "\n";
        cout << Indent << "Country    : " << WHITE << Currency.Country() << RESET << "\n";
        cout << Indent << "Code       : " << YELLOW << Currency.CurrencyCode() << RESET << "\n";
        cout << Indent << "Name       : " << WHITE << Currency.CurrencyName() << RESET << "\n";
        cout << Indent << "Rate(1$)   : " << GREEN << Currency.Rate() << RESET << "\n";
        cout << Indent << BLUE << "___________________________________" << RESET << "\n";
    }

     
    static clsCurrency _GetValidCurrency(string Message)
    {
        string Indent = "\t\t\t\t";
        string CurrencyCode;

        cout << Message;
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsExist(CurrencyCode))
        {
            cout << "\n" << Indent << RED << "Currency Code is not found, choose another: " << RESET;
            CurrencyCode = clsInputValidate::ReadString();
        }

        return clsCurrency::FindByCode(CurrencyCode);
    }

     
    static void _PrintCalculationResults(float Amount, clsCurrency FromCurrency, clsCurrency ToCurrency)
    {
        string Indent = "\t\t\t\t";

        _PrintCurrencyCard(FromCurrency, "Convert From:");

        
        float AmountInUSD = FromCurrency.ConvertCurrencyToUsd(Amount);

        cout << "\n" << Indent << "Result In USD:\n";
        cout << Indent << GREEN << Amount << RESET << " " << YELLOW << FromCurrency.CurrencyCode() << RESET
            << " = " << GREEN << AmountInUSD << RESET << " " << YELLOW << "USD" << RESET << "\n";

       
        if (ToCurrency.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\n" << Indent << "Converting from USD to:\n";
        _PrintCurrencyCard(ToCurrency, "To:");

        
        float AmountInToCurrency = ToCurrency.Convert_USD_ToCurrency(AmountInUSD);

        cout << Indent << "Final Result:\n";
        cout << Indent << GREEN << Amount << RESET << " " << YELLOW << FromCurrency.CurrencyCode() << RESET
            << " = " << CYAN << AmountInToCurrency << RESET << " " << YELLOW << ToCurrency.CurrencyCode() << RESET << "\n";
    }

public:

    static void ShowCurrencyCalculatorScreen()
    {
        char KeepInLoop = 'y';
        string Indent = "\t\t\t\t";  

        while (tolower(KeepInLoop) == 'y')
        {
            system("cls");
            _DrawScreenHeader("\t  Currency Calculator Screen");

            
            clsCurrency CurrencyFrom = _GetValidCurrency("\n" + Indent + "Please Enter Currency1 Code: ");
            clsCurrency CurrencyTo = _GetValidCurrency("\n" + Indent + "Please Enter Currency2 Code: ");

           
            cout << "\n" << Indent << "Enter Amount to Exchange: ";
            float Amount = clsInputValidate::ReadNumber<float>();

          
            _PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);

            
            cout << "\n\n" << Indent << "Do you want to perform another calculation? (y/n): ";
            cin >> KeepInLoop;
        }
    }
};