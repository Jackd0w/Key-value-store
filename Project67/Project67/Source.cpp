#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int ABS(int x) {
	x = abs(x);
}

void Print(vector <int> v) {
	for (auto i : v) {
		cout << i;
	}
}
int main() {
	int x, n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(begin(v), end(v));
	sort(begin(v), end(v), ABS);
	Print(v);
	return 0;
}