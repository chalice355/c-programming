// **********************************************
// 제  목 : 7주차 실습과제 4-4-4-2
// 날  짜 : 2026년 4월 17일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
#include <string>
using namespace std;

int main() {
	int thing;
	cout << "구입할 물품의 개수>>";
	cin >> thing;
	int* p = new int[thing];

	cout << "물품" << thing << "개의 가격 입력>>";
	for (int i = 0; i < thing; i++) {
		cin >> p[i];
	}

	int minPrice = p[0];
	int maxPrice = p[0];
	for (int i = 1; i < thing; i++) {
		if (p[i] < minPrice) minPrice = p[i];
		if (p[i] > maxPrice) maxPrice = p[i];
	}

	cout << "제일 싼 가격은 " << minPrice << endl;
	cout << "제일 비싼 가격은 " << maxPrice << endl;

	delete[] p;
	return 0;
}