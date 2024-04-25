#include <type_traits>

// if : 실행시간 조건문, 컴파일 시간에는 판단하지 않음.
//      따라서 조건식이 컴파일 시간에 false 로 결정되어도 인스턴스화에 포함됨.

// if constexpr : 컴파일 시간 조건문, 조건식이 false 라면
//				 템플릿 인스턴스화에 포함 안됨.

// cppreference.com 에서 std::invoke 찾아보세요 "possible implementation" 참고

//#ifdef 대신  if constexpr 로 안되나요 ?


template<typename T> void foo(T a)
{
	// 아래 코드는 에러가 있을까요 ?
//	if (false)
//	if constexpr ( false )
	if constexpr ( std::is_pointer_v<T> )
	{
		// 포인터 일때 최적화된 알고리즘
		*a = 10;
	}
	else if constexpr( std::is_reference_v<T> )
	{
	}
	else 
	{
	}
}
int main()
{
	foo(0); 
}

