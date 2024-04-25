// 19_structure_binding - 52 page
#include <map>
#include <string>

struct Point3D
{
	int x = 0, y = 0, z = 0;
};
int main()
{
	Point3D p3d;

	// 구조체에서 값 꺼내기. util C++14
	int x = p3d.x;
	int y = p3d.y;
	int z = p3d.z;

	// 파이썬 "튜플" 처럼 한줄로 꺼낼수 있습니다.
	// structure binding 이라는 C++17 문법
	auto [a1, a2, a3] = p3d; // 위 3줄과 동일 
							 // a1, a2, a3 라는 3개의 변수를 선언한것
	
//	int [b1, b2, b3] = p3d;  // error. auto 만 가능

//	auto [b1, b2] = p3d;  // error. 갯수가 같아야 합니다.

	// C# 에서는 필요없는 값은 _ 로 가능.
	auto [b1, b2, _ ] = p3d; // 지금은 ok 하지만 _ 는 변수의 이름
							 // 아래서 다시 사용하면 _ 이름의 변수 중복선언

	// 배열도 됩니다.
	int x[3] = {1,2,3};
	auto [c1, c2, c3] = x; // ok

	//-------------------------
	std::map<std::string, std::string> m;

	m["mon"] = "월요일"; // 이한줄은 아래 4줄과 동일합니다.

	// map은 pair를 보관합니다.
	std::pair<std::string, std::string> p;
	p.first = "tue";
	p.second = "화요일";

	m.insert(p);
	//===========================
	// map 의 모든 요소 열거
	for( auto& p : m )
	{
		// p는 맵의 요소이므로 pair 입니다.
		const std::string& key = p.first;
		const std::string& value = p.second;
	}

	// C++17 스타일 - cppreference.com 의 대부분의 예제가 이렇게 되어있습니다.
	for( const auto& [key, value] : m )
	{
	}

}

// 3:25분에 시작합니다.
