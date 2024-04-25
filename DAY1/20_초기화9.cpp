// 1_�ʱ�ȭ9. - 63 page
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int)      { std::cout << "int" << std::endl;	}
	Point(int, int) { std::cout << "int, int" << std::endl; }
	Point(std::initializer_list<int> e) { std::cout << "initializer_list<int>" << std::endl; }
};
int main()
{
	Point p1(1);		// Point(int) 생성자 호출
	Point p2(1, 2);		// Point(int, int) 생성자 호출
	Point p3({ 1,2 });	// Point(std::initializer_list)생성자 호출
	
	Point p4{ 1,2 };	// 1. Point(std::initializer_list) 생성자가 있으면사용.
						// 2. 1이 없으면 Point(int, int) 생성자

	Point p5(1, 2, 3); 	// error. Point(int, int, int) 생성자는 없다.

	Point p6{ 1, 2, 3 }; // ok. Point(std::initializer_list) 생성자 사용
	
	Point p7 = { 1,2,3 }; // ok. explicit 가 아니므로 

	// 핵심 : 생성자 인자로 std::initializer_list 를 사용하면
	// => 동일 타입의 인자를 몇개라도 전달 가능하다.
	// => 그래서, C++11 부터 STL 모든 컨테이너는 아래처럼 사용가능

	std::vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
	std::vector<int> v2 {1,2,3,4,5,6,7,8,9,10};
}


