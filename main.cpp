#include "draw_cartesian_plan.h"
#include "ordered_pair.h"
#include <iostream>
#include <vector>

std::vector<ordered_pair> const_function()
{
    int c{0};
    std::vector<ordered_pair> im{};
    std::cout << "f(x) = c\nChoose the c value.\n";
    std::cin >> c;
    // assuming the lengh of x in the graphic
    for (int i{-10}; i < 30; ++i)

        im.push_back(ordered_pair(i, c));
    return im;
}

int main()
{
    // wellcome_txt();
    bool running{true};

    std::cout << "Wellcome to the Console Display Function!\nCreate by: @Wired_Arka\n";
    std::cin.get();

    while (running)
    {
        std::vector<ordered_pair> im{};
        int choose{0};
        std::cout << "Choose a function below using numbers.\n";
        std::cout << "0 - constant function.\n1 - linear_function\n2 - quadratic_function\n";
        std::cin >> choose;

        switch (choose)
        {
            case 0:
                im = const_function();
                break;
            case 1:
                // im = linear_function() break;
            case 3:
                // im = quadratic_function() break;
            default:
                im = const_function();
        }

        draw_cartesian_plan(im);
    }

    return 0;
}
