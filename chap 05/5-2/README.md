# 실습과제 1
## 참조에 의한 호출과 주소에 의한 호출의 차이점을 설명하라
* 참조에 의한 호출은 원본변수에 대한 다른 이름(별명)을 설정하고, 주소를 명시적으로 전달하며, 원본변수의 메모리 공간을 공유한다.
* 주소에 의한 호출은 원본변수의 주소값을 새로 할당받은 메모리 공간에 저장하고, 그 주소를 전달한다.

## 참조에 의한 호출의 장점은 무엇인가
* 메모리 공간 할당이 되지 않고 원본변수의 공간을 공유하므로, 컴퓨터 자원의 절약이 가능하다
* 매개변수 할당과 인자값을 매개변수에 복사하는 과정이 필요 없기 때문에 동작 속도가 빠르다

# 실습과제 2
```
#include<iostream>
using namespace std;
void add2(int& value);	// '&' 연산자 삽입
```
* & 연산자를 삽입하여 참조하는 것을 명시한다

```
int main(void)
{
	int number;
	cout << "정수를 입력하세요 : ";
	cin >> number;
	add2(number);
	cout << "2만큼 증가한 값 :" << number << endl;
	return 0;
}
void add2(int& value)	// '&' 연산자 삽입, main함수의 number에 2를 더하는 함수
{
	value += 2;		// number의 별명으로, 2를 더해준다
}
```
* &를 삽입하여 add2함수가 number를 원본으로 하여금 참조하여 2를 더하는 연산을 한다.

# 실습과제 3
```
#include <iostream>
using namespace std;
void swap(int& a, int& b);
```
* swap함수에서 사용할 정수 2개를 원본으로부터 참조하기 위해 &를 삽입한다

```
int main() {
	int x = 0, y = 0;
	cout << "정수 x를 입력하시오: ";
	cin >> x;
	cout << "정수 y를 입력하시오: ";
	cin >> y;
```
* x와 y를 0으로 초기화 후, 키보드로부터 입력받아 저장한다

```
	cout << "swap함수 호출 전 x=" << x << ", y=" << y << endl;
	swap(x, y);
	cout << "swap함수 호출 후 x=" << x << ", y=" << y << endl;
}
```
* swap을 하기 전과 한 후의 값을 출력한다

```
void swap(int& a, int& b) { 
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
```
* main함수에서 x와 y를 각각 a와 b로 참조하여 서로의 값을 바꿔주는 연산을 진행한다

# 실습과제 4
```
#include <iostream>
using namespace std;
void get_parts(double num, int& intg, double& dcml);
```
* 정수부와 실수부로 나눌 get_parts함수 선언

```
int main() {
	double num;
	int intg;
	double dcml;
```
* 입력받은 실수를 저장할 num 선언
* 입력받은 수의 정수부를 저장할 intg 선언
* 입력받은 수의 실수부를 저장할 dcml 선언

```
	cout << "실수를 입력하시오 : ";
	cin >> num;
	get_parts(num, intg, dcml);
```
* 키보드로부터 실수를 입력받아 num에 저장한다
* get_parts함수를 진행하여 연산 진행

```
	cout << "정수부 : " << intg << endl;
	cout << "실수부 : " << dcml << endl;
	return 0;
}
```
* get_parts함수 실행 결과를 출력

```
void get_parts(double num, int& intg, double& dcml) {
	intg = (int)num;
	dcml = num - intg;
}
```
* 입력받아 저장한 num의 자료형을 정수로 변환하여 intg에 저장한다
* 입력받아 저장한 num에서 정수부인 intg를 뺄셈연산하여 남은 실수부를 dcml에 저장한다
