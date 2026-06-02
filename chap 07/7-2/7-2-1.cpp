// **********************************************
// 제 목 : +연산자로 복소수 계산
// 날 짜 : 2026 년 6 월 2 일
// 작성자 : 2001218
// **********************************************

#include <iostream>
using namespace std;

class Complex {
	int real, img;
public:
	Complex(int real = 0, int img = 0) {
		this->real = real;	this->img = img;
	}
	void show();
	Complex operator+ (Complex op2);
};

void Complex::show() {
	if (img < 0)	cout << real << img << "j" << endl;
	else if (img >= 0)	cout << real << "+" << img << "j" << endl;
}

Complex Complex::operator+(Complex op2) {
	Complex cmp;
	cmp.real = real + op2.real;
	cmp.img = img + op2.img;
	return cmp;
}

int main() {
	Complex x(2, 3), y(-5, 10), sum;
	sum = x + y;
	cout << "두 복소수의 합은 ";
	sum.show();
	return 0;
}
/*
두 복소수의 합은 -3+13j
*/
