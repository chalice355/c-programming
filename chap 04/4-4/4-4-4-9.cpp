// **********************************************
// 제  목 : 7주차 실습과제 4-4-4-9
// 날  짜 : 2026년 4월 17일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
public:
	Book() { title = ""; price = 0; }
	void set(string title, int price) { this->title = title; this->price = price; }
	string getTitle() { return title; }
	int getPrice() { return price; }
};

class Library {
	string name;	// 도서관 이름
	Book* p;	// 동적 할당받을 Book [] 배열에 대한 포인터
	int size;	// 동적 할당받은 Book [] 배열의 크기
	int next = 0;	// p[] 배열에 다음 삽입될 위치
public:
	Library(string name, int size) {	// 생성자
		this->name = name;
		this->size = size;
		p = new Book[size];
	}
	~Library() { delete[] p; }	// 소멸자
	void add(string title, int price) {		// 책 한권 입고하여 정보 저장
		p[next].set(title, price);	// 책 정보 저장
		next++;
	}
	void show() {	// 도서관에 들어있는 모든 책 출력
		cout << name << "에 입고된 책은 다음 " << next << "권입니다." << endl;
		for (int i = 0; i < next; i++) {
			cout << "[" << p[i].getTitle() << "]" << "\t";
		}
		cout << endl;
	}
	Book* mostExpensive() {	// 가장 비싼 Book 객체에 대한 포인터 리턴. 책이 없으면 NULL 리턴
		if (next == 0) return nullptr;
		Book* most = &p[0];
		for (int i = 1; i < next; i++) {
			if (p[i].getPrice() < most->getPrice())
				most = &p[i];
		}
		return most;
	}
};

int main() {
	Library* lib = new Library("한국도서관", 10);
	lib->add("명품 C++", 30000);
	lib->add("라즈베리파이", 34000);
	lib->add("HTML5", 33000);
	lib->show();
	Book* b = lib->mostExpensive();
	cout << "가장 비싼 책:" << b->getTitle() << "," << b->getPrice() << endl;
}

/*
한국도서관에 입고된 책은 다음 3권입니다.
[명품 C++]	[라즈베리파이]	[HTML5]
가장 비싼 책:라즈베리파이,34000
*/