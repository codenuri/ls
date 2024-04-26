#include <iostream>

template<typename T> class vector 
{
	T* buff;
public:
	vector(std::size_t sz)
	{
		buff = new T[sz]; 
	}
	~vector() { delete[] buff;}
};

// 부분 특수화가 아닌 특수화 (bool 전용)
template<> class vector<bool>
{
	int* buff;
public:
	vector(std::size_t sz)
	{
		buff = new int[(sz / 32) + 1];  // 0 ~ 31 이면 int 1개
										// 32~ 63 이면 int 2개
	}
	~vector() { delete[] buff;}
};

int main()
{
	// 아래 코드를 보고 위 구현을 생각해 보세요. 문제점 찾으세요
	vector<int>  v1(100); 
	vector<bool> v2(100); 
}