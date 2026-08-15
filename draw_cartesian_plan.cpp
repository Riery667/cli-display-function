#include "draw_cartesian_plan.h"
#include "ordered_pair.h"
#include <array>
#include <iostream>

// How i'll resolve the cartesian plan with origin? I thought that I could
//  This function will draw in the terminal the caracters.
std::array<std::array<char, 25>, 25> draw_cartesian_plan(std::vector<ordered_pair> points)
{
    // The use of the array was becasue my grid will have fixed lenght.
    // But this might be a error, because if I wanna zoom in the cartesian?
    // Each i is a column, and the j is the line.
    // i = Column
    // j = line
    std::array<std::array<char, 25>, 25> grid{};

    int x_origin{grid.size() / 2};
    int y_origin{grid[0].size() / 2};

    for (int i{0}; i < grid.size(); ++i)
    {
        std::cout << std::endl;

        for (int j{0}; j < grid[i].size(); j++)
        {
            // if (i == 2)
            // {
            //     grid[i][j] = 'M';
            // }

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

    // print out the points in graph
    // grid[x][y] = *
    std::cout << std::endl << points.size() << std::endl;
    std::cout << std::endl << grid.size() << std::endl;
    std::cout << std::endl << grid[0].size() << std::endl;
    for (int i{0}; i < points.size(); ++i)
    {

        // todo: do not undested this line very well.
        int x_value{x_origin + 1 - points[i].x};
        int y_value{y_origin + 1 - (points[i].y)};

        if ((x_value || y_value) < 0 || x_value > grid.size() || y_value > grid[0].size())
        {
            continue;
        }
        // else if (i == 0)
        //     grid[y_value][x_value] = '0';
        // else if (i == points.size())
        //     grid[y_value][x_value] = 'U';
        // else
        grid[y_value][x_value] = '*';

        // if (y_origin + point[i].y > grid.size() / 2)

        //     std::cout << "point y: " << point[i].y << " bigger than the graph Y max size "
        //               << grid.size() << "\n";

        // else if (y_origin + point[i].y < 0)

        //     std::cout << "point y: " << point[i].y << " small than the graph Y\n";

        // else if (x_origin + point[i].x > grid[0].size() / 2)

        //     std::cout << "point X: " << point[i].y << " bigger than the graph X max size "
        //               << grid[0].size() << "\n";
        // else if (x_origin + point[i].x < 0)

        //     std::cout << "point X: " << y_origin + point[i].y << " small than the graph Y\n";

        // else
    }

    // print out the chars in the graph
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