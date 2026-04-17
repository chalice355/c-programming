// **********************************************
// 제  목 : 7주차 실습과제 4-4-2
// 날  짜 : 2026년 4월 17일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
#include <string>
using namespace std;

int main() {
	string result = "";
	string input;
	int count = 1;

	while (true) {
		cout << "문자열 입력 : ";
		getline(cin, input, '\n');

		if (input == "quit") break;

		result = result + "<" + to_string(count) + ">" + input;
		cout << "이어진 문자열: " << result << endl;
		count++;
	}
	return 0;
}

/*
문자열 입력 : hello
이어진 문자열: <1>hello
문자열 입력 : world
이어진 문자열: <1>hello<2>world
문자열 입력 : C++
이어진 문자열: <1>hello<2>world<3>C++
문자열 입력 : quit
*/