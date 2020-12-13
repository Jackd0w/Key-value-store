#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;
/*Нужно переписать контейнер со словарем. Не надо считывать с послед. сортировкой. Попробуй через map.*/

int main() {
	int n;
	cin >> n;
	map<string, set<string>> slovarb;
	for (int i = 0; i < n; i++) {
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
			int q = 0;
			for (auto i : slovarb) {
				if (i.count(word)) {
					q++;
				}
			}
			cout << q << endl;
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