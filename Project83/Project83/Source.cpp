#include <iostream>

#include <vector>

#include <map>



using namespace std;



class Person {

public:

	void ChangeFirstName(int year, const string& first_name) {


		firstName[year] = first_name;

	}

	void ChangeLastName(int year, const string& last_name) {

		lastName[year] = last_name;


	}

	string GetFullName(int year) {

		bool foundName = false;

		bool foundSurn = false;

		string name, surname;

		int limit = firstName.begin()->first;



		for (int i = year; i >= limit; --i)

		{

			if (firstName.count(i))

			{

				name = firstName[i];

				foundName = true;

				break;

			}

		}

		limit = lastName.begin()->first;

		for (int i = year; i >= limit; --i)

		{

			if (lastName.count(i))

			{

				surname = lastName[i];

				foundSurn = true;

				break;

			}

		}



		if (foundName && foundSurn)

			return name + " " + surname;

		else if (foundName)

			return name + " with unknown last name";

		else if (foundSurn)

			return surname + " with unknown first name";

		else return "Incognito";


	}

private:

	map<int, string> firstName;

	map<int, string> lastName;


};



int main()

{

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





	getchar();

	return 0;

}