#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {
	int Q, i;
	string stop;
	map<vector<string>, int> bus;
	cin >> Q; 
	for (Q; Q > 0; Q--) {
		vector<string> v;
		cin >> i;
		for (int z = 0; z < i; z++) {
			cin >> stop;
			v.push_back(stop);
		}
		if (bus.count(v)) {
			cout << "Already exists for " << bus[v] << endl;
		}
		else {
			bus[v];
			int r = bus.size();
			bus[v] = r;
			cout << "New bus " << bus[v] << endl;
		}
	}
	return 0;
}