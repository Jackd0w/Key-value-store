#include<iostream>
#include<cmath>
using namespace std;
int main() {
	 double A, B, C, x1, x2, dscr;
	cin >> A >> B >> C;
	if (A != 0) {
		dscr = B * B - 4 * A * C;
		if (dscr > 0) {
			x1 = (-B + sqrt(dscr)) / (2 * A);
			x2 = (-B - sqrt(dscr)) / (2 * A);
			cout << x1 << " " << x2;
		}
		else if (dscr == 0) {
			x1 = (-B + sqrt(dscr)) / (2 * A);
			cout << x1;
		}
		else if (dscr < 0) {
		}
	}
	else if (A == 0) {
		x1 = -C / B;
		cout << x1;
	}
	return 0;
}