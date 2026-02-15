#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsString.h" 

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

class clsListUserScreen : protected clsScreen
{

private:

    static void _PrintUserRecordLine(clsUser User)
    {
         cout << "     " << setw(12) << left << User.UserName;
        cout << setw(25) << left << User.FullName();
        cout << setw(20) << left << User.Phone; 
        cout << setw(30) << left << User.Email;  
        cout << setw(10) << left <<  User.Password ;
        cout << setw(20) << left << clsString::FormatPermissions(User.Permissions);
        cout << endl;
    }

    static void _PrintTableHeader()
    {
         
        cout << "\n     " << RED << left << setw(12) << "UserName";
        cout << RED << left << setw(25) << "Full Name";
        cout << RED << left << setw(20) << "Phone";
        cout << RED << left << setw(30) << "Email";
        cout << RED << left << setw(10) << "Password";
        cout << RED << left << setw(20) << "Permissions" << RESET;

        
        cout << "\n" << BLUE << "_____________________________________________________________________________________________________________________\n" << RESET;
    }

public:

    static void ShowUsersListScreen()
    {
        vector <clsUser> vUsers = clsUser::LoadUsersDataFromFile();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (Users Count: " + to_string(vUsers.size()) + ")";

        clsScreen::_DrawScreenHeader(Title, SubTitle);
        cout << endl;
        _PrintTableHeader();

        if (vUsers.size() == 0)
        {
            cout << "\n\t\t\t\t" << RED << "No Users Available In the System!" << RESET << endl;
        }
        else
        {
            for (clsUser& U : vUsers)
            {
                _PrintUserRecordLine(U);
            }
        }

         
        cout << BLUE << "_____________________________________________________________________________________________________________________\n" << RESET;
    }

};