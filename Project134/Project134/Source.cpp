#include <iostream>
using namespace std;

int main() {
	double * p3 = new double[3];
	p3[0] = 1.2;
	p3[1] = 2.28;
	p3[2] = 6.9;
	cout << p3[1] << endl;
	p3 += 1;
	cout << p3[0] << endl;
	delete p3;
	return 0;
}