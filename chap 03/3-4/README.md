# 실습과제 1
## 접근지정자가 왜 필요한가?
* 클래스 내부의 멤버함수나 멤버변수에 대한 외부 접근을 제어하기 위함이다.
* 사용자의 실수 등을 방지하여 데이터 손상 위험을 감소시키고 비정상적인 값이 외부로부터 대입되는 일 등을 사전에 막아주어 데이터의 무결성을 유지할 수 있다.

## 생성자와 setter 멤버함수는 모두 멤버변수를 설정하는 기능이다. 차이점을 설명하라.
* 생성자는 객체가 처음 생성될 때 한 번 자동으로 호출되는 함수이다. 객체의 초기화를 목적으로 하며, 달성 한 후에는 이후 다시 호출할 수 없다.
* setter는 이미 생성된 객체의 멤버변수 값을 변경하기 위한 함수이다. 프로그램 실행 중 언제든 명시적으로 호출할 수 있다.

## 객체지향형 언어의 특징인 캡슐화와 정보은닉을 설명하라.
* 캡슐화는 객체와 관련된 데이터와 그 데이터를 처리하는 기능을 하나의 클래스 단위로 묶는 것을 말한다. 각 속성과 동작을 하나의 단위로 표현함으로써 코드 구조가 명확해지고 관리가 용이한 점이 있다.
* 정보은닉은 캡슐화를 기반으로하여 객체 내부의 구현 세부사항을 외부로부터 숨기는 개념이다. 멤버변수를 private으로 은닉하고, 꼭 필요한 기능만 public으로 노출시킬 수 있다.
---

# 실습과제 2
```
class Circle {
private:
	int radius;			// public -> private
```
* int radius를 public에서 private으로 변경
```
public:
	Circle();
	Circle(int r);
	void setRadius(int r);
	int getRadius();
};

Circle::Circle() { radius = 1; }
Circle::Circle(int r) { radius = r; }
void Circle::setRadius(int r) { radius = r; }
int Circle::getRadius() { return radius; }
int main() {
	Circle waffle;
	// waffle.radius = 5;	<- 삭제 필요(외부 접근)
```
* waffle.radius = 5를 지우고 setter를 통해 명시적으로 접근하여 값을 변경해야한다
```
	waffle.setRadius(5);
	cout << "원의 반지름은 " << waffle.getRadius() << endl;
	return 0;
}
```
<img src="./sbj 3-4-2.png">

---
# 실습과제 3
```
class Triangle {
private:
	int w, h;
public:
	Triangle();
	Triangle(int a, int b);
	int getWidth();
	void setWidth(int a);
	int getHeight();
	void setHeight(int b);
	float getArea();
	~Triangle();
};
```
* Triangle 클래스 선언 및 각 생성자와 setter, 소멸자 등을 선언
```
Triangle::Triangle() : Triangle(1, 1) { cout << "폭" << w << ",높이" << h << " 삼각형생성" << endl; }
Triangle::Triangle(int a, int b) : w(a), h(b) {}
int Triangle::getWidth() { return w; }
void Triangle::setWidth(int a) { w = a; }
int Triangle::getHeight() { return h; }
void Triangle::setHeight(int b) { h = b; }
float Triangle::getArea() { return (1.0 / 2.0) * w * h; }
Triangle::~Triangle() { cout << "폭" << w << ",높이" << h << " 삼각형소멸" << endl; }
```
* 각 생성자와 함수 등을 초기화
```
int main() {
	Triangle tri;
	tri.setWidth(3);
	tri.setHeight(5);
	cout << "삼각형의 폭은 " << tri.getWidth() << endl;
	cout << "삼각형의 높이는 " << tri.getHeight() << endl;
	cout << "삼각형의 면적은 " << tri.getArea() << endl;
	return 0;
}
```
* tri 선언
* setter를 통해 명시적인 초기화
* 초기화 된 값과 출력문 각각 출력
<img src="./sbj 3-4-3.png">

---
# 실습과제 4
```
class Triangle {
private:
	int w, h;
public:
	Triangle();
	Triangle(int a, int b);
	int getWidth();
	void setWidth(int a);
	int getHeight();
	void setHeight(int b);
	~Triangle();
};
```
* Triangle 클래스 선언 및 생성자, setter, 소멸자 등 선언
```
Triangle::Triangle() : Triangle(1, 1) {}
Triangle::Triangle(int a, int b) : w(a), h(b) {
	if (w < 0 || h < 0) {
		w = 1, h = 1;
		cout << "길이는 양수여야함, 대신에 폭" << w << ",높이" << h << " 삼각형생성" << endl;
	}
	else w = a, h = b;
}
```
* 기본 생성자 초기화
* 폭과 높이 둘 다 음수인 경우. 둘 다 1로 초기화 후 문장 출력
* 아닌경우, 그대로 출력
```
int Triangle::getWidth() { return w; }
```
* 폭을 반환하는 함수 정의
```
void Triangle::setWidth(int a) {
	if (a < 0)	cout << "폭은 양수이어야 함" << endl;
	else w = a;
}
```
* 폭이 음수인 경우, 문장 출력
* 아닌경우, 그대로 출력
```
int Triangle::getHeight() { return h; }
```
* 높이를 반환하는 함수 정의
```
void Triangle::setHeight(int b) {
	if (b < 0)	cout << "높이는 양수이어야 함" << endl;
	else h = b;
}
```
* 높이가 음수인 경우, 문장 출력
* 아닌경우. 그대로 출력
```
Triangle::~Triangle() { cout << "폭" << w << ",높이" << h << " 삼각형소멸" << endl; }
```
* 소멸자 정의
```
int main() {
	Triangle tri(-10, -5);
	tri.setWidth(-3);
	tri.setHeight(-5);
	tri.setWidth(3);
	tri.setHeight(5);
	cout << "삼각형의 폭은 " << tri.getWidth() << endl;
	cout << "삼각형의 높이는 " << tri.getHeight() << endl;
	return 0;
}
```
* 각 삼각형의 폭과 높이의 값 초기화
* 삼각형의 폭과 높이를 출력하는 문장 각각 실행
<img src="./sbj 3-4-4.png">
