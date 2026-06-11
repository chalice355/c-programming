# 실습과제 1
```
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
```
* 실수부와 허수부를 저장할 멤버변수 real, img 선언
* 생성자 선언 및 기본값 0으로 초기화
* 전달받은 값으로 real, img 초기화
* 외부함수 '>>'와 '<<'를 프렌드로 초대하여 멤버변수 접근 허용

```
istream& operator>>(istream& op1, Complex& op2) {
	cout << "실수부:";
	op1 >> op2.real;
	cout << "허수부:";
	op1 >> op2.img;
	return op1;
}
```
* 실수부와 허수부를 cin으로 각각 real과 img에 저장
* cin의 참조를 리턴하여 cin >> x >> y 연속 사용 가능

```
ostream& operator<<(ostream& op1, Complex& op2) {
	op1 << op2.real;
	if (op2.img < 0)	op1 << op2.img << "j" << endl;
	else
		op1 << "+" << op2.img << "j" << endl;
	return op1;
}
```
* 실수부 출력
* 허수부가 음수인 경우, 음수 부호 제거 후 출력
* 허수부가 음수가 아닌 경우. '+'연산자 추가 후 출력
* cout의 참조를 리턴하여 cout << x << y 연속 사용 가능

```
int main() {
	Complex x, y;
	cin >> x >> y;
	cout << x << y;
	return 0;
}
```
* 기본 생성자 호출-> real과 img 0으로 초기화
* x 입력 후 y 입력
* x 출력 후 y 출력

# 실습과제 2
## 실습과제 2-1
### 프렌드에 대한 설명 중 틀린 것은?
1. 한 클래스의 전체 멤버 함수를 프렌드로 선언할 수 없다.
2. 프렌드 함수는 클래스의 멤버 함숙다 아니다.
3. 프렌드 함수는 클래스의 private 멤버에 대한 접근 권한을 가진다.
4. 프렌드 함수는 friend 키워드로 클래스 내에 선언된다.

* 정답 : 1
* friend class SampleManager; 처럼 클래스 전체를 프렌드로 선언하면 그 클래스의 모든 멤버 함수가 한번에 프렌드가 되기 때문에 틀린 설명이다.

## 실습과제 2-2
### 프렌드 함수가 필요한 경우가 아닌 것은?
1. 멤버는 아니지만 클래스의 private 멤버에 접근해야만 하는 함수를 작성하는 경우
2. 두 개 이상의 클래스에 대해 private 멤버를 동시에 접근하는 함수를 작성하는 경우
3. 연산자 중복 시에
4. 함수 중복 시에

* 정답 : 4
* 함수 중복은 같은 이름의 함수를 매개변수만 다르게 여러 개 정의하는 것으로, 프렌드와 관계가 없기 때문이다.

## 실습과제 2-3
```
class SampleManager;

class Sample {
	friend class SampleManager;
};

class SampleManager {

};
```
* SampleManager의 정의가 Sample보다 뒤에 오기 때문에 이름을 미리 알려주는 '전방선언'을 한다.
* 클래스 전체를 프렌드로 선언하면 클래스의 모든 멤버 함수가 Sample의 private 멤버에 접근 가능해진다.

## 실습과제 2-4
```
class Sample;

class SampleManager {
public:
	bool compare(Sample& a, Sample& b);
};

class Sample {
	friend bool SampleManager::compare(Sample& a, Sample& b);
};
```
* SampleManager 안의 compare 매개변수에 Sample&가 존재하므로, Sample을 전방선언한다.
* SampleManager 클래스를 먼저 정의하는 이유는, Sample 안에서 SampleManager::compare를 지목하려면, 컴파일러가 구조를 알고있어야 하기 때문이다.
* Sample 안에서 해당 함수만 찝어 프렌드로 초대한다.
