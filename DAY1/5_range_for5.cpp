#include <iostream>
#include <vector>
#include <ranges> // C++20 부터 제공되는 헤더.

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	std::ranges::take_view tv(v, 3);
	std::ranges::reverse_view rv(tv); // 중첩도 됩니다.

	// 위 코드는 아래와 같이 pipe line 기법으로 만들수도 있습니다.
	auto rv2 = v | std::views::take(3) | std::views::reverse;

//	for (auto& n : rv1 ) 
//	for (auto& n : rv2 ) 
	for (auto& n : v | std::views::take(3) | std::views::reverse ) 
	{
		std::cout << n << std::endl;
	}
}

// 10:45 분에 시작합니다.













