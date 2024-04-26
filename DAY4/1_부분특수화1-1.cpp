#include <vector>
#include <list>

/*
void print_first_element(std::vector<int>& c)
{
	// 컨테이너 c 의 첫번째 요소를 꺼내고 싶다.
	int n = c.front();
}
*/
/*
template<typename T>
void print_first_element(std::vector<T>& c)
{
	T n = c.front();
}
*/
template<typename T>
void print_first_element(T& c)
{	
	// T             : std::list<double>
	// T::value_type : std::list<double>::value_type => double

	typename T::value_type n = c.front();
	auto n1 = c.front(); // 위 코드 대신 이렇게 하면 됩니다.
						// 하지만 아래 같은 코드에서는 auto 를 사용할수 없습니다.

	// c가 저장하는 요소와 같은 요소를 담을수 있는 list 를 만들고 싶다.
//	std::list< auto > s; // error 
	std::list< typename T::value_type > s;

}

int main()
{
//	std::vector<int> c = {1,2,3};
//	std::vector<double> c = {1,2,3};
	std::list<double> c = {1,2,3};

	print_first_element(c);
}
/*
// 템플릿 기반의 컨테이너 사용시 "요소의 타입" 을 알고 싶을때가 있습니다.
// 그래서 STL 아래와 같이 설계 되었습니다.
template<typename T>
class list 
{
public:
	using value_type = T; // 핵심....
	// ....
};
std::list<int> s = {1,2,3};
std::list<int>::value_type n = s.front();
*/


