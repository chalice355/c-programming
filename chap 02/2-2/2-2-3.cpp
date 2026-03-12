// **********************************************
// 제  목 : 1주차 실습과제 1-1
// 날  짜 : 2026년 3월 6일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
using namespace std;

int main() {
	char number[8];
	cout << "학번을 입력하세요 >> ";
	cin.getline(number, sizeof(number), '\n');

	char name[10];
	cout << "이름을 입력하세요 >> ";
	cin.getline(name, sizeof(name), '\n');

	char address[100];
	cout << "주소를 입력하세요 >> ";
	cin.getline(address, sizeof(address), '\n');

	cout << "1.학번:" << number << '\n';
	cout << "2.이름:" << name << '\n';
	cout << "3.주소:" << address << '\n';
}