// 10_user_define_literal2
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::literals;  // 표준이 제공하는 사용자 정의 리터럴이 
								// 이 namespace 에 있습니다.
void foo(const char* s) { std::cout << "char*"; }
void foo(std::string s) { std::cout << "string"; }

int main()
{
	foo("hello");  // char*
	foo("hello"s); // std::string operator""s("hello")

	std::chrono::seconds s1(3); // 3초
	auto s2 = 3s; // 위와 동일

	std::chrono::seconds s3 = 1h + 40min + 3s;

	// 현재 스레드 재우기
//	std::this_thread::sleep_for(3); // error

	std::this_thread::sleep_for(std::chrono::seconds(3)); // ok
	std::this_thread::sleep_for(3s); // ok
				
//	std::vector v1{"A", "B", "C"}; // vector<const char*>
//	std::vector v2{"A"s, "B"s, "C"s}; // vector<std::string>
}


