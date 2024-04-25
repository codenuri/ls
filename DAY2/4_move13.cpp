#include <iostream>
#include <string>
#include <vector>
#include <array>

// 핵심 : Setter 만들기 #2

class People
{
private:
	std::string name;
	int age;
	std::array<int, 32> data;
public:
	// retain parameter 만 move 를 생각하면 됩니다
	// in parameter 는 move 생각하지 마세요

	// 인자로 받은 문자열을 내부적으로 멤버에 보관하는 (retain) 경우만 아래처럼 2개작성
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }

	// 아래 처럼 인자로 받은 것을 사용(읽기)하기만 하는 경우는 move 고려 대상아닙니다.
	void print_msg(const std::string& msg) const
	{
		std::cout << msg << std::endl;
	}
	// std::array<int, 32> 는 raw array 처럼 데이타를 스택에 보관
	// std::move 효과 없습니다. 고려할 필요 없습니다.
	void set_data(const std::array<int, 32>& d)
	{
		data = d;
	}
};

int main()
{
	std::string s = "hello";
	std::array<int, 32> arr = {0};

	People p;

	p.print_msg(s);
	p.set_data(arr);
}








