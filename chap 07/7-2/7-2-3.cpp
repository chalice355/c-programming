// **********************************************
// 제 목 : +=연산자로 복소수 계산
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
	Complex& operator+= (Complex op2);
};

void Complex::show() {
	if (img < 0)	cout << real << img << "j" << endl;
	else if (img >= 0)	cout << real << "+" << img << "j" << endl;
}

Complex& Complex::operator+=(Complex op2) {
	real = real + op2.real;
	img = img + op2.img;
	return *this;
}

int main() {
	Complex a(3, 5), b(1, 1);
	a.show();
	b.show();
	b += a;
	a.show();
	b.show();
	return 0;
}
/*
3+5j
1+1j
3+5j
4+6j
*/
