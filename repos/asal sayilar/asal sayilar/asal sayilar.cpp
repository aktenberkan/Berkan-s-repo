
#include <iostream>
using namespace std;

int main()
{
    int number,control,i;
    control = 2;
     
    do {
        cout << "please enter a number(for exit press 0):";
        cin >> number;
        if (number < 2) {
            cout << "please enter a number which is greater than one"<<endl;
            continue;
        }
        
        if (number == 0)
            break;

        for (i = 2; i <= number / 2; i++) {
            if (number % i == 0) {
                control = 1;
                break;
            }
            else {
                control = 2;
            }
        }

        if (control == 1)
            cout << "your number is not prime number"<<endl;
        else
            cout << "your number is prime number"<<endl;
       
    } while (number != 0);
        return 0;
       
        
    
}

