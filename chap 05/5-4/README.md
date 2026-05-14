# 실습과제 1
## 일반생성자와 복사생성자의 차이는?
* 일반생성자는 새 객체 생성 시에 호출하며, 초기값을 세팅(초기화)하는 역할을 가졌고, 인자 형태는 일반적인 자료형(int, string 등)이다.
* 복사생성자는 기존 객체로 새 객체 생성시에 호출하며, 기존 객체의 데이터를 새 객체에 복사하는 역할을 하고, 인자 형태는 동일한 클래스 타입의 상수 레퍼런스(const 클래스& 변수)이다.

## 대입연산과 얕은 복사생성자의 차이는 무엇인가?
* 얕은 복사생성자는 객체가 생성될 때에 복사한다.
* 대입 연산은 이미 존재하는 객체에 값을 덮어쓴다.

## 지금까지 배운 내용기준으로 컴파일러가 자동으로 추가하는 멤버함수는 어떤 것이 있는가?(4가지)
* 기본생성자, 복사생성자, 소멸자, 대입연산자

# 실습과제 2
```
#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
    int id;
public:
    Person(int id, const string& name);
    ~Person();
    void changeName(const string& name);
    void show() { cout << id << ',' << name << endl; }
};
```
* char* -> string으로 변경
* const 8char -> const string&로 변경
* string이 깊은 복사를 하기 때문에 복사생성자 제거

```
Person::Person(int id, const string& name) {
    this->id = id;
    this->name = name;
}
```
* 동적할당 없이 대입

```
Person::~Person() {
}
```
* string이 알아서 메모리 해

```
void Person::changeName(const string& name) {
    this->name = name;
}
```
* string은 크기 제한 없으므로 strlen 비교 제거

```
int main() {
    Person father(1, "Kitae");
    Person daughter(father);
    cout << "daughter 객체 생성 직후 ----" << endl;
    father.show();
    daughter.show();
    daughter.changeName("Grace");
    cout << "daughter 이름을 Grace로 변경한 후 ----" << endl;
    father.show();
    daughter.show();
    return 0;
}
```
* 깊은 복사를 했기 때문에 daughter 이름을 바꿔도 father는 영향을 받지 않는다.
<img src="./sbj 5-4-2.png">

# 실습과제 3
```
class MyStack {
	int* p;
	int size;
	int tos;
public:
	MyStack();
	MyStack(int size);
	MyStack(const MyStack& src);
	~MyStack();
	bool push(int n);
	bool pop(int& n);
};
```
* p는 스택 데이터를 저장할 동적배열 포인터
* size = 할당받은 동적 배열의 크기, 초기값 0
* tos = 다음에 저장될 배열 원소의 인덱스, 초기값 0

```
MyStack::MyStack() : MyStack(10) {}
MyStack::MyStack(int size) : size(size), tos(0) {
	p = new int[size];
}
```
* 기본생성자는 타겟 생성자(10)에게 위임
* 타겟생성자는 size와 tos를 멤버초기화 리스트로 초기화

```
MyStack::MyStack(const MyStack& src) {
	this->size = src.size;
	this->tos = src.tos;
	this->p = new int[src.size];
	for (int i = 0; i < src.tos; i++) {
		this->p[i] = src.p[i];
	}
}
```
* 깊은 복사생성자 선언
* 원본의 최대 크기, 현재 top의 위치 복사
* 원본과 독립적인 새 메모리 할당
* 원본 배열의 데이터를 새 배열에 복사(인덱스 0부터 size-1까지)

```
MyStack::~MyStack() {
	delete[] p;
}
```
* 동적할당 한 배열 메모리 해제

```
bool MyStack::push(int n) {
	if (tos == size) return false;
	p[tos++] = n;
	return true;
}
```
* 스택에 값을 push
* tos가 size와 값이 같으면 false
* 현재 tos 위치에 n을 저장 후 tos++

```
bool MyStack::pop(int& n) {
	if (tos == 0)	return false;
	n = p[--tos];
	return true;
}
```
* 스택에서 값을 pop
* tos가 0이면 스택이 비어있는 상태 = false
* 현재 tos를 1만큼 감소시킨 후 그 위치의 값을 n에 저장

```
int main() {
	MyStack a(10);
	a.push(10); a.push(20);
	MyStack b = a;
	b.push(30);
	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;
}
```
* 크기 10짜리 스택 a 생성 후 10과 20을 push하여 배열에 추가
* 깊은 복사생성자 호출하여 스택 b를 생성하여 a의 값을 복사(독립적인 메모리)
* 스택 b의 배열에 30 push
* a의 top을 pop -> 20
* b의 top을 pop -> 30
<img src="./sbj 5-4-3.png">

# 실습과제 4
```
class MyPipe {
	int size;
	int putIndex = 0;
	int getIndex = 0;
	int* p;
public:
	MyPipe();
	MyPipe(int size);
	MyPipe(const MyPipe& src);
	~MyPipe();
	bool put(int n);
	bool get(int& n);
	int getSize() { return putIndex; }
};
```
* 파이프 최대 저장 크기, 데이터 넣을/꺼낼 위치 선언
* 데이터를 저장할 동적배열 포인터 선언

```
MyPipe::MyPipe() : MyPipe(10) {}
MyPipe::MyPipe(int size) : size(size), putIndex(0), getIndex(0) {
	p = new int[size];
}
```
* 기본생성자 -> 타겟생성자(10) 위임
* 타겟생성자 초기화

```
MyPipe::MyPipe(const MyPipe& src) {
	this->size = src.size;
	this->putIndex = src.putIndex;
	this->getIndex = src.getIndex;
	this->p = new int[src.size];
	for (int i = 0; i < src.size; i++) {
		this->p[i] = src.p[i];
	}
}
```
* 깊은 복사 생성자 정의
* size = 원본 최대 크기 복사
* putIndex = 원본 저장 위치 복사
* getIndex = 원본 꺼낼 위치 복사
* 포인터p = 원본과 독립적인 새 메모리 할당
* 원본 배열 전체를 새 배열에 복사

```
MyPipe::~MyPipe() {
	delete[] p;
}
```
* 소멸자로 동적 할당한 배열 메모리 해제

```
bool MyPipe::put(int n) {
	if (putIndex == size)	return false;
	p[putIndex++] = n;
	return true;
}
```
* 파이프 뒤쪽에 데이터 넣기
* putIndex가 size와 같으면 꽉 찬 상태 = false
* 현재 putIndex 위치에 n 저장 후 putIndex + 1

```
bool MyPipe::get(int& n) {
	if (getIndex == putIndex)	return false;
	n = p[getIndex++];
	return true;
}
```
* 파이프 앞쪽에서 데이터 꺼내기
* getIndex가 putIndex와 같으면 꺼낼 데이터 없음 = false
* getIndex 위치의 값을 n에 저장 후 getIndex + 1

```
int main() {
	MyPipe a(5);
	a.put(10); a.put(20);
	MyPipe b = a;
	b.put(30);
	cout << "파이프 a에 저장된 개수: " << a.getSize() << endl;
	cout << "파이프 b에 저장된 개수: " << a.getSize() << endl;
	int n;
	a.get(n);
	cout << "파이프 a에서 빼온 값 " << n << endl;
	b.get(n);
	cout << "파이프 b에서 빼온 값 " << n << endl;
}
```
* 크기 5짜리 파이프 a를 생성하고 10과 20을 파이프에 put
* 깊은 복사생성자 호출 -> b에 a의 값들 복사
* 파이프 b에 30 put
* a와 b의 0번 위치값을 꺼냄
<img src="./sbj 5-4-4.png">
