// 제  목 : 5주차 실습과제 4-1-2
// 날  짜 : 2026년 4월 2일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
using namespace std;

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

int main() {
	Triangle tri;
	Triangle* p = &tri;
	p -> setWidth(3);
	p -> setHeight(5);
	cout << "삼각형의 면적은 " << tri.getArea() << endl;
	return 0;
}

/*
삼각형의 면적은 7.5
*/
