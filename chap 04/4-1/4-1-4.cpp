// 제  목 : 5주차 실습과제 4-4
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
	Triangle(int a, int b) : w(a), h(b) { cout << "폭" << w << ", 높이" << h << "인 삼각형 생성" << endl; }
	int getWidth() { return w; }
	void setWidth(int a) { w = a; }
	int getHeight() { return h; }
	void setHeight(int b) { h = b; }
	float getArea() { return 0.5 * w * h; }
	~Triangle() { cout << "폭" << w << ",높이" << h << " 삼각형소멸" << endl; }
};

int main() {
	Triangle tri[3] = { Triangle(2,2), Triangle(4,4), Triangle(6,6) };
	for (int i = 0; i < 3; i++)	cout << "삼각형" << i << "의 면적은 " << tri[i].getArea() << endl;
	return 0;
}
