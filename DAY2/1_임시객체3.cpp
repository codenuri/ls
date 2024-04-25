// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자 - 81 page
void draw_line(const Point& from, const Point& to) {}
void init(Point& pt) { pt.x = 0; pt.y = 0; }

int main()
{
	// 1, 1 ~ 3,3 의 선을 그리고 싶다.
	// #1. 객체 2개를 생성해서 전달
	Point p1{1, 1};
	Point p2{3, 3};
	draw_line(p1, p2);	

	// #2. 임시객체로 전달
	// => 함수 인자로만 사용할 객체라면 "임시객체" 형태로 전달하는것이 좋다.
	draw_line(Point{1,1}, Point{3,3});

	// #3. 임시객체와 함수 인자
	init(p1);
	init(Point{1,1}); // 즉시 파괴될 객체의 상태 변경은 논리적으로 맞지 않습니다.
						// 그래서, 임시객체는 "non-const reference"로 
						// 받을수 없습니다.
						// error.
						// 자세한 것은 "임시객체2.cpp" 참고


	std::cout << "-----" << std::endl;
}





