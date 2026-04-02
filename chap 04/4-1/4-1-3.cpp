// 제  목 : 5주차 실습과제 4-1-3
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
	Triangle(int a) { this->w = a, this->h = 1; }
	Triangle(int a, int b) { this->w = a, this->h = b; }
	float getArea() { return 0.5 * w * h; }
};

int main() {
	Triangle tri1;
	cout << "삼각형의 면적은 " << tri1.getArea() << endl;
	Triangle tri2(10);
	cout << "삼각형의 면적은 " << tri2.getArea() << endl;
	Triangle tri3(10,2);
	cout << "삼각형의 면적은 " << tri3.getArea() << endl;
	return 0;
}
