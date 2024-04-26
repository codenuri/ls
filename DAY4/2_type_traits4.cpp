// 4_type_traits3 - 210 page
#include <iostream>
#include <type_traits>

// traits 의 종류
// 1. 타입질의    : is_xxx<T>::value
// 2. 변형타입얻기 : xxx<T>::type

// remove_pointer 구현 원리
template<typename T> struct remove_pointer 
{
	using type = T;
};
template<typename T> struct remove_pointer<T*>
{
	using type = T;
};
int main()
{
	remove_pointer<int*>::type n2; // int n2
}

template<typename T> void foo(T a)
{
	// T 에서 remove_pointer 사용시 typename 붙여야 합니다.
//	remove_pointer<T>::type n1; // error
	typename remove_pointer<T>::type n1; // ok
}
