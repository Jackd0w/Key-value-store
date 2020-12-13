#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, string> s;
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		string OperationType;
		cin >> OperationType;
		if (OperationType == "ADD") {
			string word1, word2;
			s.insert(word1, word2);
		}
		else if (OperationType == "COUNT") {
			string IsSyn;

			cin >> IsSyn;

			int count = 0;

			for (const auto& c : s) {

				if ((c.first == IsSyn) || (c.second == IsSyn)) {

					++count;

				}
			}
		}
		else if (OperationType == "CHECK") {
			string IS1, IS2;
			cin >> IS1 >> IS2;
			if (s[IS1] == IS2 || s[IS2] == IS1) {
				cout << "YES";
			}
			else {
				cout << "NO";
			}
		}
	}
	return 0;
}