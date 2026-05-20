#include <iostream>
using namespace std;
// 클래스 선언 추가
class Triangle {
	static int NumOfTriangles;
public:
	Triangle() { NumOfTriangles++; }
	~Triangle() { NumOfTriangles--; }
	static int getNumOfTriangle() { return NumOfTriangles; }
};

int Triangle::NumOfTriangles = 0;

int main() {
	Triangle* tri1 = new Triangle[5];
	cout << "생성된 삼각형의 개수 :" << Triangle::getNumOfTriangle()
		<< endl;
	delete[] tri1;
	Triangle tri2[15];
	cout << "생성된 삼각형의 개수 :" << Triangle::getNumOfTriangle()
		<< endl;
	return 0;
}

/*
생성된 삼각형의 개수: 5
생성된 삼각형의 개수: 15
*/