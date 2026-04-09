// **********************************************
// 제  목 : 5주차 실습과제 4-3-5
// 날  짜 : 2026년 4월 9일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	~Circle() { }
	void setRadius(int r) { radius = r; }
	double getVolume() { return (4.0 / 3.0) * 3.14 * radius * radius * radius; }
};
Circle::Circle() {
	radius = 1;
}

int main() {
	cout << "생성하고자 하는 구의 개수: ";
	int n, r;
	cin >> n; // 원의 개수 입력
	Circle* pArray = new Circle[n]; // n 개의 Circle 배열 생성
	for (int i = 0; i < n; i++) {
		cout << "구" << i + 1 << "의 반지름: "; // 도움말 출력
		cin >> r; // 반지름 입력
		pArray[i].setRadius(r);
	}
	Circle* p = pArray;
	for (int i = 0; i < n; i++) {
		cout << "구" << i + 1 << "의 부피 " << p->getVolume() << endl;
		p++;
	}
	delete[] pArray;
	return 0;
}

/*
생성하고자 하는 구의 개수: 3 <엔터>
구1의 반지름: 1 <엔터>
구2의 반지름: 2 <엔터>
구3의 반지름: 3 <엔터>
구1의 부피 4 18
구2의 부피 34 49
구3의 부피 113 04
*/