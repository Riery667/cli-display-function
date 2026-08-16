#include "ordered_pair.h"
#include <array>
#include <iostream>
#include <string>
#include <vector>
#ifndef CARTESIAN_PLAN
#define CARTESIAN_PLAN
// std::array<std::array<std::string, 25>, 25> CARTESIAN_PLAN(std::vector<ordered_pair> point);
class CartesianPlan
{
  private:
    int column_size;
    int row_size;
    std::vector<std::vector<std::string>> space;
    ordered_pair origin; // define where will be the (0,0) center of the world.

  public:
    CartesianPlan(int x, int y);
    void PlotGrid();
    void Draw();
    void BuildDots(std::vector<ordered_pair> dots);
};
#endif
