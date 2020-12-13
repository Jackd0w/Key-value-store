#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
using sorted_pair = pair<string, string>; 
sorted_pair make_sorted_pair(const std::string& word1, const string& word2) {
	return (word1 <= word2) ? make_pair(word1, word2) : make_pair(word2, word1); 
}
bool CHECK(const set<sorted_pair>& synonyms, const string& word1, const string& word2) { 
	return synonyms.count(make_sorted_pair(word1, word2)) != 0; 
}
void ADD(set<sorted_pair>& synonyms, map<string, unsigned>& synonyms_count, const string& word1, const string& word2) {
	if (CHECK(synonyms, word1, word2)) return;
	++synonyms_count[word1]; 
	++synonyms_count[word2];
	synonyms.insert(make_sorted_pair(word1, word2)); 

}
int main() {
	set<sorted_pair> s;  
	map<string, unsigned> s_c;  
	int i;
	string comand, word1, word2;
	cin >> i; 
	for (i; i > 0; i--) {
		cin >> comand; 
		if (comand == "ADD") {
			cin >> word1 >> word2; 
			ADD(s, s_c, word1, word2); 
		}
		else if (comand == "COUNT") {
			string word;
			cin >> word; 
			cout << s_c[word] << endl; 
		}
		else if (comand == "CHECK") {
			string word1, word2;
			cin >> word1 >> word2; 

			if (CHECK(s, word1, word2)) { 
				cout << "YES" << endl; 
			}
			else cout << "NO" << endl; 
		}
	}
	return 0;
}