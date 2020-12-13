#include <iostream>
using namespace std;
int main() {
	int a, b, max, pred_max;
	cin >> a >> b;
	if (a >= b) {
		max = a;
		pred_max = b;
	}
	else {
		max = b;
		pred_max = a;
	}
	while (a != 0) {
		cin >> a;
		if (a == 0) break;
		if (max <= a) {
			pred_max = max;
			max = a;
		}
		else if (pred_max < a) {
			pred_max = a;
		}
	}
	cout << pred_max;
	return 0;
}
