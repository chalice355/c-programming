// **********************************************
// 제  목 : 3주차 실습과제 3-2-2
// 날  짜 : 2026년 3월 6일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
using namespace std;

class Triangle {
	int w, h;
public:
	Triangle();
	Triangle(int a, int b);
	float getArea();
};

float Triangle::getArea() {
	return (1.0 / 2.0) * w * h;
}

Triangle::Triangle() : Triangle(1, 1) {}
Triangle::Triangle(int a, int b) : w(a), h(b) {}
int main() {
	Triangle tri1;
	cout << "삼각형의 면적은 " << tri1.getArea() << endl;

	Triangle tri2(2, 4);
	cout << "삼각형의 면적은 " << tri2.getArea() << endl;
	return 0;
}