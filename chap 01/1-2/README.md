# 소스코드 설명

'''
#include <iostream>
'''
* 밑에 작성한 cout 등을 사용하기 위해 라이브러리 객체 선언을 포함한 헤더파일인 iostream을 include한다
'''
int main()
'''
* 메인 함수의 시작
'''
std::cout << "Hello, World!";
'''
* 'Hello, World' 문장 출력, std::cout은 화면에 출력해주는 객체, <<는 삽입 연산자
'''
std::cout << std::endl;
'''
* 화면에 줄바꿈문자(std::endl)를 출력
'''
return 0;
'''
* 0을 반환하고 메인함수 정상 종료

# 실행결과 
<img src="./result_image">
