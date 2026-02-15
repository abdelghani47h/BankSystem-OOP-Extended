#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:

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
            Permissions |= (int)clsUser::enPermissions::pListClients;

        cout << "\n" << Indent << "Add New Client?   y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= (int)clsUser::enPermissions::pAddNewClient;

        cout << "\n" << Indent << "Delete Client?    y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= (int)clsUser::enPermissions::pDeleteClient;

        cout << "\n" << Indent << "Update Client?    y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= (int)clsUser::enPermissions::pUpdateClients;

        cout << "\n" << Indent << "Find Client?      y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= (int)clsUser::enPermissions::pFindClient;

        cout << "\n" << Indent << "Transactions?     y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= (int)clsUser::enPermissions::pTranactions;

        cout << "\n" << Indent << "Manage Users?     y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= (int)clsUser::enPermissions::pManageUsers;

        cout << "\n" << Indent << "Login Register?     y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions |= (int)clsUser::enPermissions::pLoginRegister;


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
        User.Password = clsInputValidate::ReadString();

        cout << "\n" << Indent << "Permissions: ";
        User.Permissions = _ReadPermissionsToSet();
    }

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
        cout << "\n" << Indent << "Password    : " << User.Password;
        cout << "\n" << Indent << "Permissions : " << clsString::FormatPermissions(User.Permissions);
        cout << "\n" << Indent << "___________________________________\n";
    }

public:

    static void ShowAddNewUserScreen()
    {
        string Title = "\t  Add New User Screen";
        _DrawScreenHeader(Title);

        string UserName = "";

        cout << "\n\n\t\t\t\t\tPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();

        while (clsUser::isExist(UserName))
        {
            cout << "\n\t\t\t\t\t" << RED << "UserName (" << UserName << ") already exists, Choose another: " << RESET;
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        char Answer = 'n';
        cout << "\n\t\t\t\t\tAre you sure you want to add this User? " << GREEN << "y" << RESET << "/" << RED << "n" << RESET << "? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            clsUser::enSaveResult SaveResult;
            SaveResult = NewUser.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResult::svSucceeded:
            {
                cout << "\n\t\t\t\t\t" << GREEN << "User Added Successfully! Here are the details:" << RESET;
                
                cout << YELLOW; _PrintUser(NewUser); cout << RESET;
               
                break;
            }
            case clsUser::enSaveResult::svFaildEmptyObject:
            {
                cout << "\n\t\t\t\t\t" << RED << "Error: User was not saved because it's Empty." << RESET << endl;
                break;
            }
            case clsUser::enSaveResult::svFaildUserExist:
            {
                cout << "\n\t\t\t\t\t" << RED << "Error: UserName already exists!" << RESET << endl;
                break;
            }
            }
        }
        else
        {
            cout << "\n\t\t\t\t\t" << YELLOW << "User Add Operation Cancelled." << RESET << endl;
        }
    }
};