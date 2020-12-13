#include <iostream>   
#include <algorithm>    
#include <vector>
#include <set>

using namespace std;

bool ABS(int a, int b)
{
	if (a <= 0 && b <= 0)
	{
		return  (a > b);
	}
	else if (a <= 0 && b >= 0)
	{
		return  (-a < b);
	}
	else if (a >= 0 && b >= 0)
	{
		return  (a < b);
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
	sort(begin(v), end(v), ABS);

	Print(v);
	return 0;
}