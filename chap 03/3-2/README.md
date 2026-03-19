# 실습과제 1
## C++에서 생성자를 통하여 멤버변수의 초기화를 하는 이유를 설명하라.
* 쓰레기 값(garbage value)이 들어가 올바른 작동을 보장하지 못하기 때문이다.

## 생성자 작성시 생성자 몸체에서 멤버를 초기화하는 것 보다 멤버 초기화 리스트에서 초기화하는 이유를 설명하라.
* 몸체에서 초기화 하는 것은 대입하는 것이고, 멤버 초기화 리스트가 올바른 초기화 방법이기 때문이다.
* 생성자 호출되면 멤버 초기화 리스트 -> 함수 몸체 순서로 실행되어 멤버 초기화 리스트에 작성 시, 실행 속도가 빠르다.

## 위임, 타겟 생성자로 나누어 작성하는 이유를 설명하라
* 코드의 중복 제거와 유지보수의 편리, 일관성 유지 등의 이유가 있다.
* 
## 함수 몸체(body)에서 생성자를 직접 호출하면 어떻게 되는지 조사해보라
* 임시 객체를 다시 생성한 후에 즉시 소멸한다.

# 실습과제 2
```
class Triangle {
```
* Triangle 클래스 시작
```
	int w, h;
```
* 멤버변수 선언, 외부 접근 불가
```
public:
```
* 이 아래는 외부 접근 가능
```
	Triangle();
```
* 기본 생성자 선언
```
	Triangle(int a, int b);
```
* 매개변수 2개를 받는 생성자 선언
```
	float getArea();
};
```
* 넓이 값을 반환하는 멤버 함수 선언
```
float Triangle::getArea() {
```
* Triangle 클래스의 getArea함수 정의 시작
```
	return (1.0 / 2.0) * w * h;
}
```
* 삼각형 넓이 공식 계산 후 결과값 반환
```
Triangle::Triangle() : Triangle(1, 1) {}
```
* Triangle 위임 생성자에서 타겟 생성자로 위임(1, 1)
```
Triangle::Triangle(int a, int b) : w(a), h(b) {}
```
* Triangle 타겟 생성자로, 멤버 초기화 리스트{w(a), h(b)}를 각각 초기화{w -> a, h -> b}
```
int main() {
```
* 메인 시작
```
	Triangle tri1;
```
* 객체1 생성, (1, 1)로 초기화
```
	cout << "삼각형의 면적은 " << tri1.getArea() << endl;
```
* tri1.getArea 호출, 넓이값 반환 및 문장 출력
```
	Triangle tri2(2, 4);
```
* 객체2 생성, (w=2, h=4)로 초기화
```
	cout << "삼각형의 면적은 " << tri2.getArea() << endl;
```
* tri2.getArea 호출, 넓이값 반환 및 문장 출력
```
	return 0;
}
```
* 함수 종료
<img src="./sbj 3-2-2.png">

# 실습과제 3
```
class Sphere {
	int r;
public:
	Sphere();
	Sphere(int a);
	float getVol();
};
```
* Sphere 클래스 선언 및 매개변수와 생성자 선언
```
float Sphere::getVol() {
	return (4.0 / 3.0) * 3.14 * r * r * r;
}
```
* 구의 부피 구하는 함수 정의(구의 부피 계산 공식)
```
Sphere::Sphere() : Sphere(1) {}
```
* 기본 생성자 1로 초기화(타겟 생성자에 위임하여 1로 초기화)
```
Sphere::Sphere(int a) : r(a) {}
```
* 매개변수 생성자 3으로 초기화
```
int main() {
	Sphere sph1;
	cout << "구의 부피는 " << sph1.getVol() << endl;

	Sphere sph2(3);
	cout << "구의 부피는 " << sph2.getVol() << endl;
	return 0;
}
```
* 각 sph1과 sph2의 부피를 계산한 값을 출력
<img src="./sbj 3-2-3.png">

# 실습과제 4
