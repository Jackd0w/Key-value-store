#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Pearson {
	string name;
	string surname;
	int age;
};

vector<Pearson> GetMoscowPopulation();

void PrintPopulationSize(vector<Pearson> p) {
	cout << p.size();
}

int main() {
	vector<Pearson> people = GetMoscowPopulation();
	PrintPopulationSize(people);
	return 0;
}