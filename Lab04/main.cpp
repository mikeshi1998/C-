// ITP 365 Fall 2018
// LP4 – Money
// Name: Yuchen Shi
// Email: yuchensh@usc.edu
// Platform: Mac

#include <iostream>
#include "money.h"

int main(int argc, char** argv)
{
    Money m1, m2;
    double s;

    std::cout << "Money 1: $";
    std::cin >> m1;
    std::cout << "Money 2: $";
    std::cin >> m2;
    std::cout << "Scaler: ";
    std::cin >> s;

    std::cout << m1 << " + " << m2 << " = " << m1 + m2 << std::endl;
    std::cout << m1 << " - " << m2 << " = " << m1 - m2 << std::endl;
    std::cout << m1 << " * " << s << " = " << m1 * s << std::endl;
    std::cout << m2 << " * " << s << " = " << m2 * s << std::endl;
    std::cout << m1 << " / " << s << " = " << m1 / s << std::endl;
    std::cout << m2 << " / " << s << " = " << m2 / s << std::endl;

    return 0;
}

