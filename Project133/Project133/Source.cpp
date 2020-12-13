#include <iostream>
#include <math.h>
#include <string>
using namespace std;


string result = number;//Переводим в 16
if (number == "10")
result = "A";
else if (number == "11")
result = "B";
else if (number == "12")
result = "C";
else if (number == "13")
result = "D";
else if (number == "14")
result = "E";
else if (number == "15")
result = "F";

return result;
}

int GetNumber(char sign) {
	int result = 0;
	switch (sign) {
	case 'A':
		result = 10;
		break;

	case 'B':
		result = 11;
		break;

	case 'C':
		result = 12;
		break;

	case 'D':
		result = 13;
		break;

	case 'E':
		result = 14;
		break;

	case 'F':
		result = 15;
		break;
	}
	if (result == 0)
		result = (int)sign - (int)'0';

	return result;
}




float TransferSystemTen(string number, int base) {
	float result = 0;
	int numberDecimalPlaces = 0;
	bool fractionalNumber = false;

	for (int j = 0; j < number.size(); j++) {
		if (fractionalNumber)
			numberDdecimalPlaces++;

		if (number[j] == ',' || number[j] == '.') {
			fractionalNumber = true;
			numberDecimalPlaces = 1; // Единица, так как мы считаем еще и запятую
		}
	}
	long int power = number.size() - numberDdecimalPlaces - 1;

	for (int i = 0; i < number.size(); i++) {
		if (number[i] == ',' || number[i] == '.')
		{
			power = -1;
			continue;
		}
		result += GetNumber(number[i]) * pow(base, power);
		power--;
	}
	return result;
}

string Converting(double number, int base) {
	float wholePart = (int)number;
	float fractionalPart = number - wholePart;
	string resultWholePart = "0";
	string resultFractionalPart = ".";

	if (wholePart != 0) {
		resultWholePart = "";
		while (wholePart != 0) {
			resultWholePart.insert(0, GetStringNumber(to_string((int)wholePart % base)));
			wholePart = floor(wholePart / base);
		}
	}
	if (fractionalPart != 0) {
		int maxNumbers = 10;
		while (maxNumbers > 0) {
			fractionalPart *= base;
			int wholePartNumber = (int)fractionalPart;
			fractionalPart -= wholePartNumber;
			resultFractionalPart += GetStringNumber(to_string(wholePartNumber));
			maxNumbers--;
		}
	}
	return resultWholePart + resultFractionalPart;
}


int main(int argc, const char * argv[]) {
	string number;
	int numberBaseA;
	int numberBaseB;

	cout << "Введите число: ";
	cin >> number;
	cout << "Введите основание числа: ";
	cin >> numberBaseA;

	cout << "Введите основание, в которое хотите перевести число " << number << ": ";
	cin >> numberBaseB;

	if (numberBaseA > 16 || numberBaseB > 16) {
		cout << "Данная программа не работает с данной СС." << endl;
		return -1;
	}

	float numberTenCC = TransferSystemTen(number, numberBaseA);

	string resultTranslate = ConvertingDecimalNumberSystemSelectedCC(numberTenCC, numberBaseB);
	cout << "Перевод числа " << number << " из " << numberBaseA << " СС в " << numberBaseB << " СС равен: " << resultTranslate << endl;

	return 0;
}