#include <iostream>
#include <type_traits>

// 아래 코드가 T 가 포인터 인지 조사하는 기술 입니다.
template<typename T> struct is_pointer 
{
//	bool value = false ; // 1. 필드 초기화는 C++11 이전에는 안되고
						 // 2. 이렇게 하면 컴파일 시간에 사용할수 없다(변수!!)

//	enum { value = false };// 그래서 최초에는 이렇게 만들었던것

	static constexpr bool value = false; // C++11 이후는 이렇게!
};

template<typename T> struct is_pointer<T*> 
{
//	enum { value = true };
	static constexpr bool value = true;
};

template<typename T> void foo(const T& a)
{
	// 현재 T 는 : int, int*
	if ( is_pointer<T>::value )
		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
}

int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}
