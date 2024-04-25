// 149
int main()
{
	int v1 = 0, v2 = 0;

	// 캡쳐 모양 정리
	auto f1 = [v1, &v2](int a) { ... };
	auto f2 = [&v1, v2](int a) { ... };

	auto f3 = [=](int a) { ... }; // 모든 지역변수를 값으로 캡쳐
	auto f4 = [&](int a) { ... }; // 모든 지역변수를 참조로 캡쳐

	auto f5 = [=, &v2](int a) { ... }; // v2만 참조, 나머지는 값
	auto f6 = [&,  v2](int a) { ... };
	auto f7 = [&, &v2](int a) { ... }; // error 또는 경고
										// 디폴트 모드와 다른 것만 표기
	
	// 변수의 이름 변경
	auto f8 = [x = v1, &y = v2](int a) { x, y };

	// move 가능
	std::string s = "AAA";
	auto f8 = [s1 = std::move(s)](int a) { s1 사용 };
				// GeneratedName( std::move(s) );

	std::cout << s << std::endl; // "" 
}




