#include <iostream>
#include <string>
#include <vector>
#include <array>

// 핵심 : Setter 만들기 #3

class People
{
private:
	std::string name;
	std::string address;
public:
/*
	void set(const std::string& n, const std::string& a)
	{
		name = n;
		address = a;
	}
	*/

	// 인자가 1개인 setter 의 move 지원
	// => T&& 를 사용해도 되지만, 
	// => T&& 사용하지 말고 보통 2개를 만드는 경우가 많습니다.(move12.cpp 참고)

	// 인자가 2개이상인 setter 의 move 지원
	// => T&& 사용하는 것이 관례
	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name    = std::forward<T1>(n);
		address = std::forward<T2>(a);
	}
};

int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p;
	p.set(name,			   addr);
	p.set(std::move(name), addr);
	p.set(name,			   std::move(addr));
	p.set(std::move(name), std::move(addr));
}








