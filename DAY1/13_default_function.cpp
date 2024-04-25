// 13_default_function - 41 page
#include <type_traits>
#include <iostream>
// godbolt.org 에 접속해 보세요
// => 다양한 언어의 기계어 코드를 볼수 있는 사이트

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// 아무일도 하지 않은 인자가 없는 생성자를 만드는 방법
	// #1. 사용자가 만들기
	// => 구현을 사용자가 만든것
	// => 컴파일러는 아무일도 하지 않는다는 것을 알지 못한다.
//	Point() {}		// bad

	// #2. 컴파일러에게 요청하기
	// => 구현을 컴파일러가 만든것
	// => 컴파일러는 어떤일을 하는지 정확히 알고 있다. 
	// => 최적화 잘되고, 다양하게 활용 가능.
	Point() = default;	// good
};

int main()
{
	Point p1;
	Point p2(1, 2);
}




