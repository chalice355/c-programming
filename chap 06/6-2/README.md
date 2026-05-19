# 실습과제 1
* 컴파일러가 선언을 먼저 읽기 때문에 선언부에서 정의해야한다.
* 만일, 정의를 main보다 나중에 할 경우, 위에서 아래로 읽는 컴파일러 특성상, 선언 -> main -> 정의 순서로 읽히므로 디폴트값을 모르기에 오류가 생기게 된다.

# 실습과제 2
```
class Rectangle {
    int width, height;
public:
    Rectangle(int w = 1, int h = 1) : width(w), height(h) {}
    void show() {
        cout << "사각형 폭은 " << width << " 높이는 " << height << endl;
    }
};
```
* 삼각형 클래스 선언
* 밑변과 높이의 값을 1로 디폴트 정의

```
int main() {
    Rectangle rect0;
    rect0.show();
    Rectangle rect1(10);
    rect1.show();
    Rectangle rect2(10, 20);
    rect2.show();
    return 0;
}
```
* 디폴트로 정의된 삼각형 출력
* 밑변을 10으로 초기화, 높이를 디폴트로 정의된 삼각형 출력
* 밑변과 높이를 10과 20으로 초기화 한 삼각형 출력
<img src="./sbj 6-2-2.png">

# 실습과제 3
```
class Point3D {
	int a, b, c;
public:
	Point3D(int x = 0, int y = 0, int z = 0) : a(x), b(y), c(z) {}
	void show() {
		cout << "3차원 점의 좌표는 (" << a << ", " << b << ", " << c << ")" << endl;
	}
};
```
* 3차원 좌표 클래스 선언
* x, y, z의 좌표를 디폴트로 (0, 0, 0)로 정의

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
* 각 좌표를 직접 초기화하는 예제 출력
<img src="./sbj 6-2-3.png">
