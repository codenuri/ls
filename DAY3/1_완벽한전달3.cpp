// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}


template<typename F>
void chronometry(F f, int& arg) 
{								
	f(arg);	  
}
template<typename F>
void chronometry(F f, int&& arg) 
{								
	f(arg);	  
}

int main()
{
	hoo(10); // ok
	chronometry(hoo, 10); 	// 왜 에러일까요 ?
							// 해결책은 ??
							// => 4번소스에서... 
}
