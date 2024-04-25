#include <iostream>
#include <type_traits> 

#pragma pack(1)		// 멤버 align 을 1byte 단위로 해달라.
struct PACKET		// padding 추가 안됨.
{
	char cmd;
//  char padding[3];	
	int  data;
};
static_assert( sizeof(char) + sizeof(int) == sizeof(PACKET), 
				"error, unexpected padding");

/*
int main()
{
	std::cout << sizeof(PACKET) << std::endl; // ?
}
*/

// 9:30 분에 시작합니다.

template<typename T> void object_set_zero(T* p)
{
	// std::is_polymorphic_v<T> : 가상함수가 있으면 true
	// 							  <type_traits> 헤더 필요
	//								
	static_assert( ! std::is_polymorphic_v<T>, 
					"T has virtual function");

	memset(p, 0, sizeof(T)); 
}
class A
{
	int n;
};
int main()
{
	A a;
	object_set_zero(&a);
}
