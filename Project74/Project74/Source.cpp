#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	int q;
	cin >> q;
	set<set<string>> slovarb;
	for (int i = 0; i < q; i++) {
		string operation;
		cin >> operation;
		if (operation == "ADD") {
			string word1, word2;
			cin >> word1 >> word2;
			slovarb.insert({ word1, word2 });
		}
		if (operation == "COUNT") {
			string word;
			cin >> word;
			int a = 0;
			for (auto i : slovarb) {
				if (i.count(word)) {
					a++;
				}
			}
			cout << a;
		}
		if (operation == "CHECK") {
			string word1, word2;
			cin >> word1 >> word2;
			if (slovarb.count({ word1, word2 }) || slovarb.count({ word2, word1 })) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}