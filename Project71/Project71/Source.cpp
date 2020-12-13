#include <iostream>
#include <map>
#include <set>

// �����, ������� ��� ��������, ���� �� ������, ��� ��� [url]http://cppstudio.com/post/439/[/url]
class WordsDatabase {
	// ��������� ������� ��� ���� std::string const *, �.�. ����� ����� ������ WordPointer, ��� ������������ std::string const*
	// std::string const* - ��������� �� const std::string, �.�. �������� ����� �� �������� ����������� ������
	using WordPointer = std::string const*;

public:
	WordsDatabase()
	{
	}

	WordPointer insertWord(const std::string& word)// �������� �� ������ ��� �������� ��������
	{
		// words.insert(word) - ��������� word � std::set 
		// .first �������� �������� �� ���������
		// * - �������������� ��������, ������� ������ �� ������ ��� ����������� ������
		// & - �������� ����� ���� ������ 
		return &(*words.insert(word).first);
	}

	void makeWordsSynonyms(const std::string& word1, const std::string& word2)
	{
		WordPointer p1 = insertWord(word1);
		WordPointer p2 = insertWord(word2);

		{
			// ������� ����� � ���� ���������
			auto it = synonyms.find(p1);
			if (it == synonyms.end()) {
				// ���� �� �����, ��������� ����� ��������
				std::set<WordPointer> set;
				set.insert(p2);
				synonyms.insert(std::make_pair(p1, set));
			}
			else {
				// ���� �����, ������ ��������� ��� ���� ������� 
				it->second.insert(p2);
			}
		}

		{
			// ���� �����, ������ ��������, ���� ������ �� ������, � ������ �����
			auto it = synonyms.find(p2);
			if (it == synonyms.end()) {
				std::set<WordPointer> set;
				set.insert(p1);
				synonyms.insert(std::make_pair(p2, set));
			}
			else {
				it->second.insert(p1);
			}
		}
	}

	bool isWordsSynonyms(const std::string& word1, const std::string& word2)
	{
		// ���� ����� � words
		WordPointer p1 = getWordIndex(word1);
		WordPointer p2 = getWordIndex(word2);

		// ������� getWordIndex ���������� nullptr, ���� ����� �� �������
		if (!p1 || !p2)
			return false;

		// ���� word1 � ���� ���������
		auto it = synonyms.find(p1);
		if (it == synonyms.end())
			return false;

		// ���� �����, ���� � std::set<WordPointer> word2 � ���������� true, ���� ��� ��� ����
		return it->second.find(p2) != it->second.end();
	}

	// ������ ������� ��� �������, ������������ ���������� ����������
	void debug()
	{
		std::cout << "words: " << std::endl;
		for (auto& word : words)
			std::cout << word << " (" << &word << ")" << std::endl;
		std::cout << std::endl;

		std::cout << "synonyms: " << std::endl;
		for (auto& pair : synonyms) {
			std::cout << pair.first << ": ";
			for (auto& value : pair.second) {
				std::cout << value << ", ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

private:
	// ��������� �����
	std::set<std::string> words;
	// std::map, ������� ������ ������������ ������ ������ � ��������� �� ������� ������ �����(��������)
	// ������ ������������ ��� �������� ������
	std::map<WordPointer, std::set<WordPointer>> synonyms;

	WordPointer getWordIndex(const std::string& word)
	{
		auto it = words.find(word);
		if (it == words.end())
			return nullptr;
		return &(*it);
	}
};

int main()
{
	WordsDatabase db;

	db.makeWordsSynonyms("car", "truck");
	db.makeWordsSynonyms("bicycle", "bike");
	db.makeWordsSynonyms("programmer", "freak");
	db.makeWordsSynonyms("beautiful", "lovely");
	db.makeWordsSynonyms("beautiful", "lovely");
	db.makeWordsSynonyms("beautiful", "fine");
	db.makeWordsSynonyms("beautiful", "nice");
	db.insertWord("something");

	std::cout << db.isWordsSynonyms("truck", "car") << std::endl;
	std::cout << db.isWordsSynonyms("car", "bike") << std::endl;
	std::cout << db.isWordsSynonyms("beautiful", "fine") << std::endl;
	std::cout << db.isWordsSynonyms("something", "bike") << std::endl;

	return 0;
}