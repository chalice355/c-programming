#include <iostream>
using namespace std;

int main() {
	cout << "입력할 실수의 개수를 입력하세요:";
	int n;
	cin >> n;
	if (n <= 0) return -1;
	double* p = new double[n];
	if (!p) {
		cout << "메모리를 할당할 수 없습니다.";
		return -1;
	}
	cout << n << "개의 실수를 입력 하시오." << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "번째 실수: ";
		cin >> p[i];
	}
	double max = 0;
	for (int i = 0; i < n; i++)
		if (max < p[i])	max = p[i];
	cout << "최대값은 " << max << endl;
	delete[] p;
}
