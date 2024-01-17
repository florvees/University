
#include <iostream>
#include <cmath>
#include "Parallelepiped.hpp"

int main()
{
    std::cout << "Please, write the x, y and z values:" << std::endl;

    int x, y, z;
    std::cin >> x >> y >> z;
    df::parallelepiped object(x, y, z);

    bool desire = true;
    while (desire)
    {
        int answer;
        std::cout << "\nType 1, to find areas. Type 2 to find the diagonal. Type 3 to find the volume" << std::endl;
        std::cout << "                           Type 0 to exit\n" << std::endl;
        std::cin >> answer;
        switch (answer)
        {
        case 0:
            desire = false;
            break;
        case 1:
            std::cout << "\nThe area of the parallelepiped equals: " << object.areas() << std::endl;
            break;
        case 2:
            std::cout << "\nThe diagonal of the parallelepiped equals: " << object.diagonal() << std::endl;
            break;
        case 3:
            std::cout << "\nThe volume of the parallelepiped equals: " << object.volume() << std::endl;
            break;
        default:
            std::cout << "\nIncorrect answer. Returning to menu..." << std::endl;
            break;
        }
        
    }
}

