int main()
{
	auto swap = [](auto& a, auto& b) { auto tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	int n = 10;
	double d = 3.4;

	// 아래 코드가 되는게 좋으세요 ? 안되는게 좋으세요 ?
	swap(n, d); // 안되는게 좋은데, 지금은 됩니다.
				// 2개의인자가 서로 다른 테플릿이므로.

	// 1, 2번째 인자가 같은 타입을 가지도록하고 싶다.!!
	// => C++20 에서 추가된 template 람다.!
	auto swap2 = []<typename T>(T& a, T& b) { T tmp = std::move(a); 
										   a = std::move(b); 
										   b = std::move(tmp); };

	swap2(n, d);	
}