#include <iostream>

// 아래 코드를 복습할때는 반드시 "godbolt.org" 에 넣어 보세요

// 인자가 한개인 함수 템플릿
// => 인자가 한개인 함수를 생성 할수 있는 도구(틀)

// 가변인자 함수 템플릿
// => 인자의 타입, 갯수에 상관없이 어떠한 함수라도 생성할수 있는 도구(틀)

template<typename ... Ts> void foo(Ts ... args)
{
	// Ts   : int, double, char   => template parameter pack
	// args : 1,   3.4,    'A'    => function parameter pack

	// pack 에 있는 요소의 갯수 얻기
	std::cout << sizeof...(Ts)   << std::endl; // 3
	std::cout << sizeof...(args) << std::endl; // 3
}

int main()
{
	foo(1, 3.4, 'A');
}
