#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// 핵심 1. 전역변수는 람다표현식에 직접 사용가능
	auto f1 = [](int a) { return a + g; };		// ok

	// 핵심 2. 람다표현식에 지역변수를 사용하려면 캡쳐 해야 합니다.
//	auto f2 = []      (int a) { return a + v1 + v2; };// error	
	auto f2 = [v1, v2](int a) { return a + v1 + v2; };// ok
}





