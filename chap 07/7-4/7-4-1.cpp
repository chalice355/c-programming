// **********************************************
// 제 목 : shift 연산자 중복
// 날 짜 : 2026 년 6 월 11 일
// 작성자 : 2001218
// **********************************************

#include <iostream>
using namespace std;

class Complex {
	double real, img;
public:
	Complex(double real = 0, double img = 0) {
		this->real = real;
		this->img = img;
	}
	friend istream& operator>>(istream& op1, Complex& op2);
	friend ostream& operator<<(ostream& op1, Complex& op2);
};

istream& operator>>(istream& op1, Complex& op2) {
	cout << "실수부:";
	op1 >> op2.real;
	cout << "허수부:";
	op1 >> op2.img;
	return op1;
}

ostream& operator<<(ostream& op1, Complex& op2) {
	op1 << op2.real;
	if (op2.img < 0)	op1 << op2.img << "j" << endl;
	else
		op1 << "+" << op2.img << "j" << endl;
	return op1;
}

int main() {
	Complex x, y;
	cin >> x >> y;
	cout << x << y;
	return 0;
}