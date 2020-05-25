#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
	std::vector<int> vec;
	if (count > 0) {
		vec.resize(count);
		int value {};
		for (size_t i = 0; i < count; ++i) {
			vec[i] = (value += step);
		}
	}
	return vec;
}
