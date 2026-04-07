// 제  목 : 6주차 실습과제 4-2-5
// 날  짜 : 2026년 4월 7일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
using namespace std;

int main() {
	cout << "저장할 문자열의 크기를 입력하세요: ";
	int n;
	cin >> n;
	cin.ignore();
	if (n <= 0) return -1;
	char* p = new char[n + 1];
	if (!p) {
		cout << "메모리를 할당할 수 없습니다.";
		return -1;
	}

	cout << "문자열을 입력 하시오: " << endl;
	cin.getline(p, n + 1, '\n');
	cout << "입력한 문자열은 ";
	for (int i = 0; p[i] != '\0'; i++)
		cout << p[i];
	cout << "입니다." << endl;
	delete[] p;
}

/*
저장할 문자열의 크기를 입력하세요: 11
문자열을 입력 하시오:
I am a boy.
입력한 문자열은 I am a boy.입니다.
*/
