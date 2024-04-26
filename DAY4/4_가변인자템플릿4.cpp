#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}
template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3

//	printv(args...); 	// printv(1, 2, 3) 인데, printv 는 인자가 한개
					 	// error.
//	printv(args)...; 	// printv(1), printv(2), printv(3) 의 의도!!
						// error.
						// pack expansion 은 이위치에서는 사용할수 없다.
	// pack expansion 이 가능한 위치
	// 1. 함수 호출 () 안
	// 2. {} 초기화 안
	// 3. 템플릿인자 전달시 사용하는 <> 안

	int x[] = { (printv(args), 0)... }; 
		   // { (printv(1), 0), (printv(2), 0), (printv(3), 0) }

}


int main()
{
	foo(1, 2, 3);
}

