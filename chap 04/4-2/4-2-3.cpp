// **********************************************
// 제  목 : 5주차 실습과제 4-2-3
// 날  짜 : 2026년 4월 7일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
using namespace std;

int main() {
	cout << "입력할 정수의 개수를 입력하세요:";
	int n;
	cin >> n;
	if (n <= 0) return -1;
	int* p = new int[n];
	if (!p) {
		cout << "메모리를 할당할 수 없습니다.";
		return -1;
	}
	cout << n << "개의 정수를 입력 하시오." << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "번째 정수: ";
		cin >> p[i];
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += p[i];
	cout << "평균 = " << sum / n << endl;
	delete[] p;
}
