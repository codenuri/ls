#include <iostream>
#include <vector>

// 사용자 정의 타입을 range-for 에 전달하려면
// => 멤버 함수 begin(), end() 을 제공하거나
// => begin(타입), end(타입) 의 일반함수가 있으면 됩니다

struct Point3D
{
	int x, y, z;

//	int* begin() { return &x;}
//	int* end()   { return &z + 1;} // 마지막 다음 요소의 주소!
};
// 일반 함수 버전.
int* begin(Point3D& p) { return &(p.x)};
int* end(Point3D& p)   { return &(p.z) + 1};

int main()
{
	Point3D p;
	p.x = 10;
	p.y = 20;
	p.z = 30;

	for (int n : p)  // 이 코드를 생각해 보세요
		std::cout << n << std::endl; 

}















