#include <iostream>
using namespace std;

int main() {
	int a1, b1, a2, b2, a, b;
	cin >> a1 >> b1 >> a2 >> b2;
	a = a1 + a2;
	b = b1 + b2;
	if (a > b) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}