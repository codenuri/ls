// 9_FOLD - 237 page

#include <iostream>

// Fold Expression : 가변인자 템플릿의 pack 안의 모든 요소에
//				     이항 연산을 수행 - C++17
// 4가지 형태 : 모두 ( ) 가 필요
// op : 이항연산자, I : 초기값
// pack op ...      :  (E1 op (E2 op E3))
// pack op ... op I :  (E1 op (E2 op (E3 op I)))

//      ... op pack :  ((E1 op E2) op E3)
// I op ... op pack : (((I  op E1) op E2) op E3)


template<typename ... Types> 
int Sum(Types ... args)
{
	// args    : 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10
	// 원하는작업 : 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10
//	int s = ( args + ... );
	int s = ( args + ... + 0); // 위 작업 끝에 + 0

	return s;
}

int main()
{
//	int n = Sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	int n = Sum();

	std::cout << n << std::endl;
}



