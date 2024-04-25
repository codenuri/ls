#include <iostream>
// 6_위임생성자- 24page
class Point // : public Base
{
public:
	int x, y;
public:
	// C++11 부터 하나의 생성자에서 다른 생성자 호출가능합니다.
	// => 위임 생성자라는 문법
	// => 초기화 리스트 문법으로 호출.
	Point() : Point(0,0) 		
	{
//		Point(0, 0); // 생성자에서 다른 생성자 호출??
					 // => 이 코드는 다른 생성자 호출이 아니라.
					 // => 임시객체를 만드는 표기법입니다.
	}
	Point(int a, int b) : x(a), y(b) // :Base()
	{
		// 복잡한 초기화 코드
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

