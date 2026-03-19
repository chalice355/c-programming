// **********************************************
// 제  목 : ３주차 실습과제 ３-２-4
// 날  짜 : 2026년 3월 6일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
using namespace std;

class Rectangle {
	int w, h, x, y;
public:
	Rectangle();
	Rectangle(int a, int b);
	Rectangle(int a, int b, int c, int d);
	void getArea();
	void getPerimeter();
	void getCord();
};

void Rectangle::getArea() {
	cout << "rect1의 면적은 " << w * h << endl;
}

void Rectangle::getPerimeter() {
	cout << "rect2의 둘레길이는 " << (w + h) * 2 << endl;
}

void Rectangle::getCord() {
	cout << "rect3의 우측하단의 좌표는 (" << x + w << ", " << y - h << ")" << endl;
}

Rectangle::Rectangle() : Rectangle(1, 1, 1, 1) {}
Rectangle::Rectangle(int a, int b) : Rectangle(a, b, 1, 1) {}
Rectangle::Rectangle(int a, int b, int c, int d) : x(a), y(b), w(c), h(d) {}
int main() {
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3, 5, 2, 4);

	rect1.getArea();
	rect2.getPerimeter();
	rect3.getCord();
}