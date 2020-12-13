#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int&s : v) {
		cin >> s;
		s = abs(s);
	}
	cout << sort(begin(v), end(v));
	return 0;
}