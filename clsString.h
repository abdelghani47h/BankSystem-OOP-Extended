//clsString.h
#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsString
{

private:
	string _Value;


public:

	clsString()
	{
		_Value = "";

	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue() {
		return _Value;
	}

	__declspec (property(get = GetValue, put = SetValue))string Value;

    static string NumberToWords(long long n)
    {

        static auto units = [](int x) {
            string arr[] = { "zero","one","two","three","four","five",
                             "six","seven","eight","nine" };
            return arr[x];
            };

        static auto teens = [](int x) {
            string arr[] = { "ten","eleven","twelve","thirteen","fourteen","fifteen",
                             "sixteen","seventeen","eighteen","nineteen" };
            return arr[x];
            };

        static auto tens = [](int x) {
            string arr[] = { "","","twenty","thirty","forty","fifty",
                             "sixty","seventy","eighty","ninety" };
            return arr[x];
            };


        if (n < 10)
            return units(n);

        if (n < 20)
            return teens(n - 10);

        if (n < 100)
        {
            int t = n / 10;
            int u = n % 10;
            return (u == 0) ? tens(t)
                : tens(t) + "-" + units(u);
        }

        if (n < 1000)
        {
            int h = n / 100;
            int r = n % 100;

            return (r == 0)
                ? units(h) + string(" hundred")
                : units(h) + string(" hundred and ") + NumberToWords(r);
        }

        if (n < 1'000'000)
        {
            long long th = n / 1000;
            long long r = n % 1000;

            return (r == 0)
                ? NumberToWords(th) + " thousand"
                : NumberToWords(th) + " thousand " + NumberToWords(r);
        }
        if (n < 1'000'000'000)
        {
            long long m = n / 1'000'000;
            long long r = n % 1'000'000;

            return (r == 0)
                ? NumberToWords(m) + " million"
                : NumberToWords(m) + " million " + NumberToWords(r);
        }
        if (n < 1'000'000'000'000LL)
        {
            long long b = n / 1'000'000'000;
            long long r = n % 1'000'000'000;

            return (r == 0)
                ? NumberToWords(b) + " billion"
                : NumberToWords(b) + " billion " + NumberToWords(r);
        }
        if (n <= 1'000'000'000'000LL)
        {
            long long t = n / 1'000'000'000'000LL;
            long long r = n % 1'000'000'000'000LL;

            return (r == 0)
                ? NumberToWords(t) + " trillion"
                : NumberToWords(t) + " trillion " + NumberToWords(r);
        }

        return "";
    }

	static vector <string> Split(string SourceString, string Dilem = "#//#")
	{
		short pos = 0;
		string sWord = "";
		vector <string > vWord;

		while ((pos = SourceString.find(Dilem)) != string::npos) {

			sWord = SourceString.substr(0, pos);

			if (sWord != "")
			{
				vWord.push_back(sWord);
			}

			SourceString.erase(0, pos + Dilem.length());

		}

		if (SourceString != "")
		{
			vWord.push_back(SourceString);
		}

		return vWord;
	}

	static string Upper(string text) {
		 
		for (char& c : text) {
			c = toupper(c);
		}
		return text;
	}
	 


    static string FormatPermissions(int Permissions)
    {

        if (Permissions == -1 || Permissions == 255+256)
            return "All Permissions";

        if (Permissions == 0)
            return "No Permissions";

        string sPermissions = "";

        if ((Permissions & 1) == 1)   sPermissions += "Show ,";
        if ((Permissions & 2) == 2)   sPermissions += "Add,";
        if ((Permissions & 4) == 4)   sPermissions += "Delete,";
        if ((Permissions & 8) == 8)   sPermissions += "Update,";
        if ((Permissions & 16) == 16) sPermissions += "Find,";
        if ((Permissions & 32) == 32) sPermissions += "Transactions,";
        if ((Permissions & 64) == 64) sPermissions += "Manage Users,";
        if ((Permissions & 128) == 128) sPermissions += "Login Register,";
        if ((Permissions & 256) == 256) sPermissions += "Currency Exchange Screen";
        if (sPermissions.length() > 2)
        {
            sPermissions = sPermissions.substr(0, sPermissions.length() - 2);
        }

        return sPermissions;
    }


   static string EncryptText(string text, short key=2)
    {
        for (char& c : text)
        {
            if (isprint(c))
                c += key;
        }
        return text;
    }

 
   static string DecryptText(string text, short key=2)
    {
        for (char& c : text)
        {
            if (isprint(c))
                c -= key;
        }
        return text;
    }



};

