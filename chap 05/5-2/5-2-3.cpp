// **********************************************
// 제 목 : 입력받은 수를 swap하는 프로그램
// 날 짜 : 2026 년 5 월 10 일
// 작성자 : 2001218
// **********************************************

#include <iostream>
using namespace std;
void swap(int& a, int& b);
int main() {
	int x = 0, y = 0;
	cout << "정수 x를 입력하시오: ";
	cin >> x;
	cout << "정수 y를 입력하시오: ";
	cin >> y;

	cout << "swap함수 호출 전 x=" << x << ", y=" << y << endl;
	swap(x, y);
	cout << "swap함수 호출 후 x=" << x << ", y=" << y << endl;
}
void swap(int& a, int& b) { 
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
