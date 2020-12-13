#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float a, b;
	cin >> a >> b;
	if (a <= 6 && a >= -4) {
		if (b <= 2 && a >= -3) {
			cout << "YES";
		}
	}
	else {
		cout << "NO";
	} 
		return 0;
}