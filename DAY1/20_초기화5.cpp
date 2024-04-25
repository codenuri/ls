#include <vector>
#include <string>
#include <memory>

void goo(std::vector<int> v) {}
void hoo(std::string s) {}

int main()
{
	hoo("hello"); // 논리적으로 맞습니다. 되야 합니다.
				  // 현재 잘됩니다.	
	std::string s1("hello");  // 이렇게 도 사용가능하고
	std::string s2 = "hello"; // 이렇게 도 사용가능
							  // 즉, string(const char*) 생성자는
							  // explicit 가 아닙니다.
	goo(10); 	// 논리적으로 맞지 않습니다. 안되야 합니다. 현재 error
	std::vector<int> v1(10);  // ok
	std::vector<int> v2 = 10; // error.
							  // vector(int) 생성자는 explicit 라는의미

	std::vector<int> v3 = {10};  // ok 
								  // 왜??? 에러가 아닌가요 ??



}





