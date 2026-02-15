#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"

using namespace std;

class clsCurrency
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;

    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;

    static clsCurrency _ConvertLineToRecord(string Line, string Seperator = "#//#")
    {
        vector<string> Info = clsString::Split(Line, Seperator);
        
        if (Info.size() < 4) return  GetEmptyCurrencyObject();

        return clsCurrency(UpdateMode, Info[0], Info[1], Info[2], stod(Info[3]));
    }

    static string _ConvertRecordToLine(clsCurrency Currency, string Seperator = "#//#")
    {
        string stCurrencyRecord = "";
        stCurrencyRecord += Currency.Country() + Seperator;
        stCurrencyRecord += Currency.CurrencyCode() + Seperator;
        stCurrencyRecord += Currency.CurrencyName() + Seperator;
        stCurrencyRecord += to_string(Currency.Rate());
        return stCurrencyRecord;
    }

    static vector <clsCurrency> _LoadDataFromFile()
    {
        vector <clsCurrency> vCurrencies;
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in); // Read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                if (!Line.empty())
                {
                    clsCurrency Currency = _ConvertLineToRecord(Line);
                    vCurrencies.push_back(Currency);
                }
            }
            MyFile.close();
        }
        return vCurrencies;
    }

    static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencies)
    {
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::out); // Write Mode (Overwrites file)

        if (MyFile.is_open())
        {
            for (clsCurrency& C : vCurrencies)
            {
                // ·« ‰Õ›Ÿ «·ﬂ«∆‰«  «·›«—€…
                if (!C.IsEmpty())
                {
                    MyFile << _ConvertRecordToLine(C) << endl;
                }
            }
            MyFile.close();
        }
    }

    void _Update()
    {
        vector <clsCurrency> _vCurrencies = _LoadDataFromFile();

        for (clsCurrency& C : _vCurrencies)
        {
            if (C.CurrencyCode() == CurrencyCode())
            {
                C = *this;
                break;
            }
        }
        _SaveCurrencyDataToFile(_vCurrencies);
    }

  
public:
    // Constructor
    clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }

    // Getters (Read-Only properties should be const)
    string Country() const { return _Country; }
    string CurrencyCode() const { return _CurrencyCode; }
    string CurrencyName() const { return _CurrencyName; }
    float Rate() const { return _Rate; }

    // Setter for Rate
    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Mode = UpdateMode; 
    }

    bool IsEmpty() const
    {
        return (_Mode == EmptyMode);
    }

    // Static Methods (Utility)
    static clsCurrency FindByCode(string CurrencyCode)
    {
        CurrencyCode = clsString::Upper(CurrencyCode);
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToRecord(Line);
                if (Currency.CurrencyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return Currency;
                }
            }
            MyFile.close();
        }
        return  GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCountry(string Country)
    {
        Country = clsString::Upper(Country);
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToRecord(Line);
                if (clsString::Upper(Currency.Country()) == Country)
                {
                    MyFile.close();
                    return Currency;
                }
            }
            MyFile.close();
        }
        return  GetEmptyCurrencyObject();
    }

    static bool IsExist(string CurrencyCode)
    {
        clsCurrency C = FindByCode(CurrencyCode);
        return (!C.IsEmpty());
    }

    static vector <clsCurrency> GetCurrenciesList()
    {
        return _LoadDataFromFile();
    }

    // Main Save Method
    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildCurrencyCodeNull = 2 };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case EmptyMode:
            return svFaildEmptyObject;

        case UpdateMode:
            _Update();
            return svSucceeded;
        }
        return svFaildEmptyObject;
    }

    static clsCurrency  GetEmptyCurrencyObject()
    {
        return clsCurrency(EmptyMode, "", "", "", 0);
    }

    float ConvertCurrencyToUsd(float Currency)
    {

        return (Currency / Rate());

    }

    float Convert_USD_ToCurrency(float USD)
    {

        return (USD * Rate());

    }

    static bool isExist(string Code) {
      clsCurrency C= FindByCode(Code);
      return !C.IsEmpty();
    }

};