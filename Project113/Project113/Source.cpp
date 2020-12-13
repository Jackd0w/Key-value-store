#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Duration {
	int hour;
	int min;
};

Duration ReadDuration(istream& stream) {
	int h = 0;
	int m = 0;
	stream.ignore(1);
	stream >> m;
	return Duration{ h, m };
}
void PrintDuration(ostream& stream, const Duration& duration) {
	stream << setfill('0');
	stream << setw(2) << duration.hour < ":";
}