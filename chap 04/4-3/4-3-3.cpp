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
	Circle* pArray = new Circle[3];
	for (int i = 0; i < 3; i++) {
		cout << pArray->getArea() << '\n';
		pArray++;
	}
	delete[] pArray;
	return 0;
}

/*
main 함수의 문제점 : 

포인터 주소는 default로 배열의 첫번째 원소의 주소를 가리킨다.
하지만, ++연산자를 통해 원소를 이동하는 경우, 포인터 주소를 직접 이동시키는 방식이므로, 원래 위치(원소 첫번째 주소)로 되돌리지 않고 delete[]를 하게 되면, 정상적으로 반환이 되지 않는다.


해결 방법 : 

Circle* p = pArray;를 추가하여 간접적으로 이동해야한다.
이 방식을 사용하면, p를 통해 간접적으로 이동시키기 때문에 pArray는 그대로 배열의 원소 첫번째 주소를 가리킨다.
이 때에, pArray를 delete[]하게 되면, 정상적으로 메모리를 반환할 수 있게 된다.
*/