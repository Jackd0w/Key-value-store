#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int a, b, v, t, S;
	int eps = 0.1;
	cin >> a >> b >> v >> t;
	S = v * t;
	if ((S - a <= eps) && (b - S <= eps)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
 	return 0;
}