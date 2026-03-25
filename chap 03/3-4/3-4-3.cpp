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
	float getArea();
	~Triangle();
};

Triangle::Triangle() : Triangle(1, 1) { cout << "폭" << w << ",높이" << h << " 삼각형생성" << endl; }
Triangle::Triangle(int a, int b) : w(a), h(b) {}
int Triangle::getWidth() { return w; }
void Triangle::setWidth(int a) { w = a; }
int Triangle::getHeight() { return h; }
void Triangle::setHeight(int b) { h = b; }
float Triangle::getArea() { return (1.0 / 2.0) * w * h; }
Triangle::~Triangle() { cout << "폭" << w << ",높이" << h << " 삼각형소멸" << endl; }

int main() {
	Triangle tri;
	tri.setWidth(3);
	tri.setHeight(5);
	cout << "삼각형의 폭은 " << tri.getWidth() << endl;
	cout << "삼각형의 높이는 " << tri.getHeight() << endl;
	cout << "삼각형의 높이는 " << tri.getArea() << endl;
	return 0;
}

/*
폭1,높이1 삼각형생성
삼각형의 폭은 3
삼각형의 높이는 5
삼각형의 면적은 7.5
폭3,높이5 삼각형소멸
*/