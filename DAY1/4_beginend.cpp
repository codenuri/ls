// 4_beginend - 16 page
#include <vector>
#include <list>
#include <iostream>
#include <ranges>

int main()
{
	//std::vector<int> v = { 1,2,3,4,5 };
	//std::list<int>   v = { 1,2,3,4,5 };
	int v[5] = { 1,2,3,4,5 };

	// C++98 스타일 
	// => 컨테이너 교체시, 타입도 변경해야 합니다.
	// => 아래 처럼 하지 말고 auto 권장.
//	std::vector<int>::iterator p1 = v.begin();
//	std::vector<int>::iterator p2 = v.end();

	// C++11 auto 사용
//	auto p1 = v.begin(); // v 가 raw array 일때는 에러!

	auto p1 = std::begin(v); // v가 raw array 라도 ok.. 

//	auto sz = v.size(); // v가 raw array 라면 error
	auto sz = std::size(v); // raw array 라도 ok

	// C++20 부터 새로운 begin 등장
	auto p3 = std::ranges::begin(v);
	
	// 새로운 begin 이 등장하는 이유
	// => 아래 코드의 함수인자를  인자를 생각해 보세요
	// => 임시객체로 생성된 컨테이너의 요소를 가리키는 반복자가 반환
	auto p4 = std::begin( std::vector{1,2,3} );
	int n = *p4; // 파괴된 메모리 접근. runtime 오류.

//	auto p4 = std::ranges::begin( std::vector{1,2,3} ); // 컴파일에러
}
// visual stdio 에서 프로젝트 메뉴 => 속성 메뉴 선택하세요
// 나타나는 창에서 C++ 버전을 "c++ lastest" 로 설정하세요