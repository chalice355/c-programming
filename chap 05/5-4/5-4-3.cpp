// **********************************************
// 제 목 : 깊은 복사 생성자를 이용하는 프로그램2
// 날 짜 : 2026 년 5 월 14 일
// 작성자 : 2001218
// **********************************************

#include <iostream>
#include <string>
using namespace std;

class MyStack {
	int* p;
	int size;
	int tos;
public:
	MyStack();
	MyStack(int size);
	MyStack(const MyStack& src);
	~MyStack();
	bool push(int n);
	bool pop(int& n);
};

MyStack::MyStack() : MyStack(10) {}
MyStack::MyStack(int size) : size(size), tos(0) {
	p = new int[size];
}
MyStack::MyStack(const MyStack& src) {
	this->size = src.size;
	this->tos = src.tos;
	this->p = new int[src.size];
	for (int i = 0; i < src.tos; i++) {
		this->p[i] = src.p[i];
	}
}
MyStack::~MyStack() {
	delete[] p;
}
bool MyStack::push(int n) {
	if (tos == size) return false;
	p[tos++] = n;
	return true;
}
bool MyStack::pop(int& n) {
	if (tos == 0)	return false;
	n = p[--tos];
	return true;
}

int main() {
	MyStack a(10);
	a.push(10); a.push(20);
	MyStack b = a;
	b.push(30);
	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;
}

/*
스택 a에서 팝한 값 20
스택 b에서 팝한 값 30
*/