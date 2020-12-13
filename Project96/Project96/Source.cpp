#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
};

int toY(struct Point a) {
	return a.y;
}
 
int main() {
	int x, y;
	struct Point a;
	cin >> a.x >> a.y;
	cout << toY(a);
	return 0;
}