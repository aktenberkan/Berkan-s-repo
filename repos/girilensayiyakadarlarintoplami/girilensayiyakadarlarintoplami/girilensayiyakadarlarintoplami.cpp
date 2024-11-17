#include <iostream>
using namespace std;

int main() {
    int n, i;
    int sum = 0;
    cin >> n;
    for (i = n; i > 0; i--) {
        sum = sum + i;
    }
    cout << sum;


}