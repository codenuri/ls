#include <iostream>
#include <vector>
#include <concepts>

template<typename T, typename V> 
		requires (!std::predicate<V, typename T::value_type>)
T myfind(T first, T last, V value)
{
	std::cout << "value 찾기\n";
	return first;
}
template<typename T, typename F> 
		requires std::predicate<F, typename T::value_type>
T myfind(T first, T last, F func)
{
	std::cout << "func을 만족하는 요소 찾기\n";
	return first;
}
int main()
{
	std::vector<int> v{1,2,3};

	// std::find_if 로 만들지 말고, 그냥 std::find 로 같은 이름을 사용하면
	// 좋지 않았을까 ??
	// => 이름 충돌 때문에 만들수 없었다.
	auto ret1 = myfind(v.begin(), v.end(), 3);
	auto ret2 = myfind(v.begin(), v.end(), 
						[](int a){ return a % 2 == 0;});
}