#include <iostream>
#include <map>
#include <set>
using namespace std;

void AddSynomyns(map<string, set<string>>& synonyms,
	const string& first_word, const string& second_word) {
	synonyms[second_word].insert(first_word);
	synonyms[first_word].insert(first_word);
}

size_t GetSynonymCount(map<string, set<string>>& synonyms,
	const string& first_word) {
	return synonyms[first_word].size();
}

bool AreSynonyms(map<string, set<string>>& synonyms,
	const string& first_word, const string& second_word) {
	return synonyms[first_word].count(second_word) == 1;
}

void TestAddSynonyms() {
	{
		map<string, set<string>> empty;
		AddSynomyns(empty, "a", "b");
		const map<string, set<string>> expected = {
			{"a", {"b"}},
			{"b", {"a"}},
		};
		assert
	}
}

int main() {
	
	return 0;
}