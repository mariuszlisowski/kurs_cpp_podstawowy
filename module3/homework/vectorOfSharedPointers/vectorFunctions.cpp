#include "vectorFunctions.hpp"

#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
	std::vector<std::shared_ptr<int>> vsptr;
	if (count > 0) {
		vsptr.reserve(count);
		for (int i = 0; i < count; ++i) {
			vsptr.push_back(std::make_shared<int>(i));
		}
	}
	return vsptr;
}

void print(const std::vector<std::shared_ptr<int>>& vsptr) {
	for (const auto& e : vsptr)
		std::cout << *e << ' ';
	std::cout << '\n';
}

void add10(const std::vector<std::shared_ptr<int>>& vsptr) {
	for (const auto& e : vsptr) {
		if (e) *e += 10;
	}
}

void sub10(int* const sptr) {
	if (sptr) *sptr -= 10;
}

void sub10(const std::vector<std::shared_ptr<int>>& vsptr) {
	for (const auto& e : vsptr) {
		if (e) sub10(e.get());
	}
}
