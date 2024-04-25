// 8_완벽한전달활용
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};
int main()
{
	std::vector<Point> v;
	
	// vector에 요소 넣기. 
	// => 복습할때 아래 각각의 방법에 대해서 화면 출력결과를 생각해 보세요

	// 1. 객체를 생성한 후에 vector에 넣기
//	Point pt(1, 2);
//	v.push_back(pt);

	// 2. 임시객체 형태로 넣기
	// => 임시객체이므로 아래 한줄이 끝날때 파괴
//	v.push_back( Point{1,2} );

	// 3. 객체를 생성해서 전달하지 말고
	//    객체를 생성하기 위한 생성자 인자를 전달하자.
	v.emplace_back( 1, 2);
			// => 이 함수가 내부적으로 new Point(1,2) 로 생성해서 보관

	// main			emplace_back			Point(int a, int b)
	// 1, 2 ========> 받아서 생성자로 전달 ==========>

	std::cout << "-----" << std::endl;
}
// cppreference.com 에서 vector 검색. 멤버 함수에서 emplace_back

