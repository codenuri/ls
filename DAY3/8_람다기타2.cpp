// C++20 부터 일반 함수 인자도 auto 가능. 원리는 template
//void foo(auto n) {}  // template<typename T> void foo(T n) {}

int main()
{
	// generic lambda
	// => 람다표현식의 인자로 auto 를 사용하는 문법
	// => C++14 부터 가능.
//	auto f = [](int a, int b) { return a + b; };
	auto f = [](auto a, auto b) { return a + b; };

	int    n = f(1, 2);
	double d1 = f(3.2, 3.2);
	double d2 = f(3.2, 2);
}
// generic lambda 의 원리
// => operator() 가 템플릿
class CompilerGeneratedName
{
public:
	template<typename T1, typename T2>
	inline auto operator()(T1 a, T2 b) const 
	{
		return a + b;
	}
};