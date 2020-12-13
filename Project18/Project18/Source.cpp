#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a;
	// считывание
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	// обработка и вывод
	for (int i = 1; i < n; i++) {
		if (a[i] > 0 && a[i - 1] > 0 || a[i] < 0 && a[i - 1] < 0) {
			if (a[i - 1] < a[i]) {
				cout << a[i - 1] << " " << a[i];
			}
			else {
				cout << a[i] << " " << a[i - 1];
			}
		}
	}
	return 0;
}