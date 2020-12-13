#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
int main() {
	set<string> bus_stops;
	map<set<string>, int> marshrut;
	int i, count_stop, number_marshrut = 0;
	string stop;
	cin >> i; 
	for (i; i > 0; i--) {
		cin >> count_stop; 
		for (count_stop; count_stop > 0; --count_stop) {
			cin >> stop; 
			bus_stops.insert(stop); 
		}
		if (!marshrut.count(bus_stops)) { 
			marshrut[bus_stops] = ++number_marshrut; 
			cout << "New bus " << number_marshrut << endl; 
		}
		else { 
			cout << "Already exists for " << marshrut[bus_stops] << endl; 
		}
		bus_stops.clear(); 
	}
	return 0;
}