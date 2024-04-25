#include <iostream>

void foo(int& a)		{ std::cout << "int&" << std::endl; }
void foo(const int& a)	{ std::cout << "const int&" << std::endl; }
void foo(int&& a)		{ std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;
	foo(n);		// int&
	foo(10);	// int&&

	int& r1 = n;
	foo(r1);	// int&

	int&& r2 = 10;		// 10 은 rvalue 지만, r2 는 lvalue 입니다.
	foo(r2);	// int&

	// data 타입과 value category 를 잘 구별하세요

	//				data type     	value category
	// n			int				lvalue
	// n + 2		int				rvalue
	// 10			int				rvalue
	// Point(1,2)	Point			rvalue
	// r1			int&			lvalue
	// r2			int&&			lvalue
	//-------------------------------------------------
	// foo(int&)  : int&  타입을 받겠다는 것이 아니라 lvalue 받겠다는것
	// foo(int&&) : int&& 타입을 받겠다는 것이 아니라 rvalue 받겠다는것

	foo(r2); // foo(int&)

	foo( static_cast<int&&>(r2)); // foo(int&&)
		// r2 가 이미 int&& 타입인데, 다시 int&& 캐스팅하는 것은 어떤의미 인가요 ?
		// 이 캐스팅은 타입 캐스팅이 아닙니다

	// static_cast<TYPE> 에서
	// TYPE 안에 && 가 포함되어 있다면 타입캐스팅이 아니라 "value 속성을 변경"하는 캐스팅
	// => C++ 표준 문서에서 명확히 언급
}



