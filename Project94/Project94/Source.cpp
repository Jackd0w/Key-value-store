#include<iostream>
using namespace std;

void one_tr(int& x1, int& x2) {
	if (x1 != 0 && x2 != 0) {
		x1 = x1 / 3;
		x2 = x2 / 3;
	}
	else if (x1 == 0 && x2 != 0) {
		x1 = x2 / 3;
		x2 = x2 * 2 / 3;
	}
	else if (x1 != 0 && x2 == 0) {
		x1 = x1 * 2 / 3;
		x2 = x2 / 3;
	}
	
}

int main() {
	float x1, x2;
	cin >> x1 >> x2;
	one_tr(x1, x2);
	cout << x1 << " " << x2;
	return 0;
}