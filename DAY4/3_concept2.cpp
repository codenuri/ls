#include <iostream>
#include <concepts>
#include <vector>
#include <type_traits>
#include <iterator>

// C++20 이전의 템플릿 : 모든 타입에 대해서 동작
// C++20 이후의 템플릿 : concept 을 만족할때만 사용 하도록 제약을 전달가능.

/*
template<typename T> requires std::ranges::range<T>
void foo(const T& a)
{
	std::cout << "container\n";
}

template<typename T> requires std::integral<T>
void foo(const T& a)
{
	std::cout << "integral\n";
}
*/
// syntax sugar ( 동일한 의미이지만, 코딩을 단순하는 문법 )
// => cppreference.com 에서 std::ranges::find 찾아보세요
/*
template<std::ranges::range T> 
void foo(const T& a)
{
	std::cout << "container\n";
}

template<std::integral T> 
void foo(const T& a)
{
	std::cout << "integral\n";
}
*/

// template 키워드도 생략가능.
// => 아래 코드가 조건(concept) 을 만족하는 경우만 사용할 함수템플릿
void foo(std::ranges::range auto a)
{
	std::cout << "container\n";
}

void foo(std::integral auto a)
{
	std::cout << "integral\n";
}

void goo( auto a)
{
	std::cout << "goo\n";
}


int main()
{
	int n = 0;
	std::vector<int> v{ 1,2,3 };

	foo(n);
	foo(v);
}
