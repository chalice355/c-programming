// **********************************************
// 제  목 : 7주차 실습과제 4-4-3
// 날  짜 : 2026년 4월 17일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int count = 0;

	cout << "문자열 입력 : ";
	getline(cin, str, '\n');

	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == 'a')
			count++;
	}

	cout << "문자 a는 " << count << "개 있습니다." << endl;
	return 0;
}
/*
문자열 입력 : Are your happy? I am so happy.
문자 a는 3개 있습니다.
*/