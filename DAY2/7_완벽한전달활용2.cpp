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
int main()
{
	// 스마트 포인터
	// 1. 직접 객체 생성
	// 아래 코드는 동적 메모리를 몇번 할당 할까요 ?
	std::shared_ptr<Point> sp1(new Point(1,2));
}







