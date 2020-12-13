#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

void Modul(int x) {
	x = abs(x);
	return x;
}

void Print(const vector<int>& v) {
	for (auto i : v) {
		cout << i << " ";
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int&s : v) {
		cin >> s;
	}
	sort(begin(v), end(v));
	sort(begin(v), end(v), Modul);
	cout << endl;
	Print(v);
	return 0;
}