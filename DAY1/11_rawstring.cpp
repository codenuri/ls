// 11_rawstring
#include <iostream>
#include <string>

int main()
{
	// 일반 문자열 : '\' 를 특수 문자로 해석
	std::string s1 = "\\\\.\\pipe\\server";

	// Raw string : '\' 를 특수 문자로 해석하지 말고, 일반 문자로 해석
	std::string s2 = R"(\\.\pipe\server)";

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

	// " 를 표기하려면 그냥 표기하면 된다.
	// 문자열 시작 : "(
	// 문자열 종료 : )"
	std::string s3 = R"(\\.\p"ipe\server)";

	// )" 를 표기하려면
	// => 시작과 끝을 나타내는 토큰을 변경하면 됩니다.
	std::string s4 = R"***(\\.\p)"ipe\server)***";
}





