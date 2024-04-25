//  - 62page
#include <iostream>
#include <initializer_list> 

// 핵심 : 중요합니다. 반드시 이해해 두세요

void foo(std::initializer_list<int> e)
{
}
int main()
{
	// 1. 우변을 보고, 배열과 동일한 형태로 메모리에 할당(일반적으로 스택사용)
	// => "이름없는 배열"이라고 합니다 ( array rvalue )
	// 2. e 는 시작 주소와 갯수 또는 시작 주소와 마지막 다음 주소를 관리
	// g++ : 시작 주소와 갯수
	// vc  : 시작 주소와 마지막 다음요소 주소.

	// 3. e가 파괴될때 배열 메모리도 파괴.
	std::initializer_list<int> e = { 1,2,3,4,5 };

	// 4. e 요소 접근은 반복자 꺼내면 됩니다. 읽기만 가능
	auto p1 = e.begin();
	auto p2 = e.end();
//	*p1 = 10; // error

	// 5. 함수 인자로 사용하기 위해서 만든것 (주로 생성자 인자)
	foo({1,2,3});
	foo({1,2,3, 4, 5});
}


