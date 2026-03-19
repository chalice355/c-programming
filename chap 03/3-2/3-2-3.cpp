// **********************************************
// 제  목 : ３주차 실습과제 ３-２-3
// 날  짜 : 2026년 3월 6일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
using namespace std;

class Sphere {
	int r;
public:
	Sphere();
	Sphere(int a);
	float getVol();
};

float Sphere::getVol() {
	return (4.0 / 3.0) * 3.14 * r * r * r;
}

Sphere::Sphere() : Sphere(1) {}
Sphere::Sphere(int a) : r(a) {}
int main() {
	Sphere sph1;
	cout << "구의 부피는 " << sph1.getVol() << endl;

	Sphere sph2(3);
	cout << "구의 부피는 " << sph2.getVol() << endl;
	return 0;
}