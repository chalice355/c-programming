// **********************************************
// 제 목 : 깊은 복사 생성자를 이용하는 프로그램
// 날 짜 : 2026 년 5 월 14 일
// 작성자 : 2001218
// **********************************************

#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
    int id;
public:
    Person(int id, const string& name);
    ~Person();
    void changeName(const string& name);
    void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, const string& name) {
    this->id = id;
    this->name = name;
}

Person::~Person() {
}

void Person::changeName(const string& name) {
    this->name = name;
}

int main() {
    Person father(1, "Kitae");
    Person daughter(father);
    cout << "daughter 객체 생성 직후 ----" << endl;
    father.show();
    daughter.show();
    daughter.changeName("Grace");
    cout << "daughter 이름을 Grace로 변경한 후 ----" << endl;
    father.show();
    daughter.show();
    return 0;
}