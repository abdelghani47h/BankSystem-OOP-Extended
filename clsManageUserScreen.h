#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsListUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"




using namespace std;

 #define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
 
class clsManageUsersScreen : protected clsScreen
{
private:

    enum enManageUsersMenueOptions {  eListUsers = 1,eAddNewUser = 2,eDeleteUser = 3,eUpdateUser = 4,eFindUser = 5,eMainMenue = 6  };

    static short _ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadNumberBetween(1, 6, "\t\t\t\t\t Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToManageUsersMenue()
    {
        cout <<YELLOW <<"\n\t\t\t\t  Press any key to go back to Manage Users Menue..."<<RESET;
        system("pause>0");
        ShowManageUsersMenue();
    }

    static  void _ShowUsersScreenList()
    {
         
        clsListUserScreen::ShowUsersListScreen();
     
    }

    static void _ShowAddNewUserScreen()
    {

        clsAddNewUserScreen::ShowAddNewUserScreen();

    }

    static void _ShowDeleteUserScreen() {

        clsDeleteUserScreen::ShowDeleteUserScreen();

    }

    static void _ShowUpdateScreen() {

        clsUpdateUserScreen::ShowUpdateUserScreen();

    }

    static void _ShowFindUserScreen() {

        clsFindUserScreen::ShowFindUserScreen();

    }


    static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
    {
        switch (ManageUsersMenueOption)
        {
        case enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowUsersScreenList();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }
        case enManageUsersMenueOptions::eMainMenue:
        {

            break;
        }
        }
    }

public:

    static void ShowManageUsersMenue()
    {
        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << BLUE << "\n\n\n\t\t\t\t======================================================\n\n" << RESET;
        cout << "\t\t\t\t\t\t" << RED << "Manage Users Menue" << RESET << "\n";
        cout << BLUE << "\t\t\t\t======================================================\n\n" << RESET;

        cout << "\t\t\t\t" << GREEN << "[1]" << RESET << " List Users.\n";
        cout << "\t\t\t\t" << GREEN << "[2]" << RESET << " Add New User.\n";
        cout << "\t\t\t\t" << GREEN << "[3]" << RESET << " Delete User.\n";
        cout << "\t\t\t\t" << GREEN << "[4]" << RESET << " Update User.\n";
        cout << "\t\t\t\t" << GREEN << "[5]" << RESET << " Find User.\n";
        cout << "\t\t\t\t" << GREEN << "[6]" << RESET << " Main Menue.\n";

        cout << BLUE << "\n\n\t\t\t\t======================================================\n" << RESET;

        _PerformManageUsersMenueOption((enManageUsersMenueOptions)_ReadManageUsersMenueOption());
    }

     
};