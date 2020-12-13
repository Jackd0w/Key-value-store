#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> Z, M, N;
	int z, n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		N.insert(x);
	}
	for (int i = 0; i < m; i++) {
		int y;
		cin >> y;
		M.insert(y);
	}
	Z.insert(N.begin(), N.end(), M.begin(), M.end());
	cout << M.size + N.size - Z.size << endl;
	return 0;
}