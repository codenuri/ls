#include <iostream>
#include <string>
#include <vector>

// 왜 move가 중요한가 ? - 101 page 아래 있습니다.

// 아래 코드는 복사를 사용하는 swap 입니다.
// => 성능이 좋지 않습니다.
/*
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
*/
// 아래 코드가 move를 사용한 swap
// => 위 코드보다 빠르게 동작합니다.
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}


int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}

// move 가 중요한 이유
// => swap, 버퍼 복사 등 다양한 알고리즘 작성시
// => std::move 를 적절히 사용하면 성능향상을 볼수 있습니다.

//int n1 = 10;
//int n2 = std::move(n1); 

