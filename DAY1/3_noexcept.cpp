// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept
// 1. 예외가 없(있)는지 조사
// 2. 예외가 없음을 알릴때 사용

// STL 내부에서 "예외가 없음을 보장하는 타입(함수)" 일 경우 최적화를 하는 코드가 많이
// 있습니다. => 내일 move 시간에 
void foo() noexcept 
{
}
void goo()
{
	if (1) // 실패라고 가정
		throw std::bad_alloc();
}
int main()
{
	bool b1 = noexcept(foo());
	bool b2 = noexcept(goo());
	std::cout << b1 << ", " << b2 << std::endl;
}




