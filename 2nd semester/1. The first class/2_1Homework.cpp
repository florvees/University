
#include <iostream>
#include <cmath>
#include "Parallelepiped.hpp"

int main()
{
    df::parallelepiped a(5, 2, 3);
    std::cout << a.diagonal() << std::endl;
}

