#include <iostream>
using namespace std;

class Triangle {
private:
	int w, h;
public:
	Triangle();
	Triangle(int a, int b);
	int getWidth();
	void setWidth(int a);
	int getHeight();
	void setHeight(int b);
	~Triangle();
};

Triangle::Triangle() : Triangle(1, 1) {}
Triangle::Triangle(int a, int b) : w(a), h(b) {
	if (w < 0 || h < 0) {
		w = 1, h = 1;
		cout << "길이는 양수여야함, 대신에 폭" << w << ",높이" << h << " 삼각형생성" << endl;
	}
	else w = a, h = b;
}
int Triangle::getWidth() { return w; }
void Triangle::setWidth(int a) {
	if (a < 0)	cout << "폭은 양수이어야 함" << endl;
	else w = a;
}
int Triangle::getHeight() { return h; }
void Triangle::setHeight(int b) {
	if (b < 0)	cout << "높이는 양수이어야 함" << endl;
	else h = b;
}
Triangle::~Triangle() { cout << "폭" << w << ",높이" << h << " 삼각형소멸" << endl; }

int main() {
	Triangle tri(-10, -5);
	tri.setWidth(-3);
	tri.setHeight(-5);
	tri.setWidth(3);
	tri.setHeight(5);
	cout << "삼각형의 폭은 " << tri.getWidth() << endl;
	cout << "삼각형의 높이는 " << tri.getHeight() << endl;
	return 0;
}


/*
길이는 양수여야함, 대신에 폭1,높이1 삼각형생성
폭은 양수이어야 함
높이는 양수이어야 함
폭3,높이5 삼각형소멸
*/