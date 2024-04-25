#include <iostream>
#include <vector>

// 아래 클래스를 이해해 보세요 - C++20 에서 등장하는 기술의 핵심입니다.
template<typename T>
class reverse_view 
{
	T& r;
public:
	reverse_view(T& r) : r{r} {}
	auto begin() { return r.rbegin();} // <== 핵심
	auto end()   { return r.rend();}   
};

template<typename T>
class take_view 
{
	T& r;
	int cnt;
public:
	take_view(T& r, int c) : r{r}, cnt{c}  {}

	auto begin() { return r.begin();}
	auto end()   { return std::next(r.begin(), cnt);}   
};


int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
//	reverse_view rv(v);

//	for (auto& n : v) 
//	for (auto& n : rv) 
//	for (auto& n : reverse_view(v) ) 
	for (auto& n : take_view(v, 3) ) 
	{
		std::cout << n << std::endl;
	}

}















