#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};

void* operator new(std::size_t sz)
{
	printf("new : %d bytes\n", sz);
	return malloc(sz);
}
int main()
{
	// 스마트 포인터
	// 1. 직접 객체 생성
	// 아래 코드는 동적 메모리를 몇번 할당 할까요 ? 2번
	// 1. new Point
	// 2. shared_ptr 의 생성자에서 "control block" 생성
//	std::shared_ptr<Point> sp1( new Point(1,2) );

	// 아래 코드는
	// 1. sizeof(Point) + sizeof(control block) 을 한번에 메모리 할당후
	// 2. 인자로 받은 것을 사용해서 Point 생성자 호출(완벽한 전달 기술)
	// 3. shared_ptr 만들어서 반환
	std::shared_ptr<Point> sp1 = std::make_shared<Point>(1,2);
}







