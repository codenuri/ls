#include <iostream>

template<typename ... Types>
struct tuple 
{
	static constexpr int N = 0; 
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple<Types...>
{
	using base = tuple<Types...>;

	T value;
	tuple() = default;
	tuple(const T& v, const Types& ... args ) 
		: value(v), base(args...) {}
	
	static constexpr int N = base::N + 1; 
};

int main()
{
//	tuple<> t0;						// 재귀 종료, primary 사용
//	tuple<             short> t1;	// short 보관
//	tuple<     double, short> t2;	// double 보관
	tuple<int, double, short> t3(1, 3.4, 5); // 1, int 보관

	std::cout << t3.value << std::endl; // 1

	std::cout << static_cast<tuple<double, short>&>(t3).value << std::endl; //  3.4

	std::cout << static_cast<tuple<short>&>(t3).value << std::endl; //  5

	auto n = get<0>(t3);
	get<0>(t3) =10;
}

template<int N, typename TP>
튜플_TP_가 가진 N 번째 요소의 타입& 
get( TP& tp )
{
	return static_cast<TP의_N번째_부모_타입&>(tp).value;
}