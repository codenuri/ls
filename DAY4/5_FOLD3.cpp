#include <iostream>
#include <vector>

template<typename ... Types>
void insert( std::vector<int>& v, Types ... args)
{
	// args 의 모든 요소를 v에 넣어 보세요
	( v.push_back(args)  , ...  );
		// (v.push(E1), (v.push(E2), v.push(E3) ))
}
int main()
{
	std::vector<int> v;
	insert(v, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	for( auto e : v)
		std::cout << v << std::endl;
}



