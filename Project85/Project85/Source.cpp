#include <iostream>
#include <string>
#include <map>
using namespace std;
struct FullName { 
	string Name;
	string Soname;
};
class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		if (YNS.count(year) == 0) YNS[year].Soname = ""; 
		YNS[year].Name = first_name; 
	}
	void ChangeLastName(int year, const string& last_name) {
		if (YNS.count(year) == 0) YNS[year].Name = "";
		YNS[year].Soname = last_name; 
	}
	string GetFullName(int year) {
		if (YNS.size() == 0) { 
			return "Incognito"; 
		}
		else { 
			for (const auto& i : YNS) {
				if (year < i.first) return "Incognito"; 
				break; 
			}
		}
		string nm = "";
		string sn = "";
		for (const auto& i : YNS) {
			if (i.first <= year && i.second.Soname != "") sn = i.second.Soname;
			if (i.first <= year && i.second.Name != "") nm = i.second.Name;
		}
		if (nm == "") return sn + " with unknown first name"; 
		else if (sn == "") return nm + " with unknown last name"; 
		else return nm + " " + sn; 
	}
private: 
	map<int, FullName> YNS; 
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