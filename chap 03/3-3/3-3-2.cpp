// **********************************************
// Á¦ ¸ñ : ½Ç½À°úÁ¦ 2
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
Triangle::Triangle() : Triangle(1,1) {}
Triangle::Triangle(int a, int b) : w(a), h(b) {
	cout << "¹Øº¯ " << w << " ,³ôÀÌ " << h << "ÀÎ »ï°¢Çü »ý¼º" << endl;
}
Triangle::~Triangle() {
	cout << "¹Øº¯ " << w << " ,³ôÀÌ " << h << "ÀÎ »ï°¢Çü ¼Ò¸ê" << endl;
}
double Triangle::getArea() {
	return (w * h) * 0.5;
}

int main() {
	Triangle tri1; //¹Øº¯,³ôÀÌ 1·Î ÃÊ±âÈ­
	cout << "»ï°¢ÇüÀÇ ¸éÀûÀº " << tri1.getArea() << endl;

	Triangle tri2(2, 4); //¹Øº¯=2,³ôÀÌ=4·Î ÃÊ±âÈ­
	cout << "»ï°¢ÇüÀÇ ¸éÀûÀº " << tri2.getArea() << endl;
	return 0;
}


/*
¹Øº¯ 1³ôÀÌ 1ÀÎ »ï°¢Çü »ý¼º
»ï°¢ÇüÀÇ ¸éÀûÀº 0.5
¹Øº¯ 2³ôÀÌ 4ÀÎ »ï°¢Çü »ý¼º
»ï°¢ÇüÀÇ ¸éÀûÀº 4
¹Øº¯ 2³ôÀÌ 4ÀÎ »ï°¢Çü ¼Ò¸ê
¹Øº¯ 1³ôÀÌ 1ÀÎ »ï°¢Çü ¼Ò¸ê
*/