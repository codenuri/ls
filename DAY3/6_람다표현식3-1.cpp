int main()
{
	// 다음중 에러를 모두 찾으세요
	auto f1        = [](int a, int b) { return a + b;}; // ok
	auto& f2       = [](int a, int b) { return a + b;}; // error
	const auto& f3 = [](int a, int b) { return a + b;}; // ok
	auto&& f4      = [](int a, int b) { return a + b;}; // ok

	// 위 4개중 최선의 코드를 찾으세요.

//	Point  p1 		= Point{1,1}; // Point p1{1,1} 과 동일
//	Point& p2 		= Point{1,1};
//	const Point& p3 = Point{1,1};
//	Point&& p4 		= Point{1,1};
}