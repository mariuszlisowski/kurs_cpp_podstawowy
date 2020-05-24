#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
	int sum {};
	for (auto e : numbers) {
		if (!(e % 2))
			sum += e;
	}
	return sum;
}
