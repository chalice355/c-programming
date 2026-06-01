#include <iostream>
using namespace std;

class Complex {
	int real, img;
public:
	Complex(int real = 0, int img = 0) {
		this->real = real;	this->img = img;
	}
	void show();
	Complex operator- (int op2);
};

void Complex::show() {
	if (img < 0)	cout << real << "-" << img << "j" << endl;
	else if (img >= 0)	cout << real << "+" << img << "j" << endl;
}

Complex Complex::operator-(int op2) {
	Complex cmp;
	cmp.real = real - op2;
	cmp.img = img - op2;
	return cmp;
}

int main() {
	Complex a(3, 5), b;
	a.show();
	b.show();
	b = a.operator- (2); // 복소수 객체와 정수 빼기
	a.show();
	b.show();
	return 0;
}
/*
3+5j
0+0j
3+5j
1+3j
*/