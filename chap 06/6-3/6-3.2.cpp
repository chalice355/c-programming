#include <iostream>
using namespace std;

class MyMath {
public:
	static int GetMax(int arr[], int size) {
		int max = arr[0];
		for (int i = 1; i < size; i++) {
			if (arr[i] > max)	max = arr[i];
		}
		return max;
	}
	static int GetMin(int arr[], int size) {
		int min = arr[0];
		for (int i = 1; i < size; i++) {
			if (arr[i] < min)	min = arr[i];
		}
		return min;
	}
};

int main() {
	int x[5] = { 20, 30, -5, 2, -30 };
	cout << "최대값은 :" << MyMath::GetMax(x, 5) << endl;
	cout << "최소값은 :" << MyMath::GetMin(x, 5) << endl;
	return 0;
}
/*
최대값은 : 30
최소값은 : -30
*/