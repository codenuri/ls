#include <unordered_set>

// C 언어 - typedef 
//typedef int DWORD;
//typedef void(*F)(); 

// C++11 using - 아래 2줄은 위 2줄과 동일합니다.
using DWORD = int;
using F = void(*)();

// typedef : type 의 별명만 가능
// using   : type 의 별명 + template 의 별명

int main()
{
	DWORD n; 
	F     f; 
}