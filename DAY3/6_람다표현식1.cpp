// 5_람다표현식1
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	
	// sort 하고 싶다면
	std::sort( v.begin(), v.end() );  // 비교정책을 전달하지 않으면 오름차순

	// 비교정책을 변경하려면
	// #1. 일반함수 - 정책함수가 인라인 치환 될수 없다.
//	std::sort( v.begin(), v.end(), cmp1 );

	// #2. 함수 객체 사용 - 정책함수의 인라인 치환 가능.
	std::less<int> f1;
	std::sort( v.begin(), v.end(), f1 );
	std::sort( v.begin(), v.end(), std::less<int>{} ); // 임시객체형태로

	// #3. 람다표현식 사용 - C++11 부터

	// => 함수 이름(주소)가 필요한 자리에 함수의 구현을 전달하는 문법
	// [] : 람다가 시작됨을 알리는 "lambda introducer"
	// => 인라인 치환 가능.
	std::sort( v.begin(), v.end(), 
				[](int a, int b) { return a < b; } );
}





