#include <iostream>
using namespace std;
int main() {
	int n;
	long time, id, res;
	long a[1000][2];
	for (int i = 0; i < 1001; i++) {
		a[i][0] = 0;
		a[i][1] = 0;
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time >> id >> res;
		if (a[id][0] == 0) {
			a[id][0] = time;
			a[id][1] = time;
		}
		else a[id][1] = time;
	}
	for ( int i = 1; i < 1001; i++)
		if (a[i][0] != 0) {
			cout << i << endl;
			cout << a[i][0] - a[i][0] << endl;
		}
	return 0;
}