#include <iostream>
using namespace std;

class Coffee {
private:
	int c, s, m, w;
public:
	Coffee() : c(10), s(0), m(0), w(0) {}
	Coffee(int a, int b, int c, int d) : c(a), s(b), m(c), w(d) {}
	void show() {
		cout << "coffee ";
		for (int i = 0; i < c; i++)	cout << "*";
		cout << endl;
		cout << "sugar ";
		for (int i = 0; i < s; i++)	cout << "*";
		cout << endl;
		cout << "milk ";
		for (int i = 0; i < m; i++)	cout << "*";
		cout << endl;
		cout << "water ";
		for (int i = 0; i < w; i++)	cout << "*";
		cout << endl;
	}
};

int main() {
	Coffee espresso;	// 커피 10, 설탕 0, 우유 0, 물 0
	Coffee americano(5, 0, 0, 10);	// 커피 5, 설탕 0, 우유 0, 물 10
	Coffee cappucchino(5, 1, 5, 2);	// 커피 5, 설탕 1, 우유 5, 물 2
	Coffee mySweet(3, 7, 5, 5);	// 커피 3, 설탕 7, 우유 5, 물 5

	espresso.show();
	cout << endl;
	mySweet.show();
}

/*
coffee **********
sugar
milk
water

coffee ***
sugar *******
milk *****
water *****
*/