// **********************************************
// 제 목 : 프렌드 선언 예제
// 날 짜 : 2026 년 5 월 27 일
// 작성자 : 2001218
// **********************************************

#include <iostream>
#include <cstring>
using namespace std;

class Complex {
	double real, img;
public:
	Complex(double r, double i) : real(r), img(i) {
		cout << "복소수 " << real << "+" << img << "j 생성" << endl;
	}
	Complex() : Complex(0, 0) {}
	void show() {
		cout << " " << real << "+" << img << "j" << endl;
	}
	friend Complex ComplexAdd(Complex x, Complex y);
};

Complex ComplexAdd(Complex x, Complex y) {
	return Complex(x.real + y.real, x.img + y.img);
}

int main() {
	Complex x(2, 3), y(-5, 10), sum;
	sum = ComplexAdd(x, y);
	cout << "두 복소수의 합은";
	sum.show();
}