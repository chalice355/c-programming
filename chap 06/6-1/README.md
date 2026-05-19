# 실습과제 1
* C언어는 함수의 이름만으로 결정하지만, C++는 함수의 이름과 더불어 매개변수로 결정하는 차이점이 있다.

# 실습과제 2
```
int big(int a, int b) {
	if (a > b)	return a;
	else return b;
}
```
* 정수값 비교 후 큰 쪽을 리턴

```
double big(double a, double b) {
	if (a > b)	return a;
	else return b;
}
```
* 실수 값 비교 후 큰 쪽을 리턴

```
string big(string a, string b) {
	if (a > b)	return a;
	else return b;
}
```
* 문자열 비교(아스키 코드에서 번호 비교) 후 큰 쪽을 리턴

```
int main() {
	int x = big(10, 20);
	cout << "큰 정수값은 " << x << endl;
	double y = big(3.14, 1.05);
	cout << "큰 실수값은 " << y << endl;
	string z = big("hello", "world");
	cout << "사전에서 뒤에 나오는 단어는 " << z << endl;
	return 0;
}
```
* 각각 비교해서 리턴받은 큰 쪽을 출력
<img src="./sbj 6-1-2.png">

# 실습과제 3
```
int big(int a, int b);
double big(double a, double b);
string big(string a, string b);
```
* 정수, 실수, 문자열을 비교할 함수 선언

```
int main() {
    int x = big(10, 20);
    cout << "큰 정수값은 " << x << endl;
    double y = big(3.14, 1.05);
    cout << "큰 실수값은 " << y << endl;
    string z = big("hello", "world");
    cout << "사전에서 뒤에 나오는 단어는 " << z << endl;
    return 0;
}
```
* 아래의 비교 함수들에서 리턴받은 값들을 출력

```
int big(int a, int b) {
    if (a > b) return a;
    else return b;
}
```
* 정수를 비교해서 큰 쪽을 리턴

```
double big(double a, double b) {
    if (a > b) return a;
    else return b;
}
```
* 실수를 비교해서 큰 쪽을 리턴

```
string big(string a, string b) {
    if (a > b) return a;
    else return b;
}
```
* 문자열을 비교(아스키 코드) 후 큰 쪽을 리턴
<img src="./sbj 6-1-3.png">

# 실습과제 4
```
class Point3D {
	int a, b, c;
public:
	Point3D() : Point3D(0, 0, 0) {}
	Point3D(int x) : Point3D(x, 0, 0) {}
	Point3D(int x, int y) : Point3D(x, y, 0) {}
	Point3D(int x, int y, int z) : a(x), b(y), c(z) {}
	void show() {
		cout << "3차원 점의 좌표는 (" << a << ", " << b << ", " << c << ")" << endl;
	}
};
```
* 3차원 지점의 클래스 선언
* 위임 생성자로 (0, 0, 0)으로 초기화
* 생성자 함수 중복으로 x또는 x,y 또는 x,y,z 모두를 직접 초기화

```
int main() {
	Point3D p0;
	p0.show();
	Point3D p1(1);
	p1.show();
	Point3D p2(1, 2);
	p2.show();
	Point3D p3(1, 2, 3);
	p3.show();
	return 0;
}
```
* 각각 디폴트, x를 초기화, x와 y를 초기화, 모두를 초기화 한 값을 출력
<img src="./sbj 6-1-4.png">
