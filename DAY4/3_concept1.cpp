#include <vector>
#include <type_traits>
#include <iterator>
#include <iostream>
#include <concepts> // C++20 에서 제공하는
					// 이미 만들어진 concept

// concept : 타입이 가져야 하는 요구조건을 코드로 작성하는 문법
// C++20 에서 도입된 기술
// concept 때문에 아주 많은 부분에서 변화가 생기게 됩니다.

// 어떻게 "조사할까" 가 중요한 것이 아니라 어떻게 "정의" 할까 가 핵심
// => 그래서 concept 이름은 "is_" 로 시작하지 말라는 것이 권장.
template<typename T>
concept container = requires(T& c)
{
//	c.begin();
//	c.end();
	std::begin(c);
	std::end(c);
};
template<typename T>
void foo(const T& arg)
{
//	bool b = std::is_pointer_v<T>;
//	bool b = container<T>;
	bool b = std::ranges::range<T>;

	std::cout << b << std::endl;
}
int main()
{
	int n = 0;
	std::vector<int> v{ 1,2,3 };
	foo(v); // true
	foo(n); // false

	int x[3] = {1,2,3};
	foo(x); // ??
}
