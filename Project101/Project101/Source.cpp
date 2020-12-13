#include <iostream>
using namespace std;

void sort3(int *a, int *b, int *c)
{
	int min, mid, max;
	if (((*a) < (*b)) && ((*a) < (*c))) {
		min = (*a);
		if ((*b) > (*c)) {
			mid = (*c);
			max = (*b);
		}
		else if ((*b) < (*c)) {
			mid = (*b);
			max = (*c);
		}
	}
	if (((*b) < (*a)) && ((*b) < (*c))) {
		min = (*b);
		if ((*a) > (*c)) {
			mid = (*c);
			max = (*a);
		}
		else if ((*b) < (*c)) {
			mid = (*a);
			max = (*c);
		}
	}
	if (((*c) < (*b)) && ((*c) < (*a))) {
		min = (*c);
		if ((*b) > (*a)) {
			mid = (*a);
			max = (*b);
		}
		else if ((*b) < (*a)) {
			mid = (*b);
			max = (*a);
		}
	}
}

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	sort3(x, y, z);
	cout << x << y << z;
	return 0;
}