# 실습과제 1
## 접근지정자가 왜 필요한가?
* 
## 생성자와 setter 멤버함수는 모두 멤버변수를 설정하는 기능이다. 차이점을 설명하라.
* 
## 객체지향형 언어의 특징인 캡슐화와 정보은닉을 설명하라.
* 

# 실습과제 2
```
#include <iostream>
using namespace std;

class Circle {
private:
	int radius;			// public -> private
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
	waffle.setRadius(5);
	cout << "원의 반지름은 " << waffle.getRadius() << endl;
	return 0;
}
```
# 실습과제 3

# 실습과제 4
