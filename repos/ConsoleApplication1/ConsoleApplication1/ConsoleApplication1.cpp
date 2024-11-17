6k

#include <iostream>
using namespace std;

int main()
{
	char operation;
	double number1, number2;

	cout << "Enter first number: ";
	cin >> number1;

	cout << "Enter an operation (+, -, *, /):" ;
	cin >> operation;

	cout << "Enter second number";
	cin >> number2;

	
	switch (operation)
	{
	case '+':
		cout << number1 << " + " << number2 << " = " << number1 + number2;
		break;
	case '-':
		cout << number1 << " - " << number2 << " = " << number1 - number2;
		break;
	case '*':
		cout << number1 << " * " << number2 << " = " << number1 * number2;
		break;
	case '/':
		cout << number1 << " / " << number2 << " = " << number1 / number2;
		break;
	default:
		cout << "ERROR!...";
		break;
	}
	return 0;
}