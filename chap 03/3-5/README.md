# 실습과제 1
## 함수를 사용하는 이유를 설명하라.
* 사용 빈도가 높은 기능들을 모아 구현하여 호출하는 것으로 간단하게 작동할 수 있는 장점이 있기 때문이다.
* 비슷하게 동작하는 기능들을 모아 함수의 형태로 만드는 것으로 코드의 중복 사용을 방지하고 재활용 하는 것으로 코드의 길이와 개발 기간을 단축할 수 있기 때문이다.

## 짧은 코드를 갖는 함수를 자주 호출하면 발생하는 함수의 오버헤드를 설명하라.
* 오버헤드의 기본적인 의미는 어떠한 활동에 따라 소비되는 비용(운영비용 등)을 말한다. 짧은 내용의 함수를 여러 번 호출하는 것은 함수호출 -> 기능의 반복이다. 그 내용을 직접 실행시키는 것 보다 느려질 뿐더러 비용(시간, 메모리, 인력 등)이 증가하여 안하니만 못하게 된다.
* 이 문제를 해결하기 위해 인라인 함수를 사용할 수 있으며, 이를 사용하게 되면, 호출에 따른 오버헤드 없이 실행할 수 있게 된다.

## 12페이지 예제에서 인라인함수가 치환되면 private 멤버 변수를 직접 접근하게 된다. 문법오류가 아닌가?
* 컴파일러가 내부적으로 최적화 하는 과정일 뿐, 실제로 코드가 완전히 대체되는 것이 아니기 때문에, 여전히 클래스의 멤버함수가 호출되는 것으로 인식하여 접근한다.

## 인라인함수는 소스코드에서는 함수이지만 기계어로 번역되면 함수가 아니다. 이렇게 복잡하게 만든 이유를 설명하라. 다시 말해, 처음부터 함수를 안 쓰면 안되나요?
* 짧은 내용이더라도 여러 곳에서 사용한다면, 하나하나 작성하고 수정하여야하기 때문에 보수의 용이성을 위해서라도 함수를 사용하는 것이 합리적이다. 

# 실습과제 2
```
class Triangle {
private:
	int w, h;
public:
	Triangle() : Triangle(1, 1) {}
	Triangle(int a, int b) : w(a), h(b) { cout << "폭" << w << ", 높이" << h << "인 삼각형 생성" << endl; }
```
* 기본 생성자 선언 및 (1, 1)로 초기화
* 타겟 생성자 선언 및 초기화
```
	int getWidth() { return w; }
	void setWidth(int a) { w = a; }
	int getHeight() { return h; }
	void setHeight(int b) { h = b; }
```
* 너비와 높이 getter와 setter 선언 및 초기화
```
	float getArea() { return 0.5 * w * h; }
	~Triangle() { cout << "폭" << w << ",높이" << h << " 삼각형소멸" << endl; }
};
```
* 너비 구하는 함수 선언 및 초기화
* 소멸자 선언 및 초기화
<img src="./sbj 3-5-2.png">

# 실습과제 3

## 예제 1
```
#include <iostream>
#include <string>
using namespace std;
```
* stirng 사용을 위해 string 라이브러리 include
```
class Picture {
private:
	int w, h;
	string place;
public:
	Picture() : w(5), h(7), place("모름") {}
	Picture(int a, int b, string p) : w(a), h(b), place(p) {}
	int getWidth() { return w; }
	int getHeight() { return h; }
	string getPlace() { return place; }
};
```
* Picture 클래스 선언 및 멤버변수와 멤버함수 선언/초기화
* 기본 생성자 선언 및 초기화
* 타겟 생성자 선언
* 너비와 높이 getter 선언 및 초기화
* string 타입의 장소 getter 선언 및 초기화
```
int main() {
	Picture pic;	// 5x7 크기, 촬영 장소 "모름"
	Picture mt(10, 14, "한라산");	// 10x14 크기, 촬영 장소 "한라산"
	cout << pic.getWidth() << "x" << pic.getHeight() << " " << pic.getPlace() << endl;
	cout << mt.getWidth() << "x" << pic.getHeight() << " " << mt.getPlace() << endl;
}
```
* Picture 객체 pic 생성 (pic = 기본 생성자 호출)
* Picture 객체 my 생성 (mt = 타겟 생성자에 변수 대입 호출)
<img src="./sbj 3-5-3-1.png">

## 예제 2
```
class Coffee {
private:
	int c, s, m, w;
public:
	Coffee() : c(10), s(0), m(0), w(0) {}
	Coffee(int a, int b, int c, int d) : c(a), s(b), m(c), w(d) {}
	void show() {
		cout << "coffee ";
		for (int i = 0; i < c; i++)	cout << "*";
		cout << endl;
		cout << "sugar ";
		for (int i = 0; i < s; i++)	cout << "*";
		cout << endl;
		cout << "milk ";
		for (int i = 0; i < m; i++)	cout << "*";
		cout << endl;
		cout << "water ";
		for (int i = 0; i < w; i++)	cout << "*";
		cout << endl;
	}
};
```
* Coffer 클래스 선언
* 기본 생성자 선언 및 초기화
* 타겟 생성자 선언
* show 선언 및 초기화(출력문)
```
int main() {
	Coffee espresso;	// 커피 10, 설탕 0, 우유 0, 물 0
	Coffee americano(5, 0, 0, 10);	// 커피 5, 설탕 0, 우유 0, 물 10
	Coffee cappucchino(5, 1, 5, 2);	// 커피 5, 설탕 1, 우유 5, 물 2
	Coffee mySweet(3, 7, 5, 5);	// 커피 3, 설탕 7, 우유 5, 물 5

	espresso.show();
	cout << endl;
	mySweet.show();
}
```
* 여러 개의 Coffee의 객체 생성
* 특정 객체를 show에 대입 호출
<img src="./sbj 3-5-3-2.png">

## 예제 3
```
class Storage {
private:
	float sum = 0;
	int count = 0;
```
* Storage 클래스의 멤버 변수 선언
* count는 배열의 순서를 위해 사용
```
public:
	double data[10] = {};
	void put(double x) {
		if (count < 10)
			data[count++] = x;
	}
```
* data 배열을 10칸으로 선언
* put 함수 선언
* put은 데이터를 넣으며 count++
```
	float getAvg() {
		sum = 0;
		for (int i = 0; i < count; i++)
			sum += data[i];
		return (sum / count);
	}
```
* 평균 체온을 구하는 함수 선언
* 누적 합(sum)을 0으로 초기화
* count = i 번째 데이터를 누적 합에 ++
* 모든 누적합(sum)을 count만큼 나누어 평균값 도출
```
	void dump() {
		for (int i = 0; i < count; i++) {
			cout << data[i];
			if (i < count - 1) cout << " ";
		}
		cout << endl;
	}
};
```
* data에 저장된 모든 체온 값을들 출력
* 체온 값 출력 시, 사이에 공백을 추가
* data에 값이 저장된 마지막 i번째 값까지 반복
```
int main() {
	Storage a;
	a.put(36.7);
	a.put(36.9);
	a.put(36.4);
	a.dump();
	cout << "평균 체온은 " << a.getAvg() << "입니다." << endl;
}
```
* Storage클래스 a라는 객체 선언
* 체온값을 데이터에 순서대로 하나씩 삽입
* 삽입된 데이터 3개를 모두 출력
* 산출된 평균 체온값과 문장을 출력
<img src="./sbj 3-5-3-7.png">
