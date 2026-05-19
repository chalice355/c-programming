#include <iostream>
#include <cstring>
using namespace std;

class Point3D {
	int a, b, c;
public:
	Point3D() : Point3D(0, 0, 0) {}
	Point3D(int x) : Point3D(x, 0, 0) {}
	Point3D(int x, int y) : Point3D(x, y, 0) {}
	Point3D(int x, int y, int z) : a(x), b(y), c(z) {}
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