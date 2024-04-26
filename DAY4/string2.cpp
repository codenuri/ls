// string1.cpp
#include <string>
#include <string_view>

int main()
{
	std::string s = "to be or not to be";

	// #1. 아래 2줄의 차이점을 이해 하세요 - 복습할때 메모리 그림 그려 보세요
	std::string      ss = s; // 문자열 자원을 깊은복사
	std::string_view sv = s; // sv 가 s 의 문자열 사용(view)
//	sv[0] = 'a'; // error. 읽기만 가능

	// #2. 아래 2줄의 차이점을 이해 하세요. - 정확히 이해 해야 합니다. 어렵습니다.
	std::string      ss1 = "to be or not to be";
						// 힙을 할당해서 문자열을 복사.
						// 즉, 자신이 문자열 소유

	std::string_view sv1 = "to be or not to be";
						// 상수 메모리에 있는 문자열을 가리키기만 함.
						// 자신이 문자열 소유 안함.

	// 참고
	// 프로그램에서 사용하는 모든 문자열 리터럴 은 상수 메모리에 놓여 있습니다
//	printf("abcdefg");	// mov  약속된레지스터, abcdefg 가 있는 상수메모리 주소
						// call printf
}