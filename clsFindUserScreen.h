#pragma once
#include <iostream>
#include <iomanip>
#include "clsString.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
 #include "clsUser.h"

 #define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:

    static void _PrintUser(clsUser User)
    {
        string Indent = "\t\t\t\t\t";

        cout << "\n" << Indent << "User Card:";
        cout << "\n" << Indent << "___________________________________";
        cout << "\n" << Indent << "FirstName   : " << User.FirstName;
        cout << "\n" << Indent << "LastName    : " << User.LastName;
        cout << "\n" << Indent << "Full Name   : " << User.FullName();
        cout << "\n" << Indent << "Email       : " << User.Email;
        cout << "\n" << Indent << "Phone       : " << User.Phone;
        cout << "\n" << Indent << "User Name   : " << User.UserName;
        cout << "\n" << Indent << "Password    : " <<  User.Password ;
        cout << "\n" << Indent << "Permissions : " << clsString::FormatPermissions(User.Permissions);
        cout << "\n" << Indent << "___________________________________\n";
    }

public:

    static void ShowFindUserScreen()
    {
        string Title = "\t  Find User Screen";
        _DrawScreenHeader(Title);

        string Indent = "\t\t\t\t\t";
        string UserName = "";

        cout << "\n" << Indent << "Please Enter User Name: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::isExist(UserName))
        {
            cout << "\n" << Indent << RED << "User Name (" << UserName << ") is not found, Choose another: " << RESET;
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);

        if (!User.IsEmpty())
        {
            cout << "\n" << Indent << GREEN << "User Found Successfully :-)" << RESET << "\n";
            _PrintUser(User);
        }
        else
        {
            cout << "\n" << Indent << RED << "User was not found." << RESET;
        }
    }
};