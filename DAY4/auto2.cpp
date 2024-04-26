
int& foo(int& a) { return a;}

int main()
{
	int n = 0;

	auto ret = foo(n); 
//  int  ret = foo(n);	// auto 규칙에서 우변의 reference는 제거되므로

	// decltype(함수 호출식) : 함수 호출 결과로 나오는 타입(반환타입)조사
	decltype( foo(n) ) ret2 = foo(n);
//  int&               ret2 = foo(n);	


	// decltype(auto) : 우변을 auto 자리에 넣어 달라. C++14
	//					또는 우변으로 추론하는데, decltype 규칙으로해달라
	decltype(auto) ret3 = foo(n);
//	int& ret3
}