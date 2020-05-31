#pragma once

#include <vector>
#include <memory>

std::vector<std::shared_ptr<int>> generate(int count);
void print(const std::vector<std::shared_ptr<int>>& vsptr);
void add10(const std::vector<std::shared_ptr<int>>& vsptr);
void sub10(int* const sptr);
void sub10(const std::vector<std::shared_ptr<int>>& vsptr);
