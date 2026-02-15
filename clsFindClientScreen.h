#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

 
using namespace std;

class clsFindClientScreen : protected clsScreen
{
private:


public:

	static void ShowFindClientScreen() {

		clsScreen::_DrawScreenHeader("\t Find Client Screen");

		string AccountNumber = "";

		cout << "\n\n\t\t\t\t\tEnter account number you search for: ";
		AccountNumber = clsInputValidate::ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n\t\t\t\t\t" << RED << "Account number (" << AccountNumber << ") is not found, choose another one: " << RESET;
			AccountNumber = clsInputValidate::ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::FindClientByAccountNumber(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\n\t\t\t\t\t" << GREEN << "Client Found Successfully :-)" << RESET << endl;
			clsScreen::_PrintFullClientCard(Client);
		}
		else
		{
			cout << "\n\t\t\t\t\t" << RED << "Error: Client was not found." << RESET << endl;
		}


	}
};