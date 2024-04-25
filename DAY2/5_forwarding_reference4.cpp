struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

// 방법 #1. call by value
// 특징 : 복사본 생성
// void foo( Point pt) {}


// 방법 #2. call by const lvalue reference
// => 복사본 생성 안됨.
// => 하지만 받으면서 const 속성 추가됨. 객체 수정할수 없음.
//void foo(const Point& pt) {}

// C++98 에서는 위 2가지 방법만 가능
// C++11 에서는 아래 방법 추가

// 방법 #3. 2개의 foo 함수
// => 복사본 없이, 상수성도 추가하지 않고 그대로 전달 받은것
// void foo(Point& pt)  {}
// void foo(Point&& pt) {}

// 방법 #4. forwarding reference(T&&) 를 사용하면
// => 방법3의 함수를 자동생성할수 있고
// => Point 타입뿐 아니라 모든 타입에 대해서 동작!!
template<typename T> void foo(T&& arg) {}


int main()
{
	Point pt(0, 0);

	// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
	foo(pt);
	foo(Point(0,0));
}
