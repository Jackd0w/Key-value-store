
#include <iostream>
#include <exception>
#include <sstream>
#include <cmath>
#include <string>
using namespace std;

class Rational {
public:
	Rational() {
		num = 0;
		den = 1;
	}
	Rational(int numerator, int denominator) {
		if (denominator == 0) throw invalid_argument("invalid_argument");
		else if (denominator < 0) {
			if (numerator < 0) {
				denominator = abs(denominator);
				numerator = abs(numerator);
			}
			else {
				denominator = abs(denominator);
				numerator = numerator - 2 * numerator;
			}
		}
		if (numerator == 0) {
			denominator = 1;
		}
		int nod = Nod(abs(numerator), abs(denominator));
		num = numerator / nod;
		den = denominator / nod;
	}
	int Numerator() const {
		return num;
	}
	int Denominator() const {
		return den;
	}
private:
	int num;
	int den;

	int Nod(int a, int b) {
		while (a > 0 && b > 0) {
			if (a > b) {
				a %= b;
			}
			else {
				b %= a;
			}
		} 
		return a + b;
	}
};
Rational operator / (Rational a, Rational b) {
	if (b.Numerator() == 0) throw domain_error("domain_error");
	return Rational((a.Numerator() * b.Denominator()), (a.Denominator() * b.Numerator()));
}
istream& operator >> (istream& stream, Rational& r) {
	int p, q;
	if (stream >> p && stream.ignore(1) && stream >> q) {
		r = { p, q };
	}
	return stream;
}
ostream& operator << (ostream& stream, const Rational& r) {
	stream << r.Numerator() << "/" << r.Denominator();
	return stream;
}
int main() {
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument&) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error&) {
	}

	cout << "OK" << endl;
	return 0;
}