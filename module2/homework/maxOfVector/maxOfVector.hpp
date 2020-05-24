#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
	int max {std::numeric_limits<int>::min()};
	for (auto e : vec) {
		if (e > max)
			max = e;
	}
	return max;
}
