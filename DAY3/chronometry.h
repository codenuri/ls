// chronometry.h 추가해 보세요
#pragma once
#include <iostream>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <functional>

// chronometry() & stop_watch
class stop_watch
{
	std::chrono::system_clock::time_point start;
	bool log_at_finish;
public:
	stop_watch(bool b = false) : log_at_finish(b) { start = std::chrono::system_clock::now(); }
	~stop_watch() { if (log_at_finish) log(); }

	std::chrono::duration<double> stop()
	{
		std::chrono::system_clock::time_point end = std::chrono::system_clock::now();

		return std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	}
	void log()
	{
		std::cout << stop().count() << " seconds." << std::endl;;
	}
};

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg) 
{		
	stop_watch sw(true); 	// 생성자에서 시간 기록, 소멸자에서 다시 시간 구해서출력
							// true : 소멸자에서 수행시간 출력해 달라.		

	return f( std::forward<T>(arg)... ); 
}

