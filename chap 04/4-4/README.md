# 실습과제 1
## string객체는 문자열 입력 받을 때 몇 자를 입력할지 물어 보지않고 알아서 크기를 자동 조절한다.동작 원리를 검색해보고 설명하라->앞으로,C++에서는 char배열을 사용하지 말고 string클래스를 사용할 것
* string 클래스는 내부적으로 힙 메모리를 동적으로 관리한다. char 배열처럼 크기를 미리 고정하지 않고, 문자열 길이에 따라 자동으로 메모리를 늘리거나 줄인다.
* 동작 원리로는, 문자열을 입력받을 때 현재 할당된 공간이 부족하면 더 큰 메모리를 새로 할당받고, 기존 내용을 복사한 뒤 이전 메모리를 해제한다.

## 문자열을 입력할 때 마지막에 입력하는 엔터키와 getline함수의 마지막 인자에 전달하는 구분문자와 차이를 설명하라
* 엔터키(\n)는 사용자가 키보드로 입력하는 '물리적'인 입력 신호이고, getline()의 구분문자는 프로그래머가 저장하는 '논리적'인 구분 기준이다.
* 엔터키의 처리 방식은 입력 버퍼에 \n으로 저장되고, getline()의 처리 방식은 해당 문자(기본값:\n)를 만나면 입력 종료한다.

# 실습과제 2
```
int main() {
	string result = "";
	string input;
	int count = 1;
```
* result 선언 및 빈 문자열로 초기화
* 입력받은 문자열을 저장할 input 선언
* 앞에 <n>형태로 붙일 순서 count를 1로 선언 및 초기화
```
	while (true) {
		cout << "문자열 입력 : ";
		getline(cin, input, '\n');
		if (input == "quit") break;
```
* while 반복문으로 문자열 입력을 반복해서 입력받아 input에 저장
* quit으로 반복문 탈출
```
		result = result + "<" + to_string(count) + ">" + input;
		cout << "이어진 문자열: " << result << endl;
		count++;
	}
	return 0;
}
```
* count로 순서 , input에 저장된 문자열을 모두 result에 누적하여 이어붙인다.
* 누적되는 result를 출력
* count + 1

# 실습과제 3
```
int main() {
	string str;
	int count = 0;
```
* 입력받은 문장을 저장할 str 선언
* a의 개수를 셀 count 선언 및 0으로 초기화
```
	cout << "문자열 입력 : ";
	getline(cin, str, '\n');
```
* 문자열을 입력받고, \n으로 문자열 종단점 구분
```
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == 'a')
			count++;
	}
```
* 문자열 길이만큼 a를 찾는 과정을 반복하고, 발견 시, count + 1
```
	cout << "문자 a는 " << count << "개 있습니다." << endl;
	return 0;
}
```
* 문자열에서 찾은 a의 개수인 count를 출력

# 실습과제 4
## 실습문제 2
```
int main() {
	int thing;
	cout << "구입할 물품의 개수>>";
	cin >> thing;
	int* p = new int[thing];
```
* 물품의 개수를 입력받아 저장할 정수변수 thing 선언
* 문자열 출력 후 키보드로부터 입력받은 정수를 thing에 저장
* thing의 크기만큼 동적 배열 p를 할당
```
	cout << "물품" << thing << "개의 가격 입력>>";
	for (int i = 0; i < thing; i++) {
		cin >> p[i];
	}
```
* thing의 크기만큼 반복문을 진행하며 물품의 가격을 각 배열에 순서대로 저장
```
	int minPrice = p[0];
	int maxPrice = p[0];
	for (int i = 1; i < thing; i++) {
		if (p[i] < minPrice) minPrice = p[i];
		if (p[i] > maxPrice) maxPrice = p[i];
	}
```
* 최소값 minPrice와 최대값 maxPrice를 선언하고, 동시에 배열의 첫번째 가격으로 초기화
* thing의 크기만큼 반복문을 반복하며 minPrice보다 작은 값을 찾으면 minPrice 갱신
* thing의 크기만큼 반복문을 반복하며 maxPrice보다 큰 값을 찾으면 maxPrice 갱신
```
	cout << "제일 싼 가격은 " << minPrice << endl;
	cout << "제일 비싼 가격은 " << maxPrice << endl;
	delete[] p;
	return 0;
}
```
* minPrice와 maxPrice를 출력
* p의 동적 할당 해제

