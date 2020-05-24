#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {
	std::vector<int> vec;
	if (count > 0) {
		int value {};
		while (count--)
			vec.push_back(value += step);
	}
	return vec;
}
