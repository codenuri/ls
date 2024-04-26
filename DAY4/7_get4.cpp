// get3.cpp => tuple5.cpp 복사
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
//=======================================================

// tuple_element 는 부분 특수화 버전만 사용하게 됩니다
// => 이경우 primary 버전은 선언만 하면 됩니다.
template<int N, typename TP> struct tuple_element;

template<typename T,  typename ... Types> 
struct tuple_element< 0, tuple<T, Types...> >
{	
	using type = T; 
	using tupleType = tuple<T, Types...>; 
};

template<int N, typename T,  typename ... Types> 
struct tuple_element< N, tuple<T, Types...> >
{	
	using type = typename tuple_element<N-1, tuple<Types...>>::type;
	using tupleType = typename tuple_element<N-1, tuple<Types...>>::tupleType;
};

template<int N, typename TP>
typename tuple_element<N, TP>::type &
get( TP& tp )
{
	return static_cast<typename tuple_element<N, TP>::tupleType &>(tp).value;
}

int main()
{
	tuple<int, double, char> t(1, 3.4, 'A');

	get<0>(t) = 10;

	std::cout << get<0>(t) << std::endl;
	std::cout << get<1>(t) << std::endl;
	std::cout << get<2>(t) << std::endl;
}








