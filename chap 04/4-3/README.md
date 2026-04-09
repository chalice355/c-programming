# 실습과제 1
## 메모리 누수를 설명하라.
* new로 동적 할당한 메모리를 delete로 해제하지 않아 프로그램이 끝날 때까지 해당 메모리가 반환되지 않는 현상이다.

## 메모리 누수가 왜 심각한 문제를 발생시키는지 설명하라.
* delete를 호출하기 전까지 절대 자동으로 해제되지 않으므로, 메모리 사용이 계속해서 누적되어 가용 메모리가 줄어들게 되고, 시스템 전체가 느려지다가 결국, 프로그램이 강제 종료가 된다.
* 메모리는 공유자원이기 때문에, 다른 프로그램들도 가용 가능 자원이 모자라게 된다.

## 메모리 누수를 방지하는 방법을 설명하라.
* new와 delete를 항상 쌍으로 작성하는 것으로 메모리의 반환을 요구한다.
* 배열은 반드시 delete[]로 올바르게 메모리 반환을 한다.
* 예외 발생 시, delete에 도달하지 못할 수 있으므로, 스마트 포인터를 사용하는 것이 좋다.

## C++ 스마트 포인터 클래스에 대해 조사하라
* 포인터를 객체로 감싸서 범위를 벗어나면 자동으로 메모리를 해제해주는 클래스이다.
* <memory>헤더에 정의되어있으며, C++11부터 도입되었다.

# 실습과제 2
```
int main() {
	int radius;
	while (true) {
		cout << "반지름 입력(음수이면 종료)>> ";
		cin >> radius;
		if (radius < 0) break;
		Circle* p = new Circle(radius);
		cout << "원의 면적:" << p->getArea() << endl;
		delete p;		// < 추가
	}
	return 0;
}
```
* main 함수의 문제점 :

delete[]를 하지 않아 메모리 반환이 실행되지 않았다. 따라서 메모리 누수로 이어지게 되고, 메모리 낭비와 메모리 부족의 원인이 된다.
이 방식의 메모리 누수는 포인터가 가리키는 주소가 덮어씌워져, 이전에 가리키던 주소는 살아있지만, 지금은 가리키지 않아 더이상 건드릴 수 없게 된다.


* 해결 방법 :

delete [] p;를 return 0;의 앞에 추가하여 메모리의 반환을 실행할 수 있도록 한다.

# 실습과제 3
```
int main() {
    Circle* pArray = new Circle[3];
    Circle* p = pArray;    // pArray 주소 보존용

    for (int i = 0; i < 3; i++) {
        cout << p->getArea() << endl;
        p++;               // p만 이동, pArray는 그대로
    }
    delete[] pArray;       // 원래 주소로 정상 해제
    return 0;
}
```
* main 함수의 문제점 : 

포인터 주소는 default로 배열의 첫번째 원소의 주소를 가리킨다.
하지만, ++연산자를 통해 원소를 이동하는 경우, 포인터 주소를 직접 이동시키는 방식이므로, 원래 위치(원소 첫번째 주소)로 되돌리지 않고 delete[]를 하게 되면, 정상적으로 반환이 되지 않는다.


해결 방법 : 

Circle* p = pArray;를 추가하여 간접적으로 이동해야한다.
이 방식을 사용하면, p를 통해 간접적으로 이동시키기 때문에 pArray는 그대로 배열의 원소 첫번째 주소를 가리킨다.
이 때에, pArray를 delete[]하게 되면, 정상적으로 메모리를 반환할 수 있게 된다.

# 실습과제 4
```
class Triangle {
private:
	int width, height;
public:
	Triangle() : width(1), height(1) { cout << "밑변 " << width << "높이 " << height << "인 삼각형 생성" << endl; }
	Triangle(int a, int b) : width(a), height(b) { cout << "밑변 " << width << "높이 " << height << "인 삼각형 생성" << endl; }
	void setWH(int a, int b) { width = a; height = b; }
	float getArea() { return 0.5 * width * height; }
	~Triangle() { cout << "밑변 " << width << "높이 " << height << "인 삼각형 소멸" << endl; }
};
```
* 클래스 선언 및 초기화
* 기본 밑변과 높이를 각각 1로 초기화
* setter 선언(setWH) 및 초기화
* 너비를 구하는 함수 선언 및 정의
* 소멸자 선언
```
int main() {
	Triangle* pArray = new Triangle[3];
	pArray[1].setWH(2, 2);
	pArray[2].setWH(4, 4);
```
* 두 번째 원소를 (2,2)로 변경
* 세 번째 원소를 (3, 3)로 변경
```
	Triangle* p = pArray;
	for (int i = 0; i < 3; i++) {
		cout << "삼각형의 면적은 " << p->getArea() << endl;
		p++;
	}
	delete[] pArray;
	return 0;
}
```
* 포인터를 직접 옮기지 않고, p를 통해 간접적으로 이동
* pArray를 delete[]
<img src="./sbj 4-3-4.png">

# 실습과제 5
```
class Circle {
	int radius;
public:
	Circle();
	~Circle() { }
	void setRadius(int r) { radius = r; }
	double getVolume() { return (4.0 / 3.0) * 3.14 * radius * radius * radius; }
};
Circle::Circle() {
	radius = 1;
}
```
* 클래스 선언 및 생성자와 함수 선언 및 초기화/정의
* 구의 반지름을 기본 1로 초기화
```
int main() {
	cout << "생성하고자 하는 구의 개수: ";
	int n, r;
	cin >> n;
	Circle* pArray = new Circle[n];
```
* int n,r을 선언하여 원의 개수 n, 구의 반지름 r을 의미
* n을 입력받고 n개 만큼의 구 생성
```
	for (int i = 0; i < n; i++) {
		cout << "구" << i + 1 << "의 반지름: "; // 도움말 출력
		cin >> r; // 반지름 입력
		pArray[i].setRadius(r);
	}
```
* 반복문을 수행하며 각 원의 반지름을 입력받는다.
* 입력받은 반지름을 r에 저장
```
	Circle* p = pArray;
	for (int i = 0; i < n; i++) {
		cout << "구" << i + 1 << "의 부피 " << p->getVolume() << endl;
		p++;
	}
	delete[] pArray;
	return 0;
}
```
* 반복문을 수행하며 i 번째 구의 부피를 출력
<img src="./sbj 4-3-5.png">
