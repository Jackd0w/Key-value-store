#include <iostream>
using namespace std;

int main() {
	float x, y;
	cin >> x >> y;
	if ((x >= -3) && (x <= 2) && (y >= -4) && (y <= 6)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}