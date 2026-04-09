// **********************************************
// 제  목 : 5주차 실습과제 4-3-4
// 날  짜 : 2026년 4월 9일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
using namespace std;

class Triangle {
private:
	int width, height;
public:
	Triangle() : width(1), height(1) { cout << "밑변 " << width << "높이 " << height << "인 삼각형 생성" << endl; }
	Triangle(int a, int b) : width(a), height(b) { cout << "밑변 " << width << "높이 " << height << "인 삼각형 생성" << endl; }
	void setWH(int a, int b) { width = a; height = b; }
	float getArea() { return 0.5 * width * height; }
	~Triangle() { cout << "밑변 " << width << "높이 " << height << "인 삼각형 소멸" << endl; }
};

int main() {
	Triangle* pArray = new Triangle[3];
	pArray[1].setWH(2, 2);
	pArray[2].setWH(4, 4);

	Triangle* p = pArray;
	for (int i = 0; i < 3; i++) {
		cout << "삼각형의 면적은 " << p->getArea() << endl;
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
