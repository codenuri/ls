#include <iostream>

template<typename T> void foo(T&& arg)
{
	// 확인하는법
	// #1. 아래처럼 하지 마세요 ( C++ RTTI 는 정확하지 않습니다. )
//	std::cout << typeid(T).name() << std::endl;

	// #2. 아래 처럼 생성된 함수이름을 출력해 보세요
	// __function__ : C++ 표준 매크로, 함수 이름만 담은 매크로
	// __FUNCSIG__  : 함수이름 + 인자의 형태도 같이 출력 ( vc++ 전용)
	// __PRETTY_FUNCTION__ : g++, clang++ 전용
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	// #3. 이 코드를 godbolt.org 에 넣으세요.
}
int main()
{
	int n = 10;

	foo(n);  // T = int&
	foo(10); // T = int
}




