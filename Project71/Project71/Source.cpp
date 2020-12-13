#include <iostream>
#include <map>
#include <set>

// класс, почитай тут например, если не знаешь, что это [url]http://cppstudio.com/post/439/[/url]
class WordsDatabase {
	// объявляем синоним для типа std::string const *, т.е. когда будем писать WordPointer, это эквивалентно std::string const*
	// std::string const* - указатель на const std::string, т.е. содержит адрес по которому расположена строка
	using WordPointer = std::string const*;

public:
	WordsDatabase()
	{
	}

	WordPointer insertWord(const std::string& word)// передача по ссылке для экономии ресурсов
	{
		// words.insert(word) - вставляем word в std::set 
		// .first получаем итератор на результат
		// * - разыменовываем итератор, получая ссылку на только что вставленную сторку
		// & - получаем адрес этой строки 
		return &(*words.insert(word).first);
	}

	void makeWordsSynonyms(const std::string& word1, const std::string& word2)
	{
		WordPointer p1 = insertWord(word1);
		WordPointer p2 = insertWord(word2);

		{
			// находим слово в мапе синонимов
			auto it = synonyms.find(p1);
			if (it == synonyms.end()) {
				// если не нашли, вставляем новое значение
				std::set<WordPointer> set;
				set.insert(p2);
				synonyms.insert(std::make_pair(p1, set));
			}
			else {
				// если нашли, просто добавляем ещё один синоним 
				it->second.insert(p2);
			}
		}

		{
			// тоже самое, только наоборот, ищем теперь не первое, а второе слово
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
		// ищем слова в words
		WordPointer p1 = getWordIndex(word1);
		WordPointer p2 = getWordIndex(word2);

		// функция getWordIndex возвращаем nullptr, если слово не нашлось
		if (!p1 || !p2)
			return false;

		// ищем word1 в мапе синонимов
		auto it = synonyms.find(p1);
		if (it == synonyms.end())
			return false;

		// если нашли, ищем в std::set<WordPointer> word2 и возвращаем true, если оно там есть
		return it->second.find(p2) != it->second.end();
	}

	// просто функция для отладки, показывающая содержимое котейнеров
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
	// множество строк
	std::set<std::string> words;
	// std::map, который хранит соответствие адреса строки и множества из адресов других строк(синонимы)
	// адреса используются для экономии памяти
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