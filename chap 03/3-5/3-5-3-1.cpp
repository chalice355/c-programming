#include <iostream>
#include <string>
using namespace std;

class Picture {
private:
	int w, h;
	string place;
public:
	Picture() : w(5), h(7), place("모름") {}
	Picture(int a, int b, string p) : w(a), h(b), place(p) {}
	int getWidth() { return w; }
	int getHeight() { return h; }
	string getPlace() { return place; }
};

int main() {
	Picture pic;	// 5x7 크기, 촬영 장소 "모름"
	Picture mt(10, 14, "한라산");	// 10x14 크기, 촬영 장소 "한라산"
	cout << pic.getWidth() << "x" << pic.getHeight() << " " << pic.getPlace() << endl;
	cout << mt.getWidth() << "x" << pic.getHeight() << " " << mt.getPlace() << endl;
}

/*
5x7 모름
10x14 한라산
*/