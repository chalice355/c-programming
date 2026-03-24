// **********************************************
// Á¦ ¸ñ : ½Ç½À°úÁ¦ 3
// ³¯ Â¥ : 2026³â 3¿ù24ÀÏ
// ÀÛ¼ºÀÚ : 2001218 ÀÓ¼º¹è
// **********************************************

#include <iostream>
using namespace std;

class Triangle {
public:
	int w, h;
	Triangle();
	Triangle(int a, int b);
	~Triangle();
	double getArea();
};
Triangle::Triangle() : Triangle(4, 8) {}
Triangle::Triangle(int a, int b) : w(a), h(b) {
	cout << "¹Øº¯ " << w << " ,³ôÀÌ " << h << "ÀÎ »ï°¢Çü »ý¼º" << endl;
}
Triangle::~Triangle() {
	cout << "¹Øº¯ " << w << " ,³ôÀÌ " << h << "ÀÎ »ï°¢Çü ¼Ò¸ê" << endl;
}
double Triangle::getArea() {
	return (w * h) * 0.5;
}

Triangle tri1;
Triangle tri2(2,2);

int main() {
	cout << "»ï°¢ÇüÀÇ ¸éÀûÀº " << tri1.getArea() << endl;

	cout << "»ï°¢ÇüÀÇ ¸éÀûÀº " << tri2.getArea() << endl;
	return 0;
}


/*
¹Øº¯ 4³ôÀÌ 8ÀÎ »ï°¢Çü »ý¼º
¹Øº¯ 2³ôÀÌ 2ÀÎ »ï°¢Çü »ý¼º
»ï°¢ÇüÀÇ ¸éÀûÀº 2
»ï°¢ÇüÀÇ ¸éÀûÀº 16
¹Øº¯ 2³ôÀÌ 2ÀÎ »ï°¢Çü ¼Ò¸ê
¹Øº¯ 4³ôÀÌ 8ÀÎ »ï°¢Çü ¼Ò¸ê
*/