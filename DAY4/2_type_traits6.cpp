// 4_type_traits3 - 210 page
#include <iostream>

// 표준  traits 를 사용하려면
#include <type_traits>

// C++14 부터 아래 별명이 표준에 추가됩니다.
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;

template<typename T> void foo(T a)
{
	// 1. 조사하려면
	bool b1 = std::is_pointer<T>::value;
	bool b2 = std::is_pointer_v<T>; // C++17 부터 이렇게 사용가능.

	// 2. 변형 타입을 얻으려면
	typename std::remove_pointer<T>::type n1;
	std::remove_pointer_t<T> n2; // 위와 동일한 코드  - C++14 부터
}

int main()
{
	int n = 0;
	foo(&n);
}
