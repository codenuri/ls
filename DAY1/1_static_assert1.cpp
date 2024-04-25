#include <cassert>

// static_assert( 조건식, 메세지 ) : 조건식이 참이 아니면
//								컴파일을 멈추고 에러를 발생해 달라. 
//							조건식은 반드시 컴파일 할때 결정되어야 한다.
//							변수 사용할수 없음. 
static_assert( sizeof(int*) == 8, "error not 64 bit");


void foo(int age)
{
	// 인자는 사용전에 유효성을 확인하는 것이 좋습니다
	assert(age > 0); // C언어 기술.

	int* p = new int[age];

	delete[] p;
}
int main()
{
	foo(-10);
}