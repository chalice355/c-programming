// **********************************************
// 제 목 : 다른 클래스의 멤버 함수를 프렌드로 선언
// 날 짜 : 2026 년 5 월 27 일
// 작성자 : 2001218
// **********************************************

#include <iostream>
#include <cstring>
using namespace std;

class Complex;
class ComplexManager {
public:
	Complex ComplexAdd(Complex x, Complex y);
};

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
	friend ComplexManager;
};

Complex ComplexManager::ComplexAdd(Complex x, Complex y) {
	return Complex(x.real + y.real, x.img + y.img);
}

int main() {
	Complex x(2, 3), y(-5, 10), sum;
	ComplexManager man;
	sum = man.ComplexAdd(x, y);
	cout << "두 복소수의 합은";
	sum.show();
}
