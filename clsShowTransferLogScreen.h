#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankClient.h"

using namespace std;


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"

class clsShowTransferLogScreen : protected clsScreen
{
private:

    static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {
        cout << setw(8) << left << "" << BLUE << "| " << RESET << setw(23) << left << TransferLogRecord.DateTime;
        cout << BLUE << "| " << RESET << setw(8) << left << TransferLogRecord.SourceAccountNumber;
        cout << BLUE << "| " << RESET << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
        cout << BLUE << "| " << GREEN << setw(8) << left << TransferLogRecord.Amount;
        cout << BLUE << "| " << YELLOW << setw(10) << left << TransferLogRecord.SrcBalanceAfter;
        cout << BLUE << "| " << YELLOW << setw(10) << left << TransferLogRecord.DestBalanceAfter;
        cout << BLUE << "| " << RESET << setw(8) << left << TransferLogRecord.UserName;
    }

public:

    static void ShowTransferLogScreen()
    {
       

        vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << BLUE << "\n\t________________________________________________________________________________________\n" << RESET;
        cout << setw(8) << left << "" << BLUE << "| "  << left << setw(23) << "Date/Time";
        cout << BLUE << "| "   << left << setw(8) << "s.Acct";
        cout << BLUE << "| "   << left << setw(8) << "d.Acct";
        cout << BLUE << "| "   << left << setw(8) << "Amount";
        cout << BLUE << "| "   << left << setw(10) << "s.Balance";
        cout << BLUE << "| "   << left << setw(10) << "d.Balance";
        cout << BLUE << "| "   << left << setw(8) << "User";
        cout << setw(8) << left << "" << BLUE << "\n\t________________________________________________________________________________________\n" << RESET;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else
        {
            for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
            {
                _PrintTransferLogRecordLine(Record);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << BLUE << "\n\t________________________________________________________________________________________\n" << RESET;
    }
};