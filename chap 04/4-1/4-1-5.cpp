// 제  목 : 5주차 실습과제 4-1-5
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
	Triangle tri[3] = { Triangle(2,2), Triangle(4,4), Triangle(6,6) };
	Triangle* p = tri;

	cout << "방법 1" << endl;
	for (int i = 0; i < 3; i++)	cout << "삼각형" << i << "의 면적은 " << (tri + i)->getArea() << endl;

	cout << "방법 2" << endl;
	for (int i = 0; i < 3; i++)	cout << "삼각형" << i << "의 면적은 " << (p + i)->getArea() << endl;

	cout << "방법 3" << endl;
	for (int i = 0; i < 3; i++)	cout << "삼각형" << i << "의 면적은 " << p[i].getArea() << endl;

	cout << "방법 4" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "삼각형" << i << "의 면적은 " << p->getArea() << endl;
		p++;
	}
	return 0;
}

/*
삼각형0의 면적은 2
삼각형1의 면적은 4
삼각형2의 면적은 6
*/
