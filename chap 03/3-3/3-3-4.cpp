// **********************************************
// 제 목 : 실습과제 4
// 날 짜 : 2026년 3월24일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
using namespace std;

class Sphere {
public:
	int radius;
	Sphere();
	Sphere(int r);
	~Sphere();
	double getVolume();
};

Sphere::Sphere() : Sphere(1) {}

Sphere::Sphere(int r) : radius(r) {
	cout << "반지름 " << radius << "인 구 생성" << endl;
}

Sphere::~Sphere() {
	cout << "반지름 " << radius << "인 구 소멸" << endl;
}

double Sphere::getVolume() {
	return (4.0 / 3.0) * 3.14 * radius * radius * radius;
}

int main() {
	Sphere sph1;
	cout << "구의 부피는 " << sph1.getVolume() << endl;

	Sphere sph2(3);
	cout << "구의 부피는 " << sph2.getVolume() << endl;
}

/*
반지름 1인 구 생성
구의 부피는 3.45
반지름 3인 구 생성
구의 부피는 110.42
반지름 3인 구 소멸
반지름 1인 구 소멸
*/