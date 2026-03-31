#include <iostream>
using namespace std;

class Triangle {
private:
	int w, h;
public:
	Triangle() : Triangle(1, 1) {}
	Triangle(int a, int b) : w(a), h(b) { cout << "Æø" << w << ", ³ôÀÌ" << h << "ÀÎ »ï°¢Çü »ý¼º" << endl; }
	int getWidth() { return w; }
	void setWidth(int a) { w = a; }
	int getHeight() { return h; }
	void setHeight(int b) { h = b; }
	float getArea() { return 0.5 * w * h; }
	~Triangle() { cout << "Æø" << w << ",³ôÀÌ" << h << " »ï°¢Çü¼Ò¸ê" << endl; }
};

int main() {
	Triangle tri;
	tri.setWidth(3);
	tri.setHeight(5);
	cout << "»ï°¢ÇüÀÇ ¸éÀûÀº " << tri.getArea() << endl;
	return 0;
}

/*
Æø1,³ôÀÌ1ÀÎ »ï°¢Çü »ý¼º
»ï°¢ÇüÀÇ ¸éÀûÀº 7.5
Æø3,³ôÀÌ5ÀÎ »ï°¢Çü ¼Ò¸ê
*/