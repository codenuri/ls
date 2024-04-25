// 1_�ʱ�ȭ10
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2{ 1,2,3,4,5 };


	// 아래 2줄의 차이점은 ?
	std::vector<int> v3(10, 2); // 10개를 2로 초기화 v3.size() 는 10
	std::vector<int> v4{10, 2}; // 2개를 10,2로 초기화 v4.size() 는 2


	// 아래 2줄은 다른 생성자 호출
	std::vector<int> v5 = 10;	// error.
								// explicit vector(int) 이므로
	std::vector<int> v6 = {10}; // ok
								// vector(std::initializer_list)생성자
								// 인데, explicit 가 아니다.
}




