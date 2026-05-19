#include <iostream>
#include <cstring>
using namespace std;

class Rectangle {
    int width, height;
public:
    Rectangle(int w = 1, int h = 1) : width(w), height(h) {}
    void show() {
        cout << "사각형 폭은 " << width << " 높이는 " << height << endl;
    }
};

int main() {
    Rectangle rect0;
    rect0.show();
    Rectangle rect1(10);
    rect1.show();
    Rectangle rect2(10, 20);
    rect2.show();
    return 0;
}

/*
사각형 폭은 1 높이는 1
사각형 폭은 10 높이는 1
사각형 폭은 10 높이는 20
*/