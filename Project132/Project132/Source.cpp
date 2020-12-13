#include <iostream>
using namespace std;

unsigned factorial(unsigned n) {
	return ((n > 1) ? n * factorial(n - 1) : n);
}

unsigned getMismatchCount(bool select[], unsigned n, unsigned step = 0) {
	unsigned count = 0;
	if (step >= n) {
		count = 1;
	}
	else {
		for (unsigned i = 0; i < n; i++) {
			if ((i != step) && !select[i]) {
				select[i] = true;
				count += getMismatchCount(select, n, step + 1);
				select[i] = false;
			}
		}
	}

	return count;
}

int main() {
	const unsigned N = 10;
	bool select[N];

	for (auto &f : select) {
		f = false;
	}

	cout << factorial(N) - getMismatchCount(select, N) << endl;

	return 0;
}