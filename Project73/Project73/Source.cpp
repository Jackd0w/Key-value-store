#include <string>
#include <iostream>
#include <map>
using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {


		YearFrstNm[year] = first_name;
		for (auto& items : YearFrstNm) {
			for (auto& items1 : Fullname) {
				items.second = items1.first;
			}
		}

	}
	void ChangeLastName(int year, const string& last_name) {


		YearLstNm[year] = last_name;
		for (auto& items3 : YearLstNm) {
			for (auto& items4 : Fullname) {
				items3.second = items4.second;
			}
		}

	}
	string GetFullName(int year) {
		getFullname[year] = Fullname;
		for (auto& i : getFullname) {
			if (i.second.size() == 0)
				return "incognito";
			else if (i.second.size() != 0)

		}
	}
private:
	map <int, string> YearFrstNm;
	map<int, string> YearLstNm;
	map<string, string> Fullname;
	map<int, map<string, string>> getFullname;
};


int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}