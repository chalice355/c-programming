# 실습과제 1
```
class Complex {
	int real, img;
public:
	Complex(int real = 0, int img = 0) {
		this->real = real;	this->img = img;
	}
	void show();
	Complex operator+ (Complex op2);
};
```
* Complex 함수 선언
* 실수와 허수를 저장할 real과 img 선언
* 초기값으로 모두 0으로 저장
* 출력 함수 선언
* +연산자 선언

```
void Complex::show() {
	if (img < 0)	cout << real << img << "j" << endl;
	else if (img >= 0)	cout << real << "+" << img << "j" << endl;
}
```
* 출력함수 정의
* 허수부가 0보다 작을 경우, 산술연산기호 제거 후, 출력
* 허수부가 0보다 클 경우, 산술연산기호 "+" 입력 후, 출력

```
Complex Complex::operator+(Complex op2) {
	Complex cmp;
	cmp.real = real + op2.real;
	cmp.img = img + op2.img;
	return cmp;
}
```
* +연산자 정의
* 1번 실수와 2번 실수를 더해 cmp.real에 저장
* 1번 허수와 2번 허수를 더해 cmp.img에 저장

```
int main() {
	Complex x(2, 3), y(-5, 10), sum;
	sum = x + y;
	cout << "두 복소수의 합은 ";
	sum.show();
	return 0;
}
```
* x와 y를 더한 값을 sum에 저장
* 저장된 값을 출력 함수를 통해 출력
<img src="./sbj 7-2-1.png">

# 실습과제 2
```
class Complex {
	int real, img;
public:
	Complex(int real = 0, int img = 0) {
		this->real = real;	this->img = img;
	}
	void show();
	Complex operator* (Complex op2);
};
```
* Complex 함수 선언
* 실수와 허수를 저장할 real과 img 선언
* 초기값으로 모두 0으로 저장
* 출력 함수 선언
* -연산자 선언

```
void Complex::show() {
	if (img < 0)	cout << real << img << "j" << endl;
	else if (img >= 0)	cout << real << "+" << img << "j" << endl;
}
```
* 출력함수 정의
* 허수부가 0보다 작을 경우, 산술연산기호 제거 후, 출력
* 허수부가 0보다 클 경우, 산술연산기호 "+" 입력 후, 출력

```
Complex Complex::operator*(Complex op2) {
	Complex cmp;
	cmp.real = (real * op2.real) - (img * op2.img);	
	cmp.img = (img * op2.real) + (op2.img * real);
	
	return cmp;
}
```
* -연산자 정의
* 1번 실수와 2번 실수를 더해 cmp.real에 저장
* 1번 허수와 2번 허수를 더해 cmp.img에 저장

```
int main() {
	Complex x(2, 3), y(-5, 10), sum;
	sum = x * y;
	cout << "두 복소수의 곱은 ";
	sum.show();
	return 0;
}
```
* x와 y를 뺀 값을 sum에 저장
* 저장된 값을 출력 함수를 통해 출력
<img src="./sbj 7-2-2.png">

# 실습과제 3
```
class Complex {
	int real, img;
public:
	Complex(int real = 0, int img = 0) {
		this->real = real;	this->img = img;
	}
	void show();
	Complex& operator+= (Complex op2);
};
```
* Complex 함수 선언
* 실수와 허수를 저장할 real과 img 선언
* 초기값으로 모두 0으로 저장
* 출력 함수 선언
* +=연산자 선언

```
void Complex::show() {
	if (img < 0)	cout << real << img << "j" << endl;
	else if (img >= 0)	cout << real << "+" << img << "j" << endl;
}
```
* 출력함수 정의
* 허수부가 0보다 작을 경우, 산술연산기호 제거 후, 출력
* 허수부가 0보다 클 경우, 산술연산기호 "+" 입력 후, 출력

```
Complex& Complex::operator+=(Complex op2) {
	real = real + op2.real;
	img = img + op2.img;
	return *this;
}
```
* +=연산자 정의
* 1번 실수와 2번 실수를 더해 cmp.real에 저장
* 1번 허수와 2번 허수를 더해 cmp.img에 저장
* 객체를 참조리턴

```
int main() {
	Complex a(3, 5), b(1, 1);
	a.show();
	b.show();
	b += a;
	a.show();
	b.show();
	return 0;
}
```
* x와 y를 뺀 값을 sum에 저장
* 저장된 값을 출력 함수를 통해 출력
<img src="./sbj 7-2-3.png">

# 실습과제 4
```
class Complex {
	int real, img;
public:
	Complex(int real = 0, int img = 0) {
		this->real = real;	this->img = img;
	}
	void show();
	Complex operator- (int op2);
};
```
* Complex 함수 선언
* 실수와 허수를 저장할 real과 img 선언
* 초기값으로 모두 0으로 저장
* 출력 함수 선언
* -연산자 선언

```
void Complex::show() {
	if (img < 0)	cout << real << "-" << img << "j" << endl;
	else if (img >= 0)	cout << real << "+" << img << "j" << endl;
}
```
* 출력함수 정의
* 허수부가 0보다 작을 경우, 산술연산기호 제거 후, 출력
* 허수부가 0보다 클 경우, 산술연산기호 "+" 입력 후, 출력

```
Complex Complex::operator-(int op2) {
	Complex cmp;
	cmp.real = real - op2;
	cmp.img = img - op2;
	return cmp;
}
```
* -연산자 정의
* 실수와 op2.실수를 뺀 값을 cmp.real에 저장
* 허수와 op2.허수를 뺀 값을 cmp.img에 저장
* cmp 리턴

```
int main() {
	Complex a(3, 5), b;
	a.show();
	b.show();
	b = a.operator- (2); // 복소수 객체와 정수 빼기
	a.show();
	b.show();
	return 0;
}
```
* x와 y를 뺀 값을 sum에 저장
* 저장된 값을 출력 함수를 통해 출력
<img src="./sbj 7-2-4.png">
