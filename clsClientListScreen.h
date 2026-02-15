#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

class clsClientListScreen : protected  clsScreen
{

public :
    
   static void PrintClientRecordLine(clsBankClient Client)
    {
       
        cout << "\t" << BLUE << "| " << RESET << setw(15) << left << Client.AccountNumber;
        cout << BLUE << "| " << RESET << setw(20) << left << Client.FullName();
        cout << BLUE << "| " << RESET << setw(12) << left << Client.Phone;
        cout << BLUE << "| " << RESET << setw(36) << left << Client.Email;  
        cout << BLUE << "| " << RESET << setw(10) << left << Client.PinCode;
        cout << BLUE << "| " << RESET << setw(12) << left << fixed << setprecision(1) << Client.AccountBalance;
    }

   static void ShowClientsList()
   {

       
       vector <clsBankClient> Clients = clsBankClient::LoadClientsDataFromFile();

       string Title = "\t  Client List Screen";
       string SubTitle = "\t    (" + to_string(Clients.size()) + ") Client(s).";
       clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << BLUE << "\n\t_______________________________________________________";
       cout << "________________________________________________________\n" << endl;

        cout << "\t" << BLUE << "| " << RED << left << setw(15) << "Acc. Number";
       cout << BLUE << "| " << RED << left << setw(20) << "Client Name";
       cout << BLUE << "| " << RED << left << setw(12) << "Phone";
       cout << BLUE << "| " << RED << left << setw(36) << "Email";
       cout << BLUE << "| " << RED << left << setw(10) << "Pin Code";
       cout << BLUE << "| " << RED << left << setw(12) << "Balance";

       cout << BLUE << "\n\t_______________________________________________________";
       cout << "________________________________________________________\n" << endl;

       if (Clients.size() == 0)
       {
       
           cout << "\t\t\t\t" << RED << "No Clients Available In the System!" << RESET;
       }
       else
       {
           for (clsBankClient& Client : Clients)
           {

               PrintClientRecordLine(Client);
               cout << endl;
           }
       }
       cout << BLUE << "\n\t_______________________________________________________";
       cout << "________________________________________________________\n" << RESET << endl;
   }

};

