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

template<int N, typename TP> struct tuple_element
{	
//	using type = ?;
	// 현재 상태에서는 TP 의 N 번째 요소의 타입을구할수 없습니다.
	// => 구할수 있도록 부분 특수화해야 합니다.
};

// N == 0 일때
/*
template<typename TP> struct tuple_element< 0, TP>
{	
	// 임의 튜플 TP 의 0번째 요소 타입 => 구할수 없다.
	// 잘못된 부분 특수화(문법적 오류가 아니라, 원하는 것을 얻을수 없다
};
*/
/*
template<typename ... Types> 
struct tuple_element< 0, tuple<Types...> >
{	
	// tuple<Types...> 의 0번째 요소 타입 => 구할수 없다.
	// 잘못된 부분 특수화
};
*/

template<typename T,  typename ... Types> 
struct tuple_element< 0, tuple<T, Types...> >
{	
	using type = T; 
	using tupleType = tuple<T, Types...>; 
};

// N != 0
template<int N, typename T,  typename ... Types> 
struct tuple_element< N, tuple<T, Types...> >
{	
	// tuple<int, double, short> 의 2번째 요소의 타입은 
	// tuple<     double, short> 의 1번째 요소의 타입은 
	// tuple<             short> 의 0번째 요소의 타입은 
	using type = typename tuple_element<N-1, tuple<Types...>>::type;
	using tupleType = typename tuple_element<N-1, tuple<Types...>>::tupleType;
};



int main()
{
	using TP = tuple<int, double, short>;

//	tuple_element<0, TP>::type n;
	tuple_element<1, TP>::type n;

	std::cout << typeid(n).name() << std::endl;
}







