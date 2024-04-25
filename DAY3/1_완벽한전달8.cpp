#include <vector>
#include <list>
#include "chronometry.h"

constexpr std::size_t count = 1'000'000;

void ex1()
{
	std::vector<int> v;
	for( int i = 0; i < count; ++i)
	{
		v.push_back(i);
	}
}
void ex2()
{
	std::vector<int> v;
	v.reserve(count);
	for( int i = 0; i < count; ++i)
	{
		v.push_back(i);
	}
}
void ex3()
{
	std::list<int> v;
	for( int i = 0; i < count; ++i)
	{
		v.push_back(i);
	}
}
int main()
{
	chronometry(ex1);
	chronometry(ex2);
	chronometry(ex3);	
}
// visual studio 사용하시는 분은 "Debug" 모드, Release 모드에서 각각 해보세요

