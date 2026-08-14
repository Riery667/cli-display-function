#include "draw_cartesian_plan.h"
#include "ordered_pair.h"
#include <iostream>
#include <vector>

int main()
{
    // wellcome_txt();
    // choose_function();
    // input_params();

    ordered_pair point1{1, 3};
    ordered_pair point2{-1, 2};

    std::vector<ordered_pair> pointers{point1, point2};

    draw_cartesian_plan(pointers);

    // choose_function_or_params(); <--- could be a conditional?
    return 0;
}
