#include <iostream>
using namespace std;

int main() {
	cout << "저장할 문자열의 크기를 입력하세요:";
	int n;
	cin >> n;
	if (n <= 0) return -1;
	char* p = new char[n];
	if (!p) {
		cout << "메모리를 할당할 수 없습니다.";
		return -1;
	}
	cout << "문자열을 입력 하시오." << endl;
	cin >> p;
	cout << "입력한 문자열은 ";
	for (int i = 0; i < n; i++) {
		cout << p[i];
	}
	cout << "입니다." << endl;
	delete[] p;
}

/*
저장할 문자열의 크기를 입력하세요: 11<엔터>
문자열을 입력하시오: I am a boy.<엔터>
입력한 문자열은 I am a boy.입니다.
*/
