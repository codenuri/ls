// 가변인자 클래스 템플릿

// 가변인자 클래스 템플릿 - C++11
// => 템플릿 타입인자를 몇개라도 전달할수 있다.
// => 전형적으로 사용되는 패턴 이 있습니다. 패턴만 알아 두면 됩니다.
template<typename ... T> class tuple 
{
};

int main()
{
	tuple<int> t1;
	tuple<int, int> t2;
	tuple<int, int, double> t3;
	tuple<> t0;
}
