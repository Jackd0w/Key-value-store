#include <iostream>
#include <cmath>

using namespace std;

double Len(int x1, int y1, int x2, int y2)
{
	return sqrt((double)(x1 - x2)*(x1 - x2) + (double)(y1 - y2)*(y1 - y2));
}

int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double len = Len(x1, y1, x1, y2);
	cout << len << endl;
	return 0;
}