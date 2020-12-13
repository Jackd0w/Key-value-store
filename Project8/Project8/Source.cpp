#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int hh, mm, n, T, C, M;
	cin >> n;
	T = n * 45 + (n - 1) * 5;
	C = T / 60 + 8;
	cout << C / 10 << C % 10 << ":";
	M = T % 60;
	cout << M / 10 << M % 10;
	return 0;
}