// auto1.cpp

int main()
{
	int n = 1;
	int& r = n;
	const int c = 1;

	// a1, a2, a3 의 타입을 예측해 보세요
	// 규칙 : 우변의 표현식이 가진 const, volatile, reference 를 제거하고 타입결정
	auto a1 = n; // int a1;
	auto a2 = r; // int a2;
	auto a3 = c; // int a3;

	// decltype(exp) : exp 의 선언시 사용된 타입 조사
	decltype(n) d1; // int d1
	decltype(r) d2; // int& d2  이므로 초기값 없다고 에러
	decltype(c) d3; // const int d3 인데, 초기값 때문에 에러.
	
}