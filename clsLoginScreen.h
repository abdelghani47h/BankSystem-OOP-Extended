#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
 
 #include "Global.h"

class clsLoginScreen : protected clsScreen
{

private:

    static bool _Login()
    {
        bool LoginFailed = false;
        string UserName, Password;
        short FailedTimes = 0;

        string Indent = "\t\t\t\t\t";

        do
        {
          
            if (LoginFailed)
            {
                FailedTimes++;

               
                if (FailedTimes == 3)
                {
                    cout << "\n" << Indent << RED << "You are locked after 3 faild trials.\n" << RESET;
                    return false;
                }

                cout << "\n" << Indent << RED << "Invalid Username/Password!\n" << RESET;
                cout << Indent << YELLOW << "You have " << (3 - FailedTimes) << " Trial(s) to login.\n\n" << RESET;
            }

            cout << Indent << "Enter User Name: ";
            UserName = clsInputValidate::ReadString();

            cout << Indent << "Enter Password : ";
            Password = clsInputValidate::ReadString();

            CurrentUser = clsUser::Find(UserName, Password);

            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);
      
        CurrentUser.AddRegisterLogInToFile();
        return true;
    }

public:

    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }

};