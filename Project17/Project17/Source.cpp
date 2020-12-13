#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, t;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n / 2; i++) {
		t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
	return 0;
}