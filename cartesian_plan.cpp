#include "cartesian_plan.h"
#include "ordered_pair.h"
#include <array>
#include <iostream>
#include <string>

CartesianPlan::CartesianPlan(int x, int y)
{
    row_size = x;
    column_size = y;

    // Define minimal domain
    if (row_size < 3)
        row_size = 3;
    if (column_size < 3)
        column_size = 3;

    // Center the origin
    // Example 6 rows. it cannot be in 3.
    // 0,1,2,3,4,5
    // 0,1,2,3,4
    //     ^      (this is a arrow)
    // It will be 2.
    if (row_size % 2 == 0)
        row_size--;
    if (column_size % 2 == 0)
        column_size--;

    // todo I can make this a feature, where you can just edit the origin whataver you like.
    origin = {column_size / 2, row_size / 2};
    space.resize(row_size, std::vector<std::string>(column_size));
}

void CartesianPlan::PlotGrid()
{
    for (int row{0}; row < space.size(); ++row)
    {
        for (int col{0}; col < space[row].size(); ++col)
        {
            if (origin.x == col && origin.y == row)
            {
                space[row][col] = "—┼—";
                continue;
            }

            if (row == origin.y)
            {
                if (col == space[row].size() - 1)
                {
                    space[row][col] = " X";
                    continue;
                }
                else if (col == space[row].size() - 2)
                {
                    space[row][col] = ">  ";
                    continue;
                }
                else
                {
                    space[row][col] = "———";
                    continue;
                }
            }

            if (col == origin.x)
            {

                if (row == 0)
                {
                    space[row][col] = " Y ";
                    continue;
                }

                else if (row == 1)
                {
                    space[row][col] = " ^ ";
                    continue;
                }

                space[row][col] = " │ ";
                continue;
            }

            int ratio{1};
            // blank space
            if (row % ratio == 0 && col % ratio == 0)
            {
                space[row][col] = " · ";
                continue;
            }

            space[row][col] = "   ";
        }
    }
}

void CartesianPlan::BuildDots(std::vector<ordered_pair> dots)
{
    // int f = dots.size();
    for (int i{0}; i < dots.size(); ++i)
    {

        // (0,0) is top left.
        int column = origin.x + dots[i].x;
        // Y is the difference btween the (row origin) and (dot.y).
        // The difference makes the *(dot) go up, and the sum make it dive deeper in the plan.
        int row = origin.y - dots[i].y;

        // Warrant that the dots will only target the graph, not outside of it.
        if (row >= row_size || column >= column_size)
            continue;
        if (column < 0 || row < 0)
            continue;

        // space[y][x]
        space[row][column] = " * ";
    }
}

void CartesianPlan::Draw()
{
    std::cout << std::endl;
    for (int i{0}; i < row_size; ++i)
    {
        for (int j{0}; j < column_size; ++j)
        {
            std::cout << space[i][j];
        }
        std::cout << std::endl;
    }
}
