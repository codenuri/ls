#include <iostream>
#include <type_traits>

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }
	Object(Object&&) noexcept { std::cout << "move" << std::endl; }
};
/*
template<typename T>
T&& mymove(T& obj)
{
	return static_cast<T&&>(obj);
}
*/
// 아래 2개를 잘 구별해 두세요
// T&  : 인자로 lvalue 만 받겠다는 의미
// T&& : 인자로 lvalue 와 rvalue 를 모두 받겠다는 의미

// move 는 lvalue 와 rvalue 를 모두 받아야 합니다.
template<typename T>
std::remove_reference_t<T> && mymove(T&& obj)
{	
	// 아래 캐스팅은 rvalue 캐스팅 이 아닙니다.
	// mymove(o2) 처럼 lvalue 로 전달되면 T = Object& 입니다.
	// 따라서 아래 캐스팅은
	// mymove 인자로 lvalue 를 보내면 lvalue 로 캐스팅
	// mymove 인자로 rvalue 를 보내면 rvalue 로 캐스팅
//	static_cast<T&&>(obj);	// 즉, std::forward 가 사용하는 캐스팅.

	// move 의 목표는 "무조건 rvalue 캐스팅" 입니다.
	// 해결책 : "T안에 있는 참조를 제거한 타입" 을 구해서 && 붙이면 됩니다
	return static_cast<std::remove_reference_t<T> &&>(obj);
}

int main()
{
	Object o1;
	Object o2 = o1;				// copy
	Object o3 = std::move(o1);	// move
	Object o4 = mymove(o2);		// move	
	Object o5 = mymove( Object{} ); // move
}
