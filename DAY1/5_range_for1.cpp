// 5_range_for1.cpp   21 page
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 전통적인 for 
	for (int i = 0; i < v.size(); i++)
	{
	}

	// 새로운 for 문 - range for 라는 문법.
	// => v 위치는 STL 컨테이너와 배열이 가능. 
	for( auto e : v )
	{

	}
}















