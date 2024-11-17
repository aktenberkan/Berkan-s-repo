#include <iostream>
#include<clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	
	cout << "yazini gir ";
	string yazi;

	getline(cin, yazi);
	cout << "Adýnýzý " << yazi << " olarak girdiniz.";
	return 0;
}