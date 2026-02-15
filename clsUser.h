#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
using namespace std;

class clsUser : public clsPerson
{
public:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    
   
    
    enum enPermissions {
        pAll = -1,
        pListClients = 1,
        pAddNewClient = 2,
        pDeleteClient = 4,
        pUpdateClients = 8,
        pFindClient = 16,
        pTranactions = 32,
        pManageUsers = 64,
        pLoginRegister = 128,
        pCurrencyExchange=256
    };


    struct stLoginRegisterRecord 
    {
        
        string DateTime;
        string UserName;
        string Password;  
        int Permissions;

    };

private:
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;

    

    bool _MarkForDelete = false;

    static vector<string> _Split(string Line, string Seprator = "#//#")
    {
        vector<string> vWord;
        string sWord = "";
        int pos = 0;

        while ((pos = Line.find(Seprator)) != string::npos)
        {
            sWord = Line.substr(0, pos);
            vWord.push_back(sWord);
            Line.erase(0, pos + Seprator.length());
        }

        if (Line != "")
        {
            vWord.push_back(Line);
        }

        return vWord;
    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static clsUser _ConvertLinetoUserObject(string Line)
    {
        vector<string> vUserData = _Split(Line);

        return clsUser(enMode::UpdateMode,
            vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4],  vUserData[5] ,
            stoi(vUserData[6]));
    }

    string _ConvertUserObjectToLine(string Seperator = "#//#") {

        string Line = "";
        Line += FirstName + Seperator;
        Line += LastName + Seperator;
        Line += Email + Seperator;
        Line += Phone + Seperator;
        Line += UserName + Seperator;
        Line += clsString::EncryptText(Password) + Seperator;
        Line += to_string(Permissions);

        return Line;
    }

    static void _SaveUsersDataToFile(vector <clsUser>& vUsers)  
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out);  

        if (MyFile.is_open())
        {
            string Line;
            for (clsUser& U : vUsers) {
               
                if (U.MarkedForDeleted() == false)
                {
                    Line = U._ConvertUserObjectToLine();
                    MyFile << Line << endl;
                }
            }
            MyFile.close();
        }
    }

    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        

        MyFile.open("Users.txt", ios::out| ios::app); 

        if (MyFile.is_open() )
        {
            MyFile << stDataLine << endl;

        }
        MyFile.close();

    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }
        }

        _SaveUsersDataToFile(_vUsers);
    }

    void _Add() {

         _AddDataLineToFile(_ConvertUserObjectToLine());
    }



    string _PrepareLogInRecordLine(string Seperator = "#//#")
    {
        string LoginRecord = "";
        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += UserName + Seperator;
        LoginRecord += Password + Seperator;
        LoginRecord += to_string(Permissions);
        return LoginRecord;
    }


public:
    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permission)
        : clsPerson(FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password =  Password ;
        _Permissions = Permission;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;


 //------------------------------------------------------------------------------
   
                              // Login Register.
   
    void AddRegisterLogInToFile()
    {
        string stDataLine = _PrepareLogInRecordLine();

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::out|ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }
    

    static stLoginRegisterRecord ConvertUserLoginRigesterToRecord(string LineLoginRegister)
    {
         vector <string> Line = clsString::Split(LineLoginRegister, "#//#");

        stLoginRegisterRecord User;

         if (Line.size() > 0)
         {
             User.DateTime = Line[0];
             User.UserName = Line[1];
             User.Password = clsString::DecryptText(Line[2]);
             User.Permissions = stoi(Line[3]);
         }

        return User;
    }
     

    
    static vector <stLoginRegisterRecord> GetLoginRegisterList()
    {

        vector <stLoginRegisterRecord> vLoginRegisterRecord;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                if (Line != "")
                {
                    vLoginRegisterRecord.push_back(ConvertUserLoginRigesterToRecord(Line));
                }
            }
            MyFile.close();
        }

        return vLoginRegisterRecord;
    }


    //------------------------------------------------------------------------------
    bool CheckAccessPermission(enPermissions Permission) {


        if (this->Permissions  == enPermissions::pAll ) {

            return true;
        }

        if ( ( Permission & this->Permissions) == Permission)
        {
            return true;
        }
        else
            false;

    }
     


    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkForDelete;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    string GetPassword()
    {
        return _Password;
    }

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    int GetPermissions()
    {
        return _Permissions;
    }

    void SetPermissions(int Permission)
    {
        _Permissions = Permission;
    }

    static vector <clsUser> LoadUsersDataFromFile()
    {
        vector <clsUser> vUsers;
        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // Read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {

                
                clsUser Client = _ConvertLinetoUserObject(Line);
                Client.Password=clsString::DecryptText(Client.Password);
                
                vUsers.push_back(Client);

            }

            MyFile.close();

        }
        return vUsers;
    }

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName && clsString::DecryptText(User.Password) == Password)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    static bool isExist(string UserName)
    {
        clsUser User = Find(UserName);
        return (!User.IsEmpty());
    }

    

    enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExist = 2 };

    enSaveResult Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            return svFaildEmptyObject;
        }
        case enMode::UpdateMode:
        {
            _Update();
            return svSucceeded;
        }
        case enMode::AddNewMode:
        {
            if (clsUser::isExist(_UserName))
            {
                return svFaildUserExist;
            }
            else
            {
                _Add();
 
                _Mode = enMode::UpdateMode;
                return svSucceeded;
            }
        }
        }
    }

 
    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkForDelete = true;
                break;
            }
        }
        _SaveUsersDataToFile(_vUsers);

 
        *this = _GetEmptyUserObject();
        return true;
    }

    static clsUser GetAddNewUserObject(string UserName)
    {

        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);

    }

    vector <clsUser> GetUsersList() {

        return LoadUsersDataFromFile();
    }


    void Print()
    {
        string Indent = "\t\t\t\t  ";

        cout << "\n" << Indent << "___________________________________";
        cout << "\n" << Indent << "|            User Card            |";
        cout << "\n" << Indent << "-----------------------------------";
        cout << "\n" << Indent << "| " << setw(12) << left << "First Name" << ": " << FirstName;
        cout << "\n" << Indent << "| " << setw(12) << left << "Last Name" << ": " << LastName;
        cout << "\n" << Indent << "| " << setw(12) << left << "Full Name" << ": " << FullName();
        cout << "\n" << Indent << "| " << setw(12) << left << "Email" << ": " << Email;
        cout << "\n" << Indent << "| " << setw(12) << left << "Phone" << ": " << Phone;
        cout << "\n" << Indent << "-----------------------------------";
        cout << "\n" << Indent << "| " << setw(12) << left << "User Name" << ": " << UserName;
        cout << "\n" << Indent << "| " << setw(12) << left << "Password" << ": " << Password;
        cout << "\n" << Indent << "| " << setw(12) << left << "Permissions" << ": " << Permissions;
        cout << "\n" << Indent << "___________________________________\n";
    }
};