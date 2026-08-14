#include "ordered_pair.h"
#include <array>
#include <iostream>
#include <vector>
#ifndef DRAW_CARTESIAN_PLAN
#define DRAW_CARTESIAN_PLAN
std::array<std::array<char, 25>, 11> draw_cartesian_plan(std::vector<ordered_pair> point);
#endif
