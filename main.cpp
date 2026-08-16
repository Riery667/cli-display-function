#include "cartesian_plan.h"
#include "ordered_pair.h"
#include <iostream>
#include <vector>

#define DEBUG_MODE

std::vector<ordered_pair> ConstantFunction()
{
    int c{0};
    std::vector<ordered_pair> im{};
    std::cout << "f(x) = c\nChoose the c value.\n";
#ifdef DEBUG_MODE
    c = 10;
#else
    std::cin >> c;
#endif
    std::cout << "C Value is " << c << std::endl;

    for (int x{-100}; x < 100; ++x)
        im.push_back(ordered_pair(x, c));
    return im;
}

// name come from literal translation of the book "Fundamentos da Matemática Elementar Vol.1"
std::vector<ordered_pair> IdentityFunction()
{
    std::vector<ordered_pair> im{};
    std::cout << "f(x) = x\nPressione alguma tecla para continuar.";
    std::cin.get();
    std::cout << "X Value is X " << std::endl;

    // assuming the lengh of x in the graphic
    for (int x{-100}; x < 100; ++x)

        im.push_back(ordered_pair(x, x));
    return im;
}

std::vector<ordered_pair> LinearFunction()
{
    int a{0};
    std::vector<ordered_pair> im{};
    std::cout << "f(x) = ax\nChoose the 'a' value.\n";

#ifdef DEBUG_MODE
    a = 2;
#else
    std::cin >> a;

#endif
    std::cout << "                                      Linear function" << std::endl;
    std::cout << "                                      f(x) = x*" << a << std::endl;

    // assuming the lengh of x in the graphic
    for (int x{-100}; x < 100; ++x)

        im.push_back(ordered_pair(x, a * x));
    return im;
}

std::vector<ordered_pair> RelatedFunction()
{
    int a{0}; // angular
    int b{0}; // linear
    std::vector<ordered_pair> im{};
    std::cout << "f(x) = ax + b\nChoose the 'a' value.\n";

#ifdef DEBUG_MODE
    a = 2;
#else
    std::cin >> a;

#endif

    std::cout << "Choose the 'b' value.\n";

#ifdef DEBUG_MODE
    b = 5;
#else
    std::cin >> b;

#endif
    std::cout << "                                      Related function" << std::endl;
    std::cout << "                                      f(x) = x*" << a << " + " << b << std::endl;

    // assuming the lengh of x in the graphic
    for (int x{-100}; x < 100; ++x)

        im.push_back(ordered_pair(x, a * x + b));
    return im;
}

int main()
{
    // wellcome_txt();
    bool running{true};

    std::cout << "Wellcome to the Console Display Function!\nCreate by: @Wired_Arka\n";
#ifndef DEBUG_MODE
    std::cin.get();
#endif

    while (running)
    {
        std::vector<ordered_pair> im{};
        int choose{0};
        std::cout << "Choose a function below using numbers.\n";
        std::cout << "0 - ConstantFunction\n1 - IdentityFunction\n2 - LinearFunction\n3 - "
                     "RelatedFunction\n";

#ifdef DEBUG_MODE
        choose = 2;
#else
        std::cin >> choose;

#endif

        switch (choose)
        {
            case 0:
                im = ConstantFunction();
                break;
            case 1:
                im = IdentityFunction();
                break;
            case 2:
                im = LinearFunction();
                break;
            case 3:
                im = RelatedFunction();
                break;
            default:
                im = ConstantFunction();
        }

        CartesianPlan cartesianPlan(30, 30);
        cartesianPlan.PlotGrid();
        cartesianPlan.BuildDots(im);
        cartesianPlan.Draw();

        std::cin >> choose;
    }

    return 0;
}
