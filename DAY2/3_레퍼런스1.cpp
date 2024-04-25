// 3_레퍼런스1.cpp - 89 page - 아주 중요!

struct Point
{
	int x, y;

	Point(int a, int b) : x(a), y(b) {}
};
int main()
{
	Point pt(0, 0);

	// 규칙 1. non-const lvalue reference 는 lvalue 가 가리킬수 있다
	Point& r1 = pt;				// ok
	Point& r2 = Point(0, 0);	// error.

	// 규칙 2. const lvalue reference 는 lvalue 와 rvalue를 모두 가리킬수 있다
	const Point& r3 = pt;			// ok
	const Point& r4 = Point(0, 0);	// ok

	// 규칙 3. rvalue reference 는 rvalue 만 가리킬수 있다.(C++11)
	// => C++11 의 move 와 완벽한 전달 기술을 위해 만든 문법
	Point&& r5 = pt;			// error
	Point&& r6 = Point(0, 0);	// ok

}
// 왜 위와같은 규칙이 생겼습니까 ?
// 규칙 1, 규칙 2 : 임시객체3.cpp 참고
// 규칙 3 : move 를 이해 해야 합니다.