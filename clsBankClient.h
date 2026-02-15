#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsDate.h"
#include <vector>
#include <iomanip>
#include <fstream>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"


using namespace std;

class clsBankClient : public clsPerson
{
public:
    struct stTransferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        double Amount;
        double SrcBalanceAfter;
        double DestBalanceAfter;
        string UserName;
    };





private:
    enum class enMode { EmptyMode = 0, UpdateMode = 1,AddNewMode=3 };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    double  _AccountBalance;
    bool   _MarkForDelete = false;



    static clsBankClient _ConvertLineToClientObject(string Line)
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, "#//#");

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }


    string _ConvertRecordToLine(string Seperator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += FirstName + Seperator;
        stClientRecord += LastName + Seperator;
        stClientRecord += Email + Seperator;
        stClientRecord += Phone + Seperator;
        stClientRecord += AccountNumber + Seperator;
        stClientRecord += PinCode + Seperator;
        stClientRecord += to_string(_AccountBalance);

        return stClientRecord;

    }

 
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

   

 
    static void _SaveInfo(vector <clsBankClient> vClients)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out); // Overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsBankClient C : vClients)
            {
                
                
                if (C.MarkForDelete == false) 
                {

                    DataLine = C._ConvertRecordToLine();
                    MyFile << DataLine << endl;

                }
            }
            MyFile.close();
        }
    }



    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C = *this; 
                break;
            }
        }

        _SaveInfo(_vClients);

    }

    void _AddNew() {

        vector <clsBankClient> ClintsData=LoadClientsDataFromFile();

        ClintsData.push_back(*this);

        _SaveInfo(ClintsData);

    }


    // __________________________________________________________________

  /* struct stTransferLogRecord
     {
         string DateTime;
         string SourceAccountNumber;
         string DestinationAccountNumber;
         double Amount;
         double SrcBalanceAfter;
         double DestBalanceAfter;
         string UserName;
     };;*/


    


    string _GetLogTransfer(double amount, clsBankClient& DestinationClient, string UserName, string seprator = "#//#") {


        string TransferLogRecord = "";


        TransferLogRecord += clsDate::GetSystemDateTimeString() + seprator;

        TransferLogRecord += AccountNumber + seprator;

        TransferLogRecord += DestinationClient.AccountNumber + seprator;

        TransferLogRecord += to_string(amount) + seprator;

        TransferLogRecord += to_string(AccountBalance) + seprator;

        TransferLogRecord += to_string(DestinationClient.AccountBalance) + seprator;

        TransferLogRecord += UserName;


        return  TransferLogRecord;

    }


    void _AddTranferLogInToFile(double amount, clsBankClient& DestinationClient, string UserName)
    {
        string stDataLine = _GetLogTransfer(amount, DestinationClient, UserName);

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }
 
    static stTransferLogRecord  _ConvertLineToTransferLogRecord(string Line) {

        vector <string> Info= clsString::Split(Line);
        stTransferLogRecord Record;
        Record.DateTime = Info[0];
        Record.SourceAccountNumber = Info[1];
        Record.DestinationAccountNumber = Info[2];
        Record.Amount = stoi(Info[3]);
        Record.SrcBalanceAfter = stoi(Info[4]);
        Record.DestBalanceAfter = stoi(Info[5]);
        Record.UserName =  Info[6];
        return Record;

    }
    //___________________________________________________________________


public:


  static  vector <stTransferLogRecord> GetTransferLogList()
    {
        fstream MyFile;
        vector <stTransferLogRecord > vTransferLogRecord;

        MyFile.open("TransferLog.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line="";
         

            while (getline(MyFile,Line))
            {
                vTransferLogRecord.push_back(_ConvertLineToTransferLogRecord(Line));
          
            }

        }

        MyFile.is_open();
        return vTransferLogRecord;

    }



    //  Õ„Ì· «·»Ì«‰«  „‰ «·„·› (Static)
    static vector <clsBankClient> LoadClientsDataFromFile()
    {
        vector <clsBankClient> vClients;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // Read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }

        return vClients;

    }
 
    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    void SetMarkForDelete(bool MarkForDelete) {

        _MarkForDelete = MarkForDelete;
    }

    bool GetMarkForDelete() {
        return _MarkForDelete;
    }
    __declspec(property(get = GetMarkForDelete ,put= SetMarkForDelete )) bool MarkForDelete;


    string GetAccountNumber()
    {
        return _AccountNumber;
    }
    __declspec(property(get = GetAccountNumber)) string AccountNumber;

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }
    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }
    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    // --- End Properties ---

   
    


    static clsBankClient FindClientByAccountNumber(string AccountNumber)
    {
        AccountNumber = clsString::Upper(AccountNumber);

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); // Read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    static clsBankClient FindClientByAccountNumber(string AccountNumber, string PinCode)
    {
        AccountNumber = clsString::Upper(AccountNumber);

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }
            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1,svFaildAccountNumberExist=2 };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            
            return enSaveResults::svFaildEmptyObject;

        }

        case enMode::UpdateMode:
        {
            
            _Update();
            return enSaveResults::svSucceeded;

        }
        case enMode::AddNewMode:
        {
            

            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExist;
            }
            else
            {

                
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            

            }
            break;

        }

        }
        return enSaveResults::svFaildEmptyObject;
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::FindClientByAccountNumber(AccountNumber);
        return (!Client1.IsEmpty());
    }

  
   static clsBankClient GetAddNewClientObject(string accountNumber) 
   {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", accountNumber, "", 0);
   }


   bool Delete() {
       bool IsExist = false;
       vector <clsBankClient> Clients  ;
       Clients = LoadClientsDataFromFile();

       for (clsBankClient& C : Clients) {

           if (C.AccountNumber ==this->_AccountNumber)
           {
               C.MarkForDelete = true;
               IsExist = true;
               break;

           }
       }
       if (IsExist==true)
       {
        
           _SaveInfo(Clients);
           *this = _GetEmptyClientObject();
           return true;

       }
       else
       {
           return false;
       }
 
   }


   static double GetTotalBalance() {

       vector <clsBankClient> Clients = clsBankClient::LoadClientsDataFromFile();
       double Total = 0;
       
       
       for (clsBankClient& C : Clients)
       {
           Total += C.AccountBalance;

       }

       return Total;

   }
 
    
   void Deposit(double Amount)
   {
       _AccountBalance += Amount;
       Save(); 
   }

    
   void Withdraw(double Amount)
   {
         
       _AccountBalance -= Amount;   
       Save();  

   }

   bool Transfer(double Amount, clsBankClient& DestinationClient,string UserName)
   {
       if (Amount > AccountBalance)
       {
           return false;
       }


       this->Withdraw(Amount);
       DestinationClient.Deposit(Amount);
       _AddTranferLogInToFile(Amount, DestinationClient, UserName);

       return true;
   }
   

 


};
