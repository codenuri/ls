// - 55 page
#include <iostream>

// C++11 부터 멤버 데이타를 직접 초기화 가능(field initialization)
// => 원리를 알아 두세요
// => 아래 코드 결과 예측해보세요
int x = 10;

class Test
{
	int value1 = 0;	
	int value2 = ++x; // 절대 이렇게 하지 마세요
public:	
	Test() {}
	Test(int n) : value2(n) {}
};
// 위 코드를 컴파일러는 아래 코드로 변경합니다.
/*
class Test
{
	int value1; // = 0;
	int value2; // = ++x;
public:	
	// 위 필드 초기값을 보고 컴파일러가 아래 처럼 생성자를 변경한것
	Test()      : value1(0), value2(++x) {}
	Test(int n) : value1(0), value2(n) {}
};
*/
int main()
{
	Test t1;
	Test t2(5);

	std::cout << x << std::endl; // 11
}