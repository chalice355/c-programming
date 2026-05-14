// **********************************************
// 제 목 : 깊은 복사 생성자를 이용하는 프로그램3
// 날 짜 : 2026 년 5 월 14 일
// 작성자 : 2001218
// **********************************************

#include <iostream>
#include <string>
using namespace std;

class MyPipe {
	int size;
	int putIndex = 0;
	int getIndex = 0;
	int* p;
public:
	MyPipe();
	MyPipe(int size);
	MyPipe(const MyPipe& src);
	~MyPipe();
	bool put(int n);
	bool get(int& n);
	int getSize() { return putIndex; }
};

MyPipe::MyPipe() : MyPipe(10) {}
MyPipe::MyPipe(int size) : size(size), putIndex(0), getIndex(0) {
	p = new int[size];
}
MyPipe::MyPipe(const MyPipe& src) {
	this->size = src.size;
	this->putIndex = src.putIndex;
	this->getIndex = src.getIndex;
	this->p = new int[src.size];
	for (int i = 0; i < src.size; i++) {
		this->p[i] = src.p[i];
	}
}
MyPipe::~MyPipe() {
	delete[] p;
}
bool MyPipe::put(int n) {
	if (putIndex == size)	return false;
	p[putIndex++] = n;
	return true;
}
bool MyPipe::get(int& n) {
	if (getIndex == putIndex)	return false;
	n = p[getIndex++];
	return true;
}

int main() {
	MyPipe a(5);
	a.put(10); a.put(20);
	MyPipe b = a;
	b.put(30);
	cout << "파이프 a에 저장된 개수: " << a.getSize() << endl;
	cout << "파이프 b에 저장된 개수: " << a.getSize() << endl;
	int n;
	a.get(n);
	cout << "파이프 a에서 빼온 값 " << n << endl;
	b.get(n);
	cout << "파이프 b에서 빼온 값 " << n << endl;
}

/*
파이프 a에 저장된 개수: 2
파이프 b에 저장된 개수: 3
파이프 a에서 빼온 값 10
파이프 b에서 빼온 값 10
*/