// C++98 초기화문제점 - 54 page
#include <complex>

int main()
{
	// 문제점 1. 변수의 종류에 따라 초기화 방법이 다르다.
	int n1 = 10;
	int n2(10); 	// C는 안되지만 C++은 () 사용가능

	int x[2] = { 1,2 };
	std::complex<double> c(1, 2);

	// 2. 동적할당한 배열(메모리)를 초기화할수 없다.
	int* p = new int[3];

	// 3. STL 컨테이너 사용시, 1,2,3,4,5 등으로 초기화 할수 없다.
	std::vector<int> v(5, 0); // ok. 5개를 0으로 
							  // 1,2,3,4,5로 초기화 할수 있을까 ?
							  // C++98 시절에는 방법이 없다
}
class Test
{
	// 4. 클래스 멤버로 있는 배열을 초기화 할수 없다.
	int x[3];
};



