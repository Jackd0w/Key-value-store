#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, num;
	cin >> n;
	num = 1;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != a[i + 1]) {
			num =num + 1;
		}
	}
	cout << num;
	return 0;
}