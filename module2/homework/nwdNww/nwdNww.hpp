#pragma once
#include <cmath>

int NWD(int lhs, int rhs) {
	int remainder;
	while (rhs != 0) {
		remainder = lhs % rhs;
		lhs = rhs;
		rhs = remainder;
	}
	return abs(lhs);
}

int NWW(int lhs, int rhs) {
    if (!lhs || !rhs)
		return 0;
	return abs(lhs * rhs / NWD(lhs, rhs));
}
