#include <complex>

int main()
{
	int n1 = 10;
	int x1[2] = { 1,2 };
	std::complex<double> c1(1, 2);

	// uniform intialization
	// => 모든 종류의 변수는 한가지 방법({}) 로 초기화 가능하다.
	// => "중괄호 초기화"라고도 부르는 문법
	int n2 = {10};
	int x2[2] = { 1,2 };
	std::complex<double> c2 = {1, 2};	

	// = 이 없어도 됩니다.
	int n3 {10};
	int x3[2] { 1,2 };
	std::complex<double> c3 {1, 2};	

	// direct initialization : = 없는 것
	// copy   initialization : = 있는 것
}












