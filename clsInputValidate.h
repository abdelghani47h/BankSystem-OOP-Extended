#pragma once
#include <iostream>
#include <string>
#include "clsString.h"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

using namespace std;


class clsInputValidate
{
private:
	string _Value;

public:

	static string ReadString() {

		string S1;

		getline(cin >> ws, S1);
		return S1;
	}


	static  string ReadAccountNumber() {

		return clsString::Upper (ReadString());

	}

	template <typename T>
	static T ReadNumber(string ErrorMassage = "\t\t\t\tInvalid , Enter again: ")
	{
		T Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << RED << ErrorMassage << RESET;

		}

		return Number;

	}

	template <typename T>
	static T ReadNumberBetween(T Min, T Max, string ErrorMassage = "Number is not within range, Enter again:\n")
	{
		
		T Number = ReadNumber<T>();

		
		while (Number < Min || Number > Max)
		{
			cout << RED << ErrorMassage << RESET;
			Number = ReadNumber<T>();
		}

		return Number;
	}



};

