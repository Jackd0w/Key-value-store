#include <iostream>   
#include <algorithm>    
#include <vector>
#include <set>

using namespace std;

bool Modul(int q, int w)
{
	if (q >= 0 && w >= 0)
	{
		return  (q < w);
	}
	else if (q <= 0 && w >= 0)
	{
		return  (-q < w);
	}
	else if (q <= 0 && w <= 0)
	{
		return  (q > w);
	}
}
void Print(vector <int> v)
{
	for (const auto& i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector <int> v;
	int n;
	cin >> n;
	int k;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		v.push_back(k);
	}
	sort(begin(v), end(v));
	sort(begin(v), end(v), Modul);

	Print(v);
	return 0;
}