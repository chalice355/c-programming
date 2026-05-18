#include <iostream>
#include <cstring>
using namespace std;

class Point3D {
	int a, b, c;
public:
	Point3D(int x = 0, int y = 0, int z = 0) : a(x), b(y), c(z) {}
	void show() {
		cout << "3차원 점의 좌표는 (" << a << ", " << b << ", " << c << ")" << endl;
	}
};

int main() {
	Point3D p0;
	p0.show();
	Point3D p1(1);
	p1.show();
	Point3D p2(1, 2);
	p2.show();
	Point3D p3(1, 2, 3);
	p3.show();
	return 0;
}

/*
3차원 점의 좌표는 (0,0,0)
3차원 점의 좌표는 (1,0,0)
3차원 점의 좌표는 (1,2,0)
3차원 점의 좌표는 (1,2,3)
*/