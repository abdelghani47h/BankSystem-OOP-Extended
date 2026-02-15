#pragma once
#pragma warning(disable : 4996) 

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class clsDate
{
private:
    short _Day;
    short _Month;
    short _Year;

public:
    clsDate(short Day, short Month, short Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    // ------------------------------------
     // Setters (áÊÚííä ÇáÞíã)
     // ------------------------------------
    void SetDay(short Day) {
        _Day = Day;
    }

    void SetMonth(short Month) {
        _Month = Month;
    }

    void SetYear(short Year) {
        _Year = Year;
    }

    // ------------------------------------
    // Getters (áÌáÈ ÇáÞíã)
    // ------------------------------------
    short GetDay() {
        return _Day;
    }

    short GetMonth() {
        return _Month;
    }

    short GetYear() {
        return _Year;
    }

    
   
    clsDate()
    {
        *this = GetSystemDate();
    }

   
    static clsDate GetSystemDate()
    {
      
        time_t t = time(0);

      
        tm* now = localtime(&t);

        short Day = now->tm_mday;
        short Month = now->tm_mon + 1;   
        short Year = now->tm_year + 1900;

        return clsDate(Day, Month, Year);
    }

    void Print()
    {
        cout << _Day << "/" << _Month << "/" << _Year << endl;
    }

     string  DateToString()
     {
        return to_string(_Day) + "/"+ to_string(_Month )+ "/"+ to_string(_Year) ;
     }

    static string DateToString(clsDate Date)
    {
        return to_string(Date._Day) + "/" + to_string(Date. _Month) + "/" + to_string(Date._Year);
    }


    static string GetSystemTime()
    {
         time_t t = time(0);
        tm* now = localtime(&t);

        short Hour = now->tm_hour;
        short Minute = now->tm_min;
        short Second = now->tm_sec;

         return to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second);
    }
 
  static string GetSystemDateTimeString()
  {
     
      time_t t = time(0);
      tm* now = localtime(&t);

      short Day, Month, Year, Hour, Minute, Second;

      Year = now->tm_year + 1900;
      Month = now->tm_mon + 1;
      Day = now->tm_mday;
      Hour = now->tm_hour;
      Minute = now->tm_min;
      Second = now->tm_sec;
 
      return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - "
          + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second));
  }

};