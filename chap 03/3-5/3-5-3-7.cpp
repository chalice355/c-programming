#include <iostream>
using namespace std;

class Storage {
private:
	float sum = 0;
	int count = 0;
public:
	double data[10] = {};
	void put(double x) {
		if (count < 10)
			data[count++] = x;
	}
	float getAvg() {
		sum = 0;
		for (int i = 0; i < count; i++)
			sum += data[i];
		return (sum / count);
	}
	void dump() {
		for (int i = 0; i < count; i++) {
			cout << data[i];
			if (i < count - 1) cout << " ";
		}
		cout << endl;
	}
};

int main() {
	Storage a;
	a.put(36.7);
	a.put(36.9);
	a.put(36.4);
	a.dump();
	cout << "평균 체온은 " << a.getAvg() << "입니다." << endl;
}

/*
36.7 36.9 36.4
평균 체온은 36.6667입니다.
*/