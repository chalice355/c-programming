#include <iostream>
using namespace std;

class Storage {
private:
	float sum = 0;

public:
	Storage();
	Storage(int z);
	float put(int x);
	float getAvg();
	double data[10] = { 0,0,0,0,0,0,0,0,0,0 };
	void dump();
};

float Storage::put(int x) {
	for (int i = 0; i < 10; i++) {
		data[i] = x;
	}
}

float Storage::getAvg() {
	for (int i = 0; i < 10; i++) {
		sum += sum;
		return (sum / i);
	}
}

void Storage::dump() { 
	for (int i = 0; i < 10; i++) {
		cout << data[i] << " ";
	}
}

int main() {
	Storage a;
	a.put(36.7);
	a.put(36.9);
	a.put(36.4);
	a.dump();
	cout << "평균 체온은 " << a.getAvg() << "입니다." << endl;
}
