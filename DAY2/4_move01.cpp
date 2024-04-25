#include <iostream>
#include <string>
#include <vector>

// move 개념

int main()
{
	std::string s1 = "hello";
	std::string s2 = "hello";

	std::string s3 = s1;	// 복사 생성자 호출(깊은 복사로 구현)							
	std::string s4 = std::move(s2);
							// s2 의 자원을 s4로 이동
							// s2 는 자원을 손실.

	std::cout << s1 << std::endl; // "hello"
	std::cout << s2 << std::endl; // ""


}

