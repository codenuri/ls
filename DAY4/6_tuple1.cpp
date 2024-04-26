// 8_tuple1 - 245 page
#include <tuple>

int main()
{
	// pair : 서로 다른 타입 2개를 보관 - C++98
	std::pair<int, double> p(1, 2.3);

	auto a1 = p.first;  // 1
	auto a2 = p.second; // 2.3

	std::pair<int, std::pair<double, char>> p3(1, {3.4, 'A'});

}
