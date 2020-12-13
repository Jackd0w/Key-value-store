#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
};
void moveX(struct Point * a, int dx) {
	int x, y;
	cin >> x >> y >> dx;
	a->x = x + dx;
	a->y = y;
}
int main() {
	struct Point a;
	int x, y, dx;
	moveX(&a, dx);
	cout << x << y;
	return 0;
}
