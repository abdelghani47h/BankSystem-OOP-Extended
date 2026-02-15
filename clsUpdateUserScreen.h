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
#define RESET   "\033[0m"

class clsUpdateUserScreen : protected clsScreen
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

    static int _ReadPermissionsToSet()
    {
        int Permissions = 0;
        char Answer = 'n';
        string Indent = "\t\t\t\t\t";

        cout << "\n" << Indent << "Do you want to give full access? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            return -1;
        }

        cout << "\n" << Indent << "Do you want to give access to : \n";

        cout << "\n" << Indent << "Show Client List? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= clsUser::enPermissions::pListClients;

        cout << "\n" << Indent << "Add New Client?   y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= clsUser::enPermissions::pAddNewClient;

        cout << "\n" << Indent << "Delete Client?    y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= clsUser::enPermissions::pDeleteClient;

        cout << "\n" << Indent << "Update Client?    y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= clsUser::enPermissions::pUpdateClients;

        cout << "\n" << Indent << "Find Client?      y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= clsUser::enPermissions::pFindClient;

        cout << "\n" << Indent << "Transactions?     y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= clsUser::enPermissions::pTranactions;

        cout << "\n" << Indent << "Manage Users?     y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= clsUser::enPermissions::pManageUsers;

        cout << "\n" << Indent << "Register Record?     y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= clsUser::enPermissions::pLoginRegister;

        return Permissions;
    }

    static void _ReadUserInfo(clsUser& User)
    {
        string Indent = "\t\t\t\t\t";

        cout << "\n" << Indent << "First Name: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\n" << Indent << "Last Name: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\n" << Indent << "Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\n" << Indent << "Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\n" << Indent << "Password: ";
        User.Password = clsInputValidate::ReadString()  ;

        cout << "\n" << Indent << "Permissions: ";
        User.Permissions = _ReadPermissionsToSet();
    }

public:

    static void ShowUpdateUserScreen()
    {
        string Title = "\t  Update User Screen";
        _DrawScreenHeader(Title);

        string Indent = "\t\t\t\t\t";
        string UserName = "";

        cout << "\n" << Indent << "Please Enter User Name: ";
        UserName = clsInputValidate::ReadString();

 
        while (!clsUser::isExist(UserName))
        {
            cout << "\n" << Indent << RED << "User Name (" << UserName << ") is Not Found, Choose another: " << RESET;
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);

        _PrintUser(User);

        cout << "\n" << Indent << "Update User Info:";
        cout << "\n" << Indent << "____________________\n";

        _ReadUserInfo(User);

        char Answer = 'n';
        cout << "\n" << Indent << "Are you sure you want to Update this User? " << GREEN << "y" << RESET << "/" << RED << "n" << RESET << "? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            clsUser::enSaveResult SaveResult;
            SaveResult = User.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResult::svSucceeded:
            {
                cout << "\n" << Indent << GREEN << "User Updated Successfully :-)" << RESET << "\n";
                _PrintUser(User);
                break;
            }
            case clsUser::enSaveResult::svFaildEmptyObject:
            {
                cout << "\n" << Indent << RED << "Error User was not saved because it's Empty" << RESET;
                break;
            }
           
            case clsUser::enSaveResult::svFaildUserExist:
            {
                cout << "\n" << Indent << RED << "Error User was not saved because UserName is used!" << RESET << "\n";
                break;
            }
            }
        }
        else
        {
            cout << "\n" << Indent << YELLOW << "Update Operation Cancelled." << RESET << endl;
        }
    }

};