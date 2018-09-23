// Yuchen Shi
// ITP 365, Fall 2018
// LP01
// yuchensh@usc.edu
// Mac

#include <iostream>

// fn = f(n-1) + f(n-2)
unsigned int getFib(unsigned int n)
{
    if (n<2)
    {
        return n;
    }
    else
    {
        unsigned int twoBack = 0;
        unsigned int oneBack = 1;
        int result = 0;
        for (unsigned int i=1; i<n; i++)
        {
            result = oneBack+twoBack;
            //update "back" variables!
            twoBack=oneBack;
            oneBack=result;
        }
        return result;
    }
    
}



int main()
{
    unsigned int toCalc;
    
    // Do I/O
    std::cout << "How many fib numbers do you want?" << std::endl;
    std::cin >> toCalc;
    
    // Display results
    for (unsigned int i = 0; i <= toCalc; i++)
    {
        std::cout << i << " : " << getFib(i) << std::endl;
    }
    
    return 0;
}
