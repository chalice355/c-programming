// **********************************************
// 제 목 : 입력받은 수에 2를 더하는 프로그램
// 날 짜 : 2026 년 5 월 10 일
// 작성자 : 2001218
// **********************************************

#include<iostream>
using namespace std;
void add2(int& value);	// '&' 연산자 삽입
int main(void)
{
	int number;
	cout << "정수를 입력하세요 : ";
	cin >> number;
	add2(number);
	cout << "2만큼 증가한 값 :" << number << endl;
	return 0;
}
void add2(int& value)	// '&' 연산자 삽입, main함수의 number에 2를 더하는 함수
{
	value += 2;		// number의 별명으로, 2를 더해준다
}
