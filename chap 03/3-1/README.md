# 실습과제 1
## 구조체와 클래스의 차이점을 설명하라
* 구조체는 기본적으로 public으로 상속하지만, 클래스는 private으로 상속한다.
* 구조체는 단순 데이터 묶음으로, 함수가 없어 연산을 수행하지 않는다.

## 클래스와 객체의 차이점을 설명하라
* 클래스가 설계도의 역할을 한다면, 객체는 그 설계도로 만든 실체이다.
* 클래스는 틀에 불과하여 메모리를 차지하지 않지만, 객체는 실제 데이터가 있기 때문에 메모리가 할당된다.

## sizeof(클래스명)의 결과값을 출력해보고 결과를 설명하라
```
class Empty {};                         
```
* 빈 클래스
```
class OnlyFunc {
    void hello() {}                      
};
```
* 함수만 존재
```
class WithInt {
    int a;                               
};
```
* int 1개
```
class WithIntChar {
    int a;                               
    char b;
};
```
* int + char
```
class WithVirtual {
    virtual void hello() {}
    int a;
};
```
* 가상함수
<img src="./sbj 3-1-1.png">
* 빈 클래스 : 1 byte
* 함수만 존재 : 1 byte
* int 1개 : 4 bytes
* int + char : 8 bytes
* 가상함수 : 16 bytes

* int와 char는 각각 4바이트와 1바이트이지만, 클래스의 전체 크기를 가장 큰 멤버(int = 4 bytes)의 배수로 맞추어야 하기 때문에 4 + 1 = 5에서 3바이트 만큼의 패딩이 붙는다.
* 가상함수 테이블 포인터(8 bytes) + int(4 bytes)에도 4바이트 만큼의 패딩이 붙어 16 바이트의 크기를 갖는다.

# 실습과제 2
```
class Triangle {
public:
	int width;
	int height;
	int getArea();
};
```
* 삼각형 클래스 선언 후, 너비와 높이, 그리고 넓이 멤버 변수를 선언
```
int Triangle::getArea() {
	return width * height / 2;
}
```
* 삼각형의 넓이를 구하는 함수를 구현
```
int main() {
	Triangle tri;
```
* 객체 생성
```
	tri.width = 6;
	tri.height = 4;
	cout << "삼각형의 면적은 " << tri.getArea() << endl;
}
```
* 멤버 변수에 갑을 저장하고, output으로 getArea()를 호출하여 저장된 값을 계산하여 결과값 출력
<img src="./sbj 3-1-2.png">

# 실습과제 3
```
class Sphere {
public:
	float radius;
	float pi = 3.14;
	float getSurfaceArea();
	float getVolume();
};
```
* 구의 클래스 선언, 반지름과 파이 멤버 변수 선언, 표면적 함수와 부피 함수 선언
```
float Sphere::getSurfaceArea() {
	return 4 * pi * radius * radius;
}
```
* 표면적 함수 구현
```
float Sphere::getVolume() {
	return (4.0 / 3.0) * pi * radius * radius * radius;
}
```
* 부피 함수 구현
```
int main() {
	Sphere sp;
	sp.radius = 5;
	cout << "구의 부피는 " << sp.getVolume() << endl;
	cout << "구의 표면적은 " << sp.getSurfaceArea() << endl;
}
```
* 구의 반지름을 5로 설정, 부피와 표면적 계산 후 결과값 출력

# 실습과제 4
