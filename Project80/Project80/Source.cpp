#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, num;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(begin(v), end(v), [](const int& x, const int& y) {
		return abs(x) < abs(y);
	});
	for (const auto& i : v) {
		cout << i << " ";
	}
	return 0;
}