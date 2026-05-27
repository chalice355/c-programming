# 실습과제 1
## 프렌드 함수가 왜 필요한가?
* 예를 들어, 두 클래스 사이에서 크기를 비교하는 함수를 작성한다고 하면, 첫 번째로, getter 함수 만들기, 두 번째로, 멤버 함수로 만들기, 세 번째로 프렌드 함수를 사용하는 것이 있다.
* getter 함수의 경우, 양쪽 클래스에 getter 함수를 만들어 반환값을 얻어내어 간접적으로 접근할수 있지만, 코드의 간결함이 부족해보일 수 있다.
* 멤버함수로 만드는 경우, 비교를 하는 함수를 가정하였을 떄, 어느 한쪽에 멤버함수로 만드는 것은 어색해진다.
* 프렌드 함수를 사용하는 경우, 프렌드 선언하는 문장 하나만 추가하면 된다. 단점으로는, 캡슐화 유의 원칙이 조금 깨질 수 있다.

## 객체 지향형 언어의 특징 중의 하나인 다형성의 의미와 종류를 조사하시오
* 다형성이란, 같은 이름이지만, 상황에 따라 다르게 동작할 수 있는 것을 말한다.
* 함수 오버로딩 : 컴파일 시 결정, 매개변수 타입/개수로 구분 -> 매개변수가 다르면 같은 이름의 함수 여러개 가능
* 연산자 오버로딩 : 컴파일 시 결정, 피연산자 타입으로 구분 -> 피연산자가 다르면 같은 연산자 다르게 동작
* 가상함수 : 실행 시 결정, 객체 타입으로 구분 -> 객체 타입에 따라 같은 함수가 다르게 동

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
```
* Complex 클래스 선언
* 실수와 허수를 인자로 갖는 생성자(default = (0,0)) 선언 및 정의
* 정보 출력 함수 정의
* ComplexAdd 함수를 프렌드 선언

```
Complex ComplexAdd(Complex x, Complex y) {
	return Complex(x.real + y.real, x.img + y.img);
}
```
* ComplexAdd함수 정의
* Complex와 프렌드가 되었으므로, Complex의 실수와 허수를 사용 가능

```
int main() {
	Complex x(2, 3), y(-5, 10), sum;
	sum = ComplexAdd(x, y);
	cout << "두 복소수의 합은";
	sum.show();
}
```
* Complex 클래스에 인자를 대입한 x와 y, 그리고 그것들을 더한 값을 저장할 sum 선언
* sum 정의
* 더한 값 출력
<img src="./sbj 7-1-2.png">

# 실습과제 3
```
class Complex;
class ComplexManager {
public:
	Complex ComplexAdd(Complex x, Complex y);
};
```
* Complex와 ComplexManager는 서로가 서로를 필요로 하기 때문에 forward declaration을 추가하여 컴파일러에게 Complex라는 클래스가 존재한다는 것을 미리 알린다.
* Complex의 인자를 활용하는 멤버함수 ComplexAdd를 선언

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
	friend ComplexManager;
};
```
* 사전에 먼저 선언한 Complex클래스 정의
* 타겟 생성자 정의
* 위임 생성자 정의 (default = (0,0))
* 정보 출력 함수 정의
* ComplexManager를 프렌드로 선언

```
Complex ComplexManager::ComplexAdd(Complex x, Complex y) {
	return Complex(x.real + y.real, x.img + y.img);
}
```
* ComplexManager의 멤버함수 정의

```
int main() {
	Complex x(2, 3), y(-5, 10), sum;
	ComplexManager man;
	sum = man.ComplexAdd(x, y);
	cout << "두 복소수의 합은";
	sum.show();
}
```
* Complex에 인자 대입한 x와 y, 더한 값을 저장할 sum을 선언
* ComplexManager의 ComplexAdd함수를 실행(덧셈)
* 더한 정보 출력
<img src="./sbj 7-1-2.png">
