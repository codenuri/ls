#include <iostream>
#include <type_traits> // 이 안에 이미 std::is_pointer 가 있습니다.

template<typename T> void printv(const T& v)
{
	if ( std::is_pointer<T>::value  )
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}

