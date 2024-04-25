#include <iostream>

class Meter 
{
	int value;
public:
	Meter(int n) : value(n) {}
};
// 사용자 정의 literal 문법
// => 정수 리터럴에 사용되는 함수의 인자는 반드시 unsigned long long
// => _가 붙지 않은 것은 표준에서 사용하기로 예약됨.
// => 사용자가 만들때는 반드시 _로 시작해야 한다.(에러 또는 경고)
Meter operator""_m(unsigned long long value)
{
	Meter m( static_cast<int>(value) );
	return m;
}
int main()
{
	Meter me = 3_m; // operator""_m(3) 을 찾게 됩니다.

//	Gram  gr = 3g;

	float f = 3.4f; 
}




