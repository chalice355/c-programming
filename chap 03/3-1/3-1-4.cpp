// **********************************************
// 제  목 : 1주차 실습과제 1-1
// 날  짜 : 2026년 3월 6일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
using namespace std;

class Rectangle {
public:
	int x = 1;
	int y = 2;
	int width = 3;
	int height = 4;
	int getArea();
	int getPerimeter();
	void getBR();
};

int Rectangle::getArea() {
	return width * height;
}

int Rectangle::getPerimeter() {
	return (width + height) * 2;
}

void Rectangle::getBR() {
	cout << "사각형의 우측하단의 좌표는 (" << x + width << ", " << y - height << ")" << endl;
}

int main() {
	Rectangle rect;
	cout << "사각형의 면적은 " << rect.getArea() << endl;
	cout << "사각형의 둘레 길이는 " << rect.getPerimeter() << endl;
	rect.getBR();
}