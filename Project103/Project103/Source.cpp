#include<iostream>
using namespace std;

struct Point {
	int x;
	int y;
};

void moveX(struct Point a, int dx) {
	a.x = a.x + dx;
	a.y = a.y;
}

int main() {
	struct Point a;
	int x, y, dx;
	cin >> x >> y >> dx;
	moveX(a, dx);
	cout << a.x << " " << a.y;
	return 0;
}

