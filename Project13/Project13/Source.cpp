#include <iostream>
using namespace std;

int main() {
int x, y1, y2, y;
cin >> x >> y;
if ((x >= -5) && (x <= 0))  {
	y1 = x + 3;
	if (y <= y1) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}
else if ((x >= 0) && (x <= 5)) {
	y2 = -x + 3;
	if (y <= y2) {
		cout << "YES";
	}
}
else {
	cout << "NO";
}
return 0;
}