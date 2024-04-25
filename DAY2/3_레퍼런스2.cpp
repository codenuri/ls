#include <iostream>

// 90 page
void foo(int& a)       { std::cout << "int&" << std::endl; }
void foo(const int& a) { std::cout << "const int&" << std::endl; }
void foo(int&& a)      { std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;
	foo(n); 	// lvalue
				// 1번 선택. 
				// 1번이 없으면 2번 사용.	

	foo(10);	// rvalue
				// 3번 선택.
				// 3번이 없으면 2번 사용.
}
// 위 규칙은 move 의 핵심 입니다. 반드시 외워야 합니다.







