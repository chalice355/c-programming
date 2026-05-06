#include <iostream>
#include <cstring>
using namespace std;

string GetLatterString(string s1, string s2);

int main() {
	string s1("hello");
	string s2("world");
	string res;
	res = GetLatterString(s1, s2);
	cout << "사전에서 뒤에 나오는 문자열은 " << res << "입니다." << endl;
}

string GetLatterString(string a1, string a2) {
	int cmp = a1.compare(a2);
	if (cmp < 0)	return a2;
	else if(cmp > 0)	return a1;
}