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

// main					chronometry						hoo(int&&)
// hoo(10) ================================================> ok
// chronometry(10) ==> int&& arg = 10
//					   hoo(arg) ============================> error
//					   hoo(static_cast<int&&>(arg))=========> ok
template<typename F>
void chronometry(F f, int&& arg) 
{					
	// int&& arg = 10 으로 받게 됩니다.
	// 10 이라는 rvalue 를 받으면서 arg 라는 이름이 생기게 됩니다.
	// arg 는 lvalue			
//	f(arg);	  // hoo(int&) 를 찾게 됩니다.

	// 원래 인자는 rvalue 였는데, 받으면서 lvalue 로 된것을
	// forward 할때는 다시 rvalue 로 변경합니다.
	f(static_cast<int&&>(arg)); // ok!!
}

int main()
{
	hoo(10); 
	chronometry(hoo, 10); 	
}
