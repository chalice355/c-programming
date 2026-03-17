// **********************************************
// 제  목 : 1주차 실습과제 1-1
// 날  짜 : 2026년 3월 6일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
using namespace std;

class Sphere {
public:
	float radius;
	float pi = 3.14;
	float getSurfaceArea();
	float getVolume();
};

float Sphere::getSurfaceArea() {
	return 4 * pi * radius * radius;
}

float Sphere::getVolume() {
	return (4.0 / 3.0) * pi * radius * radius * radius;
}

int main() {
	Sphere sp;
	sp.radius = 5;
	cout << "구의 부피는 " << sp.getVolume() << endl;
	cout << "구의 표면적은 " << sp.getSurfaceArea() << endl;
}