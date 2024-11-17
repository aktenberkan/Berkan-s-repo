// carpim tablosu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    short int number=1, i = 1;
    while (number!=0) {
        i = 1;

        cout << "please enter a number between 1-10(exit:0)" << "\n";
        cin >> number;
        if (number < 0 || number > 10) {
            cout << "your number is not between in 1-10"<<"\n";

        }
        else {
            while (i <= 10 && number!=0) {
                cout << number << "x" << i << "=" << number * i << "\n\n";
                i++;
              
            }

        }

    }
}
