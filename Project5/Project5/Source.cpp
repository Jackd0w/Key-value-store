#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) 
	{
		int temp;
		cin >> temp;
		if (temp % 2 == 0) 
		{
			a[i] = temp;
		}
		else
		{
			a[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			if (a[i] != 0)
			{
				cout << a[i] << ' ';
			}
		}
	}
	return 0;
}