// 복사생성자 모양을 생각해 봅시다.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 컴파일러가 제공하는 복사 생성자
//	Point(const Point& other) : x(ohter.x), y(other.y) {}

	// 복사생성자의 모양에 대해서 생각해 봅시다.
	// #1. call by value 
	// => 인자를 받을때 모양이 "Point other = p2" 이므로 다시 복사생성자호출
	// => 복사 생성자가 무한히 호출되는 코드. 컴파일 에러
//	Point(Point other) : x(other.x), y(other.y) {}

	// #2. call by non-const lvalue reference
	// => 에러 아님
	// => rvalue(임시객체)를 받을수 없다.
	// => "Point ret = foo()" 에서 foo 값 값으로 반환하면 에러
// 	Point(Point& other) : x(other.x), y(other.y) {}

	// #3. const lvalue reference 
	// => lvalue, rvalue 를 모두 받을수 있다.
	// => 이런 이유 때문에 "복사 생성자" 의 인자는 "const lvalue reference!!"
	Point(const Point& other) : x(other.x), y(other.y) {}
};
Point foo()
{
	Point p(1,1);
	return p;
}
int main()
{
	Point p1;		
	Point p2(1, 2); 
	Point p3(p2);	// 컴파일러가 제공하는 복사 생성자 사용	
	Point ret = foo();// error ( non-const 버전의 복사 생성자라면)			
}


// 11:00 에 시작합니다.

