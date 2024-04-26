#include <string>
#include <string_view>
#include <algorithm>
#include <vector>
#include <ranges>

int main()
{
	std::string s = "to be or not to be";

	// 아래 코드를 생각해 보세요 
	auto p1 = std::begin( std::vector<int>{1,2,3} );
				// 반환된 반복자는 dangling 입니다.
				// 파괴된 컨테이너를 가리키는 반복자

	auto p2 = std::begin( std::string_view{s} );
				// 임시객체인 string_view 가 파괴되어도
				// p2 가 가리키는 곳은 유효 합니다.
				// 사용가능 합니다.

	// 즉, 같은 임시객체라고 "자원을 소유"하는가 "빌려 쓰는가" 에 따라 
	// 다양한 경우 결과가 다르게 됩니다.
	// 그래서 "RUST언어에 borrow" 개념이 있고
	// C++20 부터 C++ 에도 도입되었습니다.

	bool b1 = std::ranges::borrowed_range<std::vector<int> >;
	bool b2 = std::ranges::borrowed_range<std::string_view>;

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	// std::ranges::begin 은 위 개념을 모두 가진 함수 입니다.
	auto p3 = std::ranges::begin( std::vector<int>{1,2,3}); // error
	auto p4 = std::ranges::begin( std::string_view{s});  // ok

	// std::string_view : 연속된 메모리에 있는 "char" 타입의 view - C++17
	// std::span<T>     : 연속된 메모리에 있는 "T" 타입의 view - C++20

	// C# 에도 Span<T> 가 있습니다.
}

// 13:00 에 시작 합니다.






