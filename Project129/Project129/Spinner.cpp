#include <iostream>
using namespace std;

int main() {
	int a, b, c, n_max;
	cin >> a;
	cin >> b;
	cin >> c;
	if (a > c) {
		cout << "Invalid Input!";
	}
	else {
		n_max = floor((c - a) / b);
		cout << n_max;
	}

	return 0;
}