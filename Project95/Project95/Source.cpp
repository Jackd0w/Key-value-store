#include <iostream>
#include <vector>
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
	string GetFullNameWithHistory(int year) {
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
		vector<string> secondnames;
		vector<string> firstnames;
		for (const auto& i : YNS) {
			if (i.first <= year && i.second.Soname != "") {
				if (i.second.Soname != sn && sn != "") {
					secondnames.push_back(sn);
				}
				sn = i.second.Soname;
			}
			if (i.first <= year && i.second.Name != "") {
				if (i.second.Name != nm && nm != "") {
					firstnames.push_back(nm);
				}
				nm = i.second.Name;
			}
		}
		string secnam_string = "", firstnam_string = "";
		if (secondnames.size() > 0) {
			secnam_string += " (" + secondnames[secondnames.size() - 1];
			if (secondnames.size() > 1) {
				for (int i = secondnames.size() - 1; i > 0; --i) {
					secnam_string += ", " + secondnames[i - 1];
				}
			}
			secnam_string += ")";
		}
		if (firstnames.size() > 0) {
			firstnam_string += " (" + firstnames[firstnames.size() - 1];
			if (firstnames.size() > 1) {
				for (int i = firstnames.size() - 1; i > 0; --i) {
					firstnam_string += ", " + firstnames[i - 1];
				}
			}
			firstnam_string += ")";
		}
		if (nm == "") return sn + secnam_string + " with unknown first name";
		else if (sn == "") return nm + firstnam_string + " with unknown last name";
		else return nm + firstnam_string + " " + sn + secnam_string;
	}
private:
	map<int, FullName> YNS;
};
int main() {
		Person person;

		person.ChangeFirstName(1965, "Polina");
		person.ChangeLastName(1967, "Sergeeva");
		for (int year : {1900, 1965, 1990}) {
			cout << person.GetFullNameWithHistory(year) << endl;
		}

		person.ChangeFirstName(1970, "Appolinaria");
		for (int year : {1969, 1970}) {
			cout << person.GetFullNameWithHistory(year) << endl;
		}

		person.ChangeLastName(1968, "Volkova");
		for (int year : {1969, 1970}) {
			cout << person.GetFullNameWithHistory(year) << endl;
		}

		person.ChangeFirstName(1990, "Polina");
		person.ChangeLastName(1990, "Volkova-Sergeeva");
		cout << person.GetFullNameWithHistory(1990) << endl;

		person.ChangeFirstName(1966, "Pauline");
		cout << person.GetFullNameWithHistory(1966) << endl;

		person.ChangeLastName(1960, "Sergeeva");
		for (int year : {1960, 1967}) {
			cout << person.GetFullNameWithHistory(year) << endl;
		}

		person.ChangeLastName(1961, "Ivanova");
		cout << person.GetFullNameWithHistory(1967) << endl;

	return 0;
}