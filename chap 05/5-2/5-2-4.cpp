// **********************************************
// 제 목 : 실수를 입력받아 정수부와 소수부를 구하여 출력하는 프로그램
// 날 짜 : 2026 년 5 월 10 일
// 작성자 : 2001218
// **********************************************

#include <iostream>
using namespace std;
void get_parts(double num, int& intg, double& dcml);

int main() {
	double num;
	int intg;
	double dcml;

	cout << "실수를 입력하시오 : ";
	cin >> num;
	get_parts(num, intg, dcml);

	cout << "정수부 : " << intg << endl;
	cout << "실수부 : " << dcml << endl;
	return 0;
}

void get_parts(double num, int& intg, double& dcml) {
	intg = (int)num;
	dcml = num - intg;
}