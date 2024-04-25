#include <iostream>
#include <algorithm> 
// 아래 코드는 비교 정책을 인자화 해서
// 장점 : 유연성이 좋습니다.
// 단점 : 느립니다.
// C 언어의 qsort() 가 사용하는 방식.

// 비교 정책을 교체 할수 있는데, 성능저하 없이(인라인치환) 할수 없을까요 ?
// => 함수 객체 사용하면 가능!!

void Sort(int* x, int sz, bool(*cmp)(int, int)  )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
//			if (x[i] > x[j])		// 1

			if ( cmp( x[i], x[j] ) == false ) // 2
				std::swap(x[i], x[j]);
		}
	}
}
//=================================
inline bool cmp1( int a, int b) { return a < b;}
inline bool cmp2( int a, int b) { return a > b;}

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10, cmp1);
	Sort(x, 10, cmp2);
}

