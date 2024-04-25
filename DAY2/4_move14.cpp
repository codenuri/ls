#include <iostream>
#include <string>
#include <vector>
#include <array>

// herb shutter : C++ 표준위원회 의장을 했던 개발자(MS 수석 아키텍쳐)
// 			=> 새로운 C++ 작업중(c++front)

// 핵심 : Setter 만들기 #3

class People
{
private:
	std::string name;
	std::string address;
public:
	// 인자가 2개인 setter
	void set(const std::string& n, const std::string& a)
	{
		name = n;
		address = a;
	}
	void set(std::string&& n, std::string&& a)
	{
		name = std::move(n);
		address = std::move(a);
	}	
	void set(std::string&& n, const std::string& a)
	{
		name = std::move(n);
		address = a;
	}		
	void set(const std::string& n, std::string&& a)
	{
		name = n;
		address = std::move(a);
	}	
	// 인자가 N개인 setter 가 move 를 지원하려면
	// => 2^N 개의 함수 필요

	// 생성자도 setter 입니다. 인자가 2개 이상인 생성자도 많습니다.
	// => move 지원하려면 위처럼 해야 합니다.
	// => 완벽한 전달 기술을 사용하면 "한개의 함수템플릿"으로 모두 해결!!!

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








