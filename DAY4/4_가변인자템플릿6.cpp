#include <iostream>

// recursive 기법
// => 단, 아래 코드는 실제 "재귀 호출"은 아닙니다.
// => foo(3개인자) => foo(2개인자) => foo(1개인자) 순으로 호출

// 1. 첫번째 인자는 "가변이 아닌 독립된 이름" 으로 받으세요

void foo() {} // 아래 재귀의 종료를 위해서 C++14 까지는 이 코드 필요

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{	
	static int cnt = 0;

	std::cout << ++cnt << " : " << value << std::endl;

	// 아래 코드는 C++14 까지
//	foo( args... ); // foo(3.4, 'A')
					// foo('A')
					// foo()

	// 아래 코드는 C++17 부터 가능 ( if constexpr 이 C++17 문법)
	if constexpr ( sizeof...(args) > 0 )
		foo( args... );
}

int main()
{
	foo(1, 3.4, 'A'); 
}





