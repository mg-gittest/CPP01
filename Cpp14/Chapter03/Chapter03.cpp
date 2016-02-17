// Chapter03.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


#include "chapter03.h"

#include <map>
#include <random>

namespace mg_cpp14 {
	Chapter03::Chapter03()
	{
		// default to a method that returns false
		set_lambda([](double) { return false; });
	}
	Chapter03::~Chapter03()
	{
	}

	std::map<int, int> Chapter03::normalDist(std::size_t count, int mean, int stdDev)
	{
		std::random_device rd;
		// Generate a normal distribution around that mean
		std::mt19937 engine(rd());
		std::normal_distribution<> normal_dist(mean, stdDev);

		auto ret = std::map<int, int>();

		for (size_t i = 0; i < count; ++i) {
			auto val = normal_dist(engine);
			int idx = int(std::round(val));
			++ret[ idx ];
		}

		return ret;
	}

	std::function<int(int)> Chapter03::get_function() const
	{
		return [](int i) { return abs(i); };
	}

	void Chapter03::set_lambda(const std::function<bool(double)>& lambda)
	{
		_stored_lambda = lambda;
	}

	bool Chapter03::call_lamda(double dd)
	{
		return _stored_lambda(dd);
	}
}

