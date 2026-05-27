# 실습과제 1
## 프렌드 함수가 왜 필요한가?
* 

## 객체 지향형 언어의 특징 중의 하나인 다형성의 의미와 종류를 조사하시오
* 

# 실습과제 2
```
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
```
* 
<img src="./sbj 7-1-2.png">

# 실습과제 3
```
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
```
* 
<img src="./sbj 7-1-2.png">
