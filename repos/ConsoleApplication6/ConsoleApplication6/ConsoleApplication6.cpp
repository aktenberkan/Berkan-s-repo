#include <iostream>
#include<clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	
	cout << "yazini gir ";
	string yazi;

	getline(cin, yazi);
	cout << "Ad�n�z� " << yazi << " olarak girdiniz.";
	return 0;
}