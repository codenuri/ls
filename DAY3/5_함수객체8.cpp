#include <vector>
#include <list>
#include <algorithm>
#include "chronometry.h"

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less   { inline bool operator()(int a, int b) { return a < b; }};
struct Greater{	inline bool operator()(int a, int b) { return a > b; }};


constexpr std::size_t count = 1'000'000;

std::vector<int> v1;
std::vector<int> v2;
std::vector<int> v3;

void init()
{
	v1.reserve(count);
	v2.reserve(count);
	v3.reserve(count);

	for( int i = 0; i < count; i++)
	{
		int n = rand();
		v1.push_back(n);
		v2.push_back(n);
		v3.push_back(n);
	}
}

void ex1() { std::sort(v1.begin(), v1.end(), cmp1); } 
void ex2() { std::sort(v2.begin(), v2.end(), Less{});} 

void ex3() 
{ 
	std::sort(v3.begin(), v3.end(), 
			[](int a, int b) { return a < b;}) ;
} 

int main()
{
	init();
	chronometry(ex1);
	chronometry(ex2);
	chronometry(ex3);	
}

