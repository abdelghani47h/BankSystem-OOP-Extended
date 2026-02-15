#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsString.h"
#include "clsUser.h"

using namespace std;

 
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class clsLoginRegisterScreen : protected clsScreen
{
private:

    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {
        
        cout << setw(8) << left << "" << BLUE << "| " << RESET << setw(35) << left << LoginRegisterRecord.DateTime;
        cout << BLUE << "| " << RESET << setw(20) << left << LoginRegisterRecord.UserName;
        cout << BLUE << "| " << RESET << setw(20) << left << LoginRegisterRecord.Password;
        cout << BLUE << "| " << RESET << setw(10) << left << clsString::FormatPermissions(LoginRegisterRecord.Permissions ) ;
    }

public:

    static void ShowLoginRegisterScreen()
    {
        

        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

       
        _DrawScreenHeader(Title, SubTitle);

        
        cout << setw(8) << left << "" << BLUE << "\n\t__________________________________________________________________________________________________________\n" << RESET;
        cout << setw(8) << left << "" << BLUE << "| " << MAGENTA << left << setw(35) << "Date/Time";
        cout << BLUE << "| " << MAGENTA << left << setw(20) << "UserName";
        cout << BLUE << "| " << MAGENTA << left << setw(20) << "Password";
        cout << BLUE << "| " << MAGENTA << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << BLUE << "\n\t__________________________________________________________________________________________________________\n" << RESET;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\t" << RED << "No Logins Available In the System!" << RESET;
        else
        {
            for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
            {
                _PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << BLUE << "\n\t__________________________________________________________________________________________________________\n" << RESET;
    }

};