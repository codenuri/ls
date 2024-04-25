// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체의 특징 - 79 page
int main()
{
	Point pt(1, 2);
	
	pt.x = 10;			// ok
	Point(1, 2).x = 10;	// error.	
						// 특징 1. 임시객체는 = 의 왼쪽에 올수 없다.
						//		  임시객체는 rvalue 이다.(lvalue가 될수 없다)

	Point* p1 = &pt;			// ok
	Point* p2 = &Point(1, 2);	// error.
								// 특징 2. 임시객체는 & 연산자로 주소를 구할수 없다
								//        (rvalue 는 주소를 구할수 없다.)

	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error.
								// 특징 3. 임시객체는 non-const reference로
								//			가리킬수 없다.
	
	const Point& r3 = Point(1,2); // ok
								  // 특징 4. 임시객체라도 const reference 로
								  //        가리킬수 있다.
								  // 이순간 임시객체의 수명은 r3의 수명으로 연장됩니다.
								  // "lifetime extension" 이라는 개념
	// 왜 이런 복잡한 규칙을 만들었나요 ?
	// => 임시객체3.cpp 을 생각해 보세요
	// => 임시 객체를 함수 인자로 받을수 있게 하기 위해서 만들어진 규칙

	// C++11 을 만들때 상수성 없이 임시객체를 가리키는 문법이 필요 했습니다
	// (move 와 완벽한 전달을 위해)
	// 그래서, 새로운 문법의 탄생
	Point&& r4 = Point(1,2); // ok
							 // 상수성 없이 임시객체를 가리키는 문법

	foo(Point(1,2)); // 임시객체 전달
}

void foo(Point&& p) // 상수성 없이 임시객체를 받아서
{
	p.x  = 10;      // 임시객체를 수정!!!
}

// 왜??? 임시객체(곧 파괴될 객체)를 수정하나요 ?
// => move 때문에



