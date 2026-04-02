# 실습과제 1
## 배열명의 의미를 설명하라.
* 배열의 이름이 아닌, 배열의 첫 번째 원소의 주소를 나타내는 상수이다.

## 객체 포인터의 의미를 설명하라.
* 객체의 주소를 저장하는 변수로, 멤버변수나 멤버함수가 저장된 객체와는 다르다.

## 포인터를 이용하여 배열 각 원소의 주소를 구하는 방법을 설명하라
* 포인터에 정수를 더하거나 ++하여 각 원소의 주소를 구할 수 있다.
```
int arr[3] = {10, 20, 30};
int* p = arr;       // p는 arr[0]의 주소

p
p + 1
p + 2
```

## 포인터를 이용하여 배열 각 원소의 값을 구하는 방법을 설명하라
* 주소 앞에 *을 붙여 주소에 저장된 값을 가져올 수 있다.
```
int arr[3] = {10, 20, 30};
int* p = arr;

*p
*(p + 1)
*(p + 2)
```

# 실습과제 2
```
class Triangle {
private:
	int w, h;
public:
	Triangle() : Triangle(1, 1) {}
	Triangle(int a, int b) : w(a), h(b) {}
	int getWidth() { return w; }
	void setWidth(int a) { w = a; }
	int getHeight() { return h; }
	void setHeight(int b) { h = b; }
	float getArea() { return 0.5 * w * h; }
};
```
* 삼각형 클래스 생성 및 각각 초기화
* 기본 삼각형 크기 = (1, 1)
```
int main() {
	Triangle tri;
	Triangle* p = &tri;
```
* 객체포인터 선언 및 초기화
```
	p -> setWidth(3);
	p -> setHeight(5);
```
* -> 연산자로 멤버함수 호출
```
	cout << "삼각형의 면적은 " << tri.getArea() << endl;
	return 0;
}
```
* -> 연산자로 getArea함수 호출
<img src="./sbj 4-1-2.png">

# 실습과제 3
```
class Triangle {
private:
	int w, h;
public:
	Triangle() : Triangle(1, 1) {}
	Triangle(int a) { this->w = a, this->h = 1; }
	Triangle(int a, int b) { this->w = a, this->h = b; }
	float getArea() { return 0.5 * w * h; }
};
```
* 삼각형 클래스 선언 및 초기화
* 기본 삼각형 크기 = (1, 1)
* 매개변수(a, b)의 이름이 멤버변수(w, h)와 다르기 때문에 this가 없어도 동작하지만, 구분을 위해 다르게 사용함
* this는 현재 멤버함수를 호출한 객체 자신의 주소를 가리키는 포인터이다.
* 이름을 같게 사용하는 경우, this->를 붙여야 컴파일러가 멤버변수와 매개변수를 구분할 수 있다.
```
int main() {
	Triangle tri1;
	cout << "삼각형의 면적은 " << tri1.getArea() << endl;
	Triangle tri2(10);
	cout << "삼각형의 면적은 " << tri2.getArea() << endl;
	Triangle tri3(10,2);
	cout << "삼각형의 면적은 " << tri3.getArea() << endl;
	return 0;
}
```
* tri2와 tri3의 주소를 this가 가리키고, 각 대입값을 w와 h에 넣는다
* 대입된 값을 getArea가 산출한다.
<img src="./sbj 4-1-3.png">

# 실습과제 4
```
class Triangle {
private:
	int w, h;
public:
	Triangle() : Triangle(1, 1) {}
	Triangle(int a, int b) : w(a), h(b) { cout << "폭" << w << ", 높이" << h << "인 삼각형 생성" << endl; }
	int getWidth() { return w; }
	void setWidth(int a) { w = a; }
	int getHeight() { return h; }
	void setHeight(int b) { h = b; }
	float getArea() { return 0.5 * w * h; }
	~Triangle() { cout << "폭" << w << ",높이" << h << " 삼각형소멸" << endl; }
};
```
* 삼각형 클래스 선언 및 각 멤버함수 초기화
```
int main() {
	Triangle tri[3] = { Triangle(2,2), Triangle(4,4), Triangle(6,6) };
	for (int i = 0; i < 3; i++)	cout << "삼각형" << i << "의 면적은 " << tri[i].getArea() << endl;
	return 0;
}
```
* 삼각형 클래스의 객체 배열 tri 선언 및 초기화
* for문을 통해 멤버함수를 연속해서 출
<img src="./sbj 4-1-4.png">

# 실습과제 5
```
class Triangle {
private:
	int w, h;
public:
	Triangle() : Triangle(1, 1) {}
	Triangle(int a, int b) : w(a), h(b) {}
	int getWidth() { return w; }
	void setWidth(int a) { w = a; }
	int getHeight() { return h; }
	void setHeight(int b) { h = b; }
	float getArea() { return 0.5 * w * h; }
};
```
* 삼각형 클래스 선언 및 멤버함수 초기화
```
int main() {
	Triangle tri[3] = { Triangle(2,2), Triangle(4,4), Triangle(6,6) };
	Triangle* p = tri;
```
* Triangle의 객체 배열 tri 선언 및 초기회
* tri 배열의 첫 번째 주소를 가리키는 p 선언
```
	cout << "방법 1" << endl;
	for (int i = 0; i < 3; i++)	cout << "삼각형" << i << "의 면적은 " << (tri + i)->getArea() << endl;
```
* 배열명 + i
* tri + i번째 원소의 주소이며, ->로 해당 객체의 멤버함수를 호출한다.
* 배열명은 포인터 상수이므로. ++ 연산은 불가하다.
```
	cout << "방법 2" << endl;
	for (int i = 0; i < 3; i++)	cout << "삼각형" << i << "의 면적은 " << (p + i)->getArea() << endl;
```
* p + i
* p는 tri[0]을 가리키므로, + i씩 올라가며 해당하는 객체의 멤버함수를 호출한다.
```
	cout << "방법 3" << endl;
	for (int i = 0; i < 3; i++)	cout << "삼각형" << i << "의 면적은 " << p[i].getArea() << endl;
```
* 포인터도 배열처럼 인덱스 연산자를 활용할 수 있다.
* p[i]는 *(p + i)와 동일하므로, 객체 자체를 가져오기 때문에 .연산자를 사용한다.
```
	cout << "방법 4" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "삼각형" << i << "의 면적은 " << p->getArea() << endl;
		p++;
	}
	return 0;
}
```
* p가 가리키는 현재 객체의 멤버함수를 호출한 뒤에 p++로 포인터 자체를 이동시킨다.
<img src="./sbj 4-1-5.png">
