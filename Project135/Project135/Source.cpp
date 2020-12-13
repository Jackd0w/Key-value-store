#include <iostream>
#include <string>
#include <cstdio>
#include <iterator>
#include <fstream>
#include <ctime>
using namespace std;

int Check(int arr[21][21], int i, int j);
int num_generation;
int array[21][21];
int n;

void MakeWorkFile() {
	ofstream fout("work.out");
	int array[21][21];
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
			array[i][j] = -1;

	for (int i = 0; i < 21 * 21 / 2; i++)
	{
		int select = abs(rand() % (21 * 21));
		int state = abs(rand() % 6);
		array[select / 21][select % 21] = state;
	}
	cout << "������ ��������� �������������" << endl;
}
 
int Check(int arr[21][21], int i, int j)
{
	int count = 0;

	if (i - 1 > -1)
	{
		if (arr[i - 1][j] > 0) count++;
	}
	if (i + 1 < 21)
	{
		if (arr[i + 1][j] > 0) count++;
	}
	if (j - 1 > -1)
	{
		if (arr[i][j - 1] > 0) count++;
	}
	if (j + 1 < 21)
	{
		if (arr[i][j + 1] > 0) count++;
	}
	if (j + 1 < 21 && i + 1 < 21)
	{
		if (arr[i + 1][j + 1] > 0) count++;
	}
	if (j + 1 < 21 && i - 1 > -1)
	{
		if (arr[i - 1][j + 1] > 0) count++;
	}
	if (j - 1 > -1 && i + 1 < 21)
	{
		if (arr[i + 1][j - 1] > 0) count++;
	}
	if (j - 1 > -1 && i - 1 > -1)
	{
		if (arr[i - 1][j - 1] > 0) count++;
	}
	return count;
}


	

int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Please, write here the generation number" << endl;
	cin >> num_generation;
	ofstream fout("work.out");
	int array[21][21];
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
			array[i][j] = -1;

	for (int i = 0; i < 21 * 21 / 2; i++)
	{
		int select = abs(rand() % (21 * 21));
		int state = abs(rand() % 6);
		array[select / 21][select % 21] = state;
	}
	cout << "������ ��������� �������������" << endl;
	for (int q = 1; q < n + 1; q++)
	{
		int memory_count = 0;
		int user_info = 0;
		int arrays[21][21];
		std::memcpy(arrays, array, sizeof(int) * 10);
		for (int i = 0; i < 21; i++)
			for (int j = 0; j < 21; j++)
			{
				if (array[i][j] > -1 && array[i][j] != 11 && array[i][j] != 0)
				{
					memory_count++;
					user_info += array[i][j];
					if (Check(array, i, j) > 1)
						arrays[i][j] = array[i][j] + 1;
					else
						if (Check(array, i, j) == 0)
							arrays[i][j] = 0;
						else
							arrays[i][j] = array[i][j];
				}
				if (array[i][j] == 11)
				{
					memory_count++;
					user_info += array[i][j];
					arrays[i][j] = 0;

				}
				if (array[i][j] == 0)
				{
					user_info += array[i][j];
					arrays[i][j] = 1;
				}

			}
		fout << q << "." << "����� : " << memory_count << " , ���� ����� : " << user_info << "\n";

	}
	return 0;
}