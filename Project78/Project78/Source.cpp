#include <iostream>
using namespace std;

int main() {
	int val = 9;
	int *ptrval = &val;
	cout << *ptrval << endl;
	return 0;
}