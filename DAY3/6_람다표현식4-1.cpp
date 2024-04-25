#include <vector>
#include <algorithm>
#include <functional> // 이 안에 std::less 있습니다.

int main()
{
	std::vector<int> v = {1,3,5,2,4};

	// 아래 코드를 평가해 보세요
	// => 모든 람다 표현식은 다른 타입이므로, 같은 구현의 람다 표현식도 다른타입
	// => std::sort() 함수가 3개 생성됨..
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b;});
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b;});
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b;});

	// 핵심 #1. 동일한 람다 표현식을 여러번 사용할때는
	// => auto 변수에 담아서 사용하세요
	auto cmp = [](int a, int b) { return a < b;};

	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);

	// 핵심 #2. < 연산을 수행하는 함수 객체는 이미 표준에 있습니다.
	// => 람다표현식을 사용할 필요 없습니다.
	// => 람다표현식은 결국, 새로함수 객체 만든것
	std::less<int> f;
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), f);
	std::sort(v.begin(), v.end(), f);

}