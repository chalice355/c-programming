#include <iostream>
#include <string>
using namespace std;

int big(int a, int b);
double big(double a, double b);
string big(string a, string b);

int main() {
    int x = big(10, 20);
    cout << "큰 정수값은 " << x << endl;
    double y = big(3.14, 1.05);
    cout << "큰 실수값은 " << y << endl;
    string z = big("hello", "world");
    cout << "사전에서 뒤에 나오는 단어는 " << z << endl;
    return 0;
}

int big(int a, int b) {
    if (a > b) return a;
    else return b;
}

double big(double a, double b) {
    if (a > b) return a;
    else return b;
}

string big(string a, string b) {
    if (a > b) return a;
    else return b;
}

/*
사각형 폭은 1 높이는 1
사각형 폭은 10 높이는 1
사각형 폭은 10 높이는 20
*/
