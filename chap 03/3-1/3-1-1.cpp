// **********************************************
// 제  목 : 1주차 실습과제 1-1
// 날  짜 : 2026년 3월 6일
// 작성자 : 2001218 임성배
// **********************************************

#include <iostream>
using namespace std;

class Empty {};                         

class OnlyFunc {
    void hello() {}                      
};

class WithInt {
    int a;                               
};

class WithIntChar {
    int a;                               
    char b;
};

class WithVirtual {
    virtual void hello() {}
    int a;
};

int main() {
    cout << "Empty          : " << sizeof(Empty) << " bytes" << endl;
    cout << "OnlyFunc       : " << sizeof(OnlyFunc) << " bytes" << endl;
    cout << "WithInt        : " << sizeof(WithInt) << " bytes" << endl;
    cout << "WithIntChar    : " << sizeof(WithIntChar) << " bytes" << endl;
    cout << "WithVirtual    : " << sizeof(WithVirtual) << " bytes" << endl;
}
