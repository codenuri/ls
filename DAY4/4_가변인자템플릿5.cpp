#include <iostream>
#include <tuple>

template<typename ... Types> void foo(Types ... args)
{
	// args 에 있는 "2 번째 요소를 꺼내고 싶다면"
	// => 이렇게 직접 꺼내는 방법는 C++26 부터 지원 됩니다. 
	// => "args...[2]"" => C++26
	
	// C++26 이전에는 아래 3가지 방법으로만 요소 접근 가능합니다.
	// 1. pack expansion 으로 모든 요소를 , 로 열거(args...)
	// 2. recursive 유사 코드 작성
	// 3. fold expression - C++17

	//----------------------------------------
	// pack expansion!
	// 모든 요소가 동일 타입이면 배열에 담아서 사용가능.
	int[] x = { args... };

	// 요소가 다른 타입이면 tuple 에 담아서 사용
	std::tuple<Types...> t = {args...};

	auto n = std::get<1>(t); // tuple 의 요소 접근

}


int main()
{
	foo(1, 2, 3);
}

