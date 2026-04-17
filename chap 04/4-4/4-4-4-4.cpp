// **********************************************
// 제  목 : 7주차 실습과제 4-4-4-4
// 날  짜 : 2026년 4월 17일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str, result = "";
	cout << "텍스트 입력(한글 안 됨)>>";
	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		char ch = str.at(i);
		if (isalpha(ch) || ch == ' ') {
			result += ch;
		}
	}
	cout << result << endl;
	return 0;
}