// **********************************************
// 제  목 : 5주차 실습과제 4-3-3
// 날  짜 : 2026년 4월 9일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};
Circle::Circle() {
	radius = 1; cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int r) {
	radius = r; cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
}

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