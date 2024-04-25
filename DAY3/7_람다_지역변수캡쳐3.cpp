#include <iostream>

int main()
{
	int v1 = 10, v2 = 10;

	// capture by reference
	auto f1 = [&v1, &v2](int a) { v1 = 100; return a + v1 + v2; }; 

	f1(0); // v1 = 100 은 실제 지역변수 변경

	std::cout<< v1 << std::endl; // 100
/*
	class CompilerGeneratedName 
	{
		int& v1;
		int& v2;
	public:
		CompilerGeneratedName(int& a, int& b) : v1(a), v2(b) {}

		inline int operator()(int a) const  
		{
			v1 = 100; 			// ok. 이 코드는 v1 을 변경한것이 아니라
								// v1 이 가리키는 대상체를 변경하므로!!	
			return a + v1 + v2;
		}
	};
	auto f1 = CompilerGeneratedName{v1, v2};
*/
}