## 실습문제 4
```
int main() {
	string str, result = "";
	cout << "텍스트 입력(한글 안 됨)>>";
	getline(cin, str);
```
* 입력받은 문자열을 저장할 str과 새로운 문자열을 저장할 result를 선언 후, 빈 문자열로 초기화
* 문자열을 입력받아 str에 저장
```
	for (int i = 0; i < str.length(); i++) {
		char ch = str.at(i);
		if (isalpha(ch) || ch == ' ') {
			result += ch;
		}
	}
```
* 문자열의 길이만큼 반복문을 수행하며 i째 문자가 알파벳 또는 공백일 경우. result에 추가
```
	cout << result << endl;
	return 0;
}
```
* result에 저장된 알파벳과 공백 문자의 새로운 문자열 출력

## 실습문제 9
```
class Book {
	string title;
	int price;
```
* 책 제목과 책의 가격 선언
```
public:
	Book() { title = ""; price = 0; }
	void set(string title, int price) { this->title = title; this->price = price; }
	string getTitle() { return title; }
	int getPrice() { return price; }
};
```
* 기본 생성자 Book()을 제목 빈 문자열, 가격 0으로 초기화
* 제목과 가격 설정(매개변수와 멤버변수명이 같아 this-> 사용)
* 제목을 반환하는 getTitle()선언
* 가격을 반환하는 getPrice()선언
```
class Library {
	string name;	// 도서관 이름
	Book* p;	// 동적 할당받을 Book [] 배열에 대한 포인터
	int size;	// 동적 할당받은 Book [] 배열의 크기
	int next = 0;	// p[] 배열에 다음 삽입될 위치
```
* 도서관 이름을 저장할 name 선언
* 동적 할당받을 Book 배열 포인터
* 동적 할당받은 Book 배열의 크기
* p[] 배열 다음에 삽입될 위치(현재 저장된 책의 수)
```
public:
	Library(string name, int size) {	// 생성자
		this->name = name;
		this->size = size;
		p = new Book[size];
	}
```
* 생성자 Library는 도서관 이름과 최대 책 수를 받음
* size만큼 Book 배열에 동적 할당
```
	~Library() { delete[] p; }	// 소멸자
	void add(string title, int price) {		// 책 한권 입고하여 정보 저장
		p[next].set(title, price);	// 책 정보 저장
		next++;
	}
```
* 소멸자는 동적 할당 메모리를 해제
* add는 책의 이름과 가격을 배열에 순서대로 저장
* 최대 책 수를 보여주는 next + 1
```
	void show() {	// 도서관에 들어있는 모든 책 출력
		cout << name << "에 입고된 책은 다음 " << next << "권입니다." << endl;
		for (int i = 0; i < next; i++) {
			cout << "[" << p[i].getTitle() << "]" << "\t";
		}
		cout << endl;
	}
```
* 반복문을 수행하며 배열에 저장된 책의 제목을 하나씩 출력
* 줄띄움
```
	Book* mostExpensive() {	// 가장 비싼 Book 객체에 대한 포인터 리턴. 책이 없으면 NULL 리턴
		if (next == 0) return nullptr;
```
* 저장된 가장 비싼 책의 포인터 반환
* 없을 경우, NULL 반환
```
		Book* most = &p[0];
		for (int i = 1; i < next; i++) {
			if (p[i].getPrice() < most->getPrice())
				most = &p[i];
		}
		return most;
	}
};
```
* 가장 비싼 가격을 저장하는 most 선언 및 첫 번째 책을 기준값으로 초기화
* 반복문을 책의 수 만큼 현재 저장된 책의 가격과 비교하여 더 비싼 책 탐색
* 저장된 가격 < 찾은 가격 인 경우, 포인터 갱신
* 최종 선택된 책의 포인터 반환
```
int main() {
	Library* lib = new Library("한국도서관", 10);
	lib->add("명품 C++", 30000);
	lib->add("라즈베리파이", 34000);
	lib->add("HTML5", 33000);
	lib->show();
	Book* b = lib->mostExpensive();
	cout << "가장 비싼 책:" << b->getTitle() << "," << b->getPrice() << endl;
}
```
* 최대 10권을 저장할 수 있는 도서관 객체 동적 생성
* 책 3권을 순서대로 입고(배열에 저장)
* 입고 된 책 목록(배열에 저장된 원소들) 출력
* 가장 비싼 책의 포인터를 받음
* 가장 비싼 책의 제목과 가격을 출력
