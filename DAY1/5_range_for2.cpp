// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	
	for (auto& n : v) 
	{
		std::cout << n << std::endl;
	}
	// 위 코드의 정확한 원리 - 컴파일러가 위 코드를 아래 코드로 변경합니다
	auto first = v.begin(); // 배열이면 std::begin(v)
	auto last = v.end();

	for( ; first != last; ++first )
	{
		auto& n = *first;
		//------------------------------------
	}
}















