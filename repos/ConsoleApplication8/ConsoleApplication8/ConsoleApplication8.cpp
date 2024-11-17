

/*#include <iostream>
using namespace std;

int main()
{

	

	int even = 500;

	int odd = 500;

	int avgeven = even * (even + 1) / 500;
	int avgodd = odd * odd / 500;
	cout << "average of the odd numbers is " << avgodd << "\n";
	cout << "average of the even numbers is " << avgeven << "\n";

	return 0;

}


int main() {

	int sumodd = 0;
	int sumeven = 0;

	for (int odd = 1; odd <= 999; odd = odd + 2)
		sumodd += odd;
	cout << "average of the odd number is "<<sumodd/500<<"\n";

	for (int even = 2; even <= 1000; even = even + 2)
		sumeven += even;
	cout << "average of the even number is " << sumeven / 500<<"\n";

	return 0;
}

int main()
{

	int hours;
	cout << "please enter your parking time" << "\n";
	cin >> hours;
	if (hours <= 10 && hours != 0)
		cout << "your fee is " << (hours * 12) + 10 << "\n";
	else if (hours > 10 && hours <= 48)
		cout << "your fee is " << ((hours - 10) * 5) + 130 << "\n";
	else
		cout << "time out" << "\n";
		return 0;
}
 
 */
#include <iostream>
using namespace std;

// the program that involves finding determinant of the given number
int main()
{
	int b;
	int a;
	int c;
	cout << "x'in katsayisini giriniz:" << "\n";

	cin >> a ;

	cout << "y'nin katsayisini giriniz:" << "\n";

	cin >> b;

	cout << "z'nin katsayisini giriniz:" << "\n";

	cin >> c;

	cout << "Denkleminizin diskriminanti " << ((b * b) - (4 * a * c)) << "  olarak hesaplanmistir." << "\n"; 

	return 0;





			
	
}




























