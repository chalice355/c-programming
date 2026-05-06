#include <iostream>
#include <cstring>
using namespace std;
string GetLatterString(string* a1, string* a2);
// 함수 선언 추가
int main() {
	string s1("hello");
	string s2("world");
	string res;
	res = GetLatterString(&s1, &s2); // 함수 호출
	cout << "사전에서 뒤에 나오는 문자열은" << res << "입니다." << endl;
}
// 함수 정의 추가
string GetLatterString(string* a1, string* a2) {
	
}