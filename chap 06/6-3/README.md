# 실습과제 1
## static 멤버변수는 클래스 선언부에 선언하고 외부에서 다시 선언하는 이유를 설명하라.
* 클래스 선언부에서 선언하는 것은 컴파일러에게 변수의 정보만을 주며 실제 메모리를 사용하지 않기 때문에 값을 넣을 수 없다.
* 외부에서 다시 선언하여 정의하는 것은 실제 메모리가 할당되어 메모리에 값을 넣어줄 수 있기 때문이다.
* static 멤버 변수는 모든 객체가 공유해야하므로, 전체 영역에서 사용할 수 있도록 전역 범위에서 정의 및 초기화 해야하기 때문이다.

## static 멤버함수의 클래스 구현부에 static 키워드를 붙이면 안되는 이유를 설명하라.
* 클래스 구현부에서의 static은 클래스 내부의 범위에서 사용이 가능한 함수로 선언하는 것이다.
* 클래스 외부의 static은 소스파일 내 전체범위에서 사용이 가능하도록 선언하는 것이다.

# 실습과제 2
```
class MyMath {
public:
	static int GetMax(int arr[], int size) {
		int max = arr[0];
		for (int i = 1; i < size; i++) {
			if (arr[i] > max)	max = arr[i];
		}
		return max;
	}
```
* 최대값을 찾는 정적 함수 선언 및 정의
* 배열의 0번째 값을 max에 저장한 뒤, 반복문을 통해 배열을 순회하며 저장된 max값과 비교한다.
* 저장되어있는 max값보다 큰 값을 i번째에서 찾은 경우, i번째의 값을 max에 저장하여 갱신
* 최종적으로 찾은 max값 리턴

```
	static int GetMin(int arr[], int size) {
		int min = arr[0];
		for (int i = 1; i < size; i++) {
			if (arr[i] < min)	min = arr[i];
		}
		return min;
	}
};
```
* 최소값을 찾는 정적 함수 선언 및 정의
* 배열의 0번째 값을 min에 저장한 뒤, 반복문을 통해 배열을 순회하며 저장된 min값과 비교
* 저장되어있는 min값보다 작은 값을 i번째에서 찾은 경우, i번째의 값을 min에 저장하여 갱신
* 최종적으로 찾은 min값 리턴

```
int main() {
	int x[5] = { 20, 30, -5, 2, -30 };
	cout << "최대값은 :" << MyMath::GetMax(x, 5) << endl;
	cout << "최소값은 :" << MyMath::GetMin(x, 5) << endl;
	return 0;
}
```
* 비교할 원소들이 저장된 배열 x 정의
* 배열 x의 원소 5개를 반복문을 통해 비교하여 리턴받은 최대값/최소값을 출력

# 실습과제 3
```
class Triangle {
	static int NumOfTriangles;
public:
	Triangle(int n = 0);
	~Triangle() { NumOfTriangles--; }
	static int getNumOfTriangle() { return NumOfTriangles; }
};
```
* 삼각형의 개수를 구하는 클래스
* 

```
Triangle::Triangle(int n) {
	NumOfTriangles = n;
	NumOfTriangles++;
}
int Triangle::NumOfTriangles = 0;

int main() {
	Triangle* tri1 = new Triangle[5];
	cout << "생성된 삼각형의 개수 :" << Triangle::getNumOfTriangle()
		<< endl;
	delete[] tri1;
	Triangle tri2[15];
	cout << "생성된 삼각형의 개수 :" << Triangle::getNumOfTriangle()
		<< endl;
	return 0;
}
```

# 실습과제 4


