#include <iostream>
#include "clsLoginScreen.h"
#include "clsMainScreen.h"
#include "clsCurrencyCalculator.h"
using namespace std;


int main()
{


    while (true) {


        if (clsLoginScreen::ShowLoginScreen())
        {
            clsMainScreen::ShowMainMenue();

        }
        else
        {
            return 0;
        }


    }


    return 0;



}