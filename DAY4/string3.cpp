// string1.cpp
#include <string>
#include <string_view>

void bad ( std::string s)        {}

void good( const std::string& s) {}


void best( std::string_view   s) {}


int main()
{
	std::string s = "to be or not to be";

	// 아래 2줄은 약간의 차이가 있지만 비슷합니다.
	good(s);
	best(s);

	// 문제는 아래 코드 입니다. - 메모리 생각해 보세요
	good("to be or not to be");
	best("to be or not to be");

}
// RUST 의 문자열 타입이 2가지 입니다.
// String   : std::string
// str		: std::string_view