#include <iostream>
#include <vector>
#include <algorithm>

// 함수객체의 장점 1. Closure

bool foo(int n) { return n % 3 == 0; }

struct IsDivide 
{
	int value;
	IsDivide( int n) : value(n) {}

	bool operator()(int n) const 
	{
		return n % value == 0;
	}
};


int main()
{
	std::vector<int> v = { 1,2,6,5,4,3,7,8 };

	int k = 3;
	IsDivide f(k); // f 는 k 값을 캡쳐(보관)하는 단항 함수 객체 입니다.
	bool b = f(5); // "5 % k == 0" 을 조사하는 단항함수

	auto p1 = std::find_if(v.begin(), v.end(), f);	

	std::cout << *p1 << std::endl; // 6

	auto p2 = std::find_if(v.begin(), v.end(), IsDivide{k} );	
}
// 일반함수 : 동작은 있지만 상태가 없습니다.
// 함수객체 : 동작과 상태가 있습니다.(멤버 데이타가 있다는 것)

// std::find_if(v.begin(), v.end(), IsDivide{k} );	
// 의 3번째 인자는 
// "단항함수 + 지역변수k" 을 인자로 전달한다고 생각할수 있습니다
// 클로져 입니다.
// 클로져 : 자신이 속한 문맥의 지역변수를 캡쳐할수 있는 함수!!!


// 오후 수업은 13:00 에 시작 합니다.