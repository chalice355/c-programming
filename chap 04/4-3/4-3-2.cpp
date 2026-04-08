#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};
Circle::Circle() {
	radius = 1; cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int r) {
	radius = r; cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
}

int main() {
	int radius;
	while (true) {
		cout << "반지름 입력(음수이면 종료)>> ";
		cin >> radius;
		if (radius < 0) break; 
			Circle* p = new Circle(radius);
		cout << "원의 면적:" << p->getArea() << endl;
	}
	return 0;
}

/*
main 함수의 문제점 :

delete[]를 하지 않아 메모리 반환이 실행되지 않았다. 따라서 메모리 누수로 이어지게 되고, 메모리 낭비와 메모리 부족의 원인이 된다.
이 방식의 메모리 누수는 포인터가 가리키는 주소가 덮어씌워져, 이전에 가리키던 주소는 살아있지만, 지금은 가리키지 않아 더이상 건드릴 수 없게 된다.


해결 방법 : 

delete [] p;를 return 0;의 앞에 추가하여 메모리의 반환을 실행할 수 있도록 한다.
*/