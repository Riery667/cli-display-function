#include "draw_cartesian_plan.h"
#include "ordered_pair.h"
#include <array>
#include <iostream>

// This function will draw in the terminal the caracters.
std::array<std::array<char, 21>, 11> draw_cartesian_plan(std::vector<ordered_pair> point)
{
    // The use of the array was becasue my grid will have fixed lenght.
    // But this might be a error, because if I wanna zoom in the cartesian?
    std::array<std::array<char, 21>, 11> grid{};

    for (int i{0}; i < grid.size(); ++i)
    {
        std::cout << std::endl;

        for (int j{0}; j < grid[i].size(); j++)
        {
            // draw the vertical line
            if (j == grid[i].size() / 2)
            {
                if (i == 0)
                    grid[i][j] = 'Y';
                else
                    grid[i][j] = '|';
            }

            // draw horizontal line
            else if (i == grid.size() / 2)
            {
                // - 1 because when the j matches the size of it's array, the loop ends
                // so the last index will be size() - 1
                if (j == grid[i].size() - 1)
                    grid[i][j] = 'X';
                else
                    grid[i][j] = '-';
            }
            else
                grid[i][j] = ' ';
            // std::cout << " " << grid[i][j] << " ";
        }
    }

    for (int i{0}; i < point.size(); ++i)
    {
        grid[point[i].x][point[i].y] = '*';
    }

    for (int i{0}; i < grid.size(); ++i)
    {
        std::cout << std::endl;

        for (int j{0}; j < grid[i].size(); j++)
        {
            std::cout << " " << grid[i][j] << " ";
        }
    }

    std::cout << std::endl;
    return grid;
}