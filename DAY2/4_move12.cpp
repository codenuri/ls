#include <iostream>
#include <string>
#include <vector>

// 핵심 : Setter 만들기 #1

class People
{
private:
	std::string name;
	int age;

public:
	// 방법 1. call by const reference
	// => C++98 시절에서는 최선의 코드 100점!!!
	// => C++11 이후, 쓸만 하지만, 최선은 아님.
	// => move 를 지원할수 없는 setter
//	void set_name(const std::string& n) { name = n; } // 항상 복사
//	void set_name(const std::string& n) { name = std::move(n); } // 항상복사

	// std::move 개념을 완벽히 지원하는 setter 를 만들려면
	// 2개를 제공해야 합니다.
	// => C++11 이후의 "최선의 코드"!!
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }
};
int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);
	p.set_name(std::move(s2));	

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""

	//=========================
	std::vector<std::string> v;
	v.push_back(s1);			// s1 자원 복사
	v.push_back(std::move(s1));	// s1 자원 이동
}
// cppreference.com  에서 std::vector 검색후 push_back








