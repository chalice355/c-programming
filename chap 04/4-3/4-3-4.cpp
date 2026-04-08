#include <iostream>
using namespace std;

class Triangle {
private:
	int width, height;
public:
	Triangle();
	Triangle(int a, int b);
	int setWH(int a, int b) { width = a, height = b; }
	float getArea();
	~Triangle();
};

Triangle::Triangle() : Triangle(1, 1) { cout << "폭" << width << ",높이" << height << " 삼각형생성" << endl; }
Triangle::Triangle(int a, int b) : width(a), height(b) {}
float Triangle::getArea() { return (1.0 / 2.0) * width * height; }
Triangle::~Triangle() { cout << "폭" << width << ",높이" << height << " 삼각형소멸" << endl; }

int main() {
	Triangle* pArray = new Triangle[3];
	pArray[0].getArea();

	for (int i = 0; i < 3; i++)
		cout << pArray[i].getArea() << '\n';
	Triangle* p = pArray;
	for (int i = 0; i < 3; i++) {
		cout << p->getArea() << '\n';
		p++;
	}
	delete[] pArray;
	return 0;
}

/*
밑변 1높이 1인 삼각형 생성
밑변 2높이 2인 삼각형 생성
밑변 4높이 4인 삼각형 생성
삼각형의 면적은 0.5
삼각형의 면적은 2
삼각형의 면적은 8
밑변 4높이 4인 삼각형 소멸
밑변 2높이 2인 삼각형 소멸
밑변 1높이 1인 삼각형 소멸
*/