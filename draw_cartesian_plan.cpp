// #include "draw_cartesian_plan.h"
#include <array>
#include <iostream>

void draw_cartesian_plan()
{
    std::array<std::array<char, 21>, 11> grid{};

    for (int i{0}; i < grid.size(); ++i)
    {
        std::cout << std::endl;
        for (int j{0}; j < grid[i].size(); j++)
        {

            if (j == 10)
            {

                grid[i][j] = {'|'};
                std::cout << grid[i][j] << " ";
            }
            else if (i == 5)
            {
                grid[i][j] = {'-'};
                std::cout << grid[i][j] << " ";
            }
            else
            {

                grid[i][j] = {'0'};
                std::cout << grid[i][j] << " ";
            }
        }
    }

    std::cout << std::endl;
}