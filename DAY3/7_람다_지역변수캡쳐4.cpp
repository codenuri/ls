#include <iostream>
#include <vector>
#include <algorithm>

struct People
{
	// name, addr
	int age;
	People(int a) : age(a) {}
};

int main()
{
	std::vector<People> v;
	v.emplace_back(10); // v.push_back(People(10)) 와 동일
	v.emplace_back(20);
	v.emplace_back(15);

	int age = 15;
	auto ret = std::find_if(v.begin(), v.end(), 
						[age](const People& p) { return p.age == age;} );
}







