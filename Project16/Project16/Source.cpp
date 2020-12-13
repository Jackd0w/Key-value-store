#include <iostream>
using namespace std;
void sort_three_numbers(int &a, int &b, int &c)
{
	if (b < a) swap(a, b);
	if (c < a) swap(a, c);
	if (b > c) swap(b, c);
}


	
	return 0;
}