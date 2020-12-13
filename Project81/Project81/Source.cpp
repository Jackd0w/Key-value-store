#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string lower(const string& s) {
	string result;
	for (auto i : s) {
		result += tolower(i);
	}
	return result;
}

bool stroka(const string&a, const string&b) {
	return lower(a) < lower(b);
}
int main() {
	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		v.push_back(x);
	}
	sort(begin(v), end(v), stroka);
	for (auto& i : v) {
		cout << i << " ";
	}
	return 0;
}