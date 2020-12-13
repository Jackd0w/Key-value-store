#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int q, number;
	int count = 0;
	string command;
	cin >> q;
	vector<int> queue;
	while (q > 0) {
		cin >> command;
	}
	if (command == "COME") {
		cin >> number;
		if (number >= 0) {
			queue.resize(queue.size() + number, false);
		}
		else {
			for (int i = 0; i < -number; i++) {
				queue.pop_back();
			}
		}
	}
	if (command == "WORRY") {
		cin >> number;
		if (!queue[number]) {
			queue[number] = true;
		}
	}
	if (command == "QUIET") {
		cin >> number;
		if (queue[number]) {
			queue[number] = false;
		}
	}
	if (command == "WORRY_COUNT") {
		count = 0;
		for (auto el : queue) {
			if (el) {
				count++;
			}
		}
		cout << count;
	}
	q--;
	return 0;
}