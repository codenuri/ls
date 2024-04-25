// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// 임시객체와 함수 반환값 -  82 page
/*
void f1(Point  pt) {} // call by value     : 복사본 생성
void f2(Point& pt) {} // call by reference : 복사본 생성 안됨

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/

Point pt(1, 2);

Point foo() // return by value : pt를 반환하는 것이 아니라
{			//					 pt의 복사본을 반환 한것
			//					 복사본에 이름이 없다.(리턴용 임시객체)
	return pt; // return Point{pt}; 의 의미. 
}
Point& goo() // return by reference : 리턴용 임시객체를 만들지 말라는 의미
{
	return pt;
}

int main()
{
	foo().x = 10; // error. "임시객체.x = 10" 인데, 임시객체는 rvalue 이므로
	goo().x = 10; // ok.    "pt.x = 10" 의 의미
}




