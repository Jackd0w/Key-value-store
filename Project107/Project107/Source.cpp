#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string line;
	ifstream input;
	input.open("124.txt");
	while (getline(input, line)) {
		cout << line;
	}
	return 0;
}