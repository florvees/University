#include "Parallelepiped.hpp"
#include <cmath>
#include <iostream>

namespace df
{
    parallelepiped::parallelepiped(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    parallelepiped::~parallelepiped()
    {
        std::cout << "The parallelepiped, which location is " << this << ", just disappeared!" << std::endl;
    }

    int parallelepiped::areas()
    {
        short face_number;
        std::cout << "Which face do you need? \n1.(x and y) \n2.(x and z) \n3.(y and z)" << std::endl;
        std::cin >> face_number;
        switch (face_number)
        {
        case 1:
            return this->x * this->y;
        case 2:
            return this->x * this->z;
        case 3:
            return this->y * this->z;
        }
    }

    int parallelepiped::volume()
    {
        return this->x * this->y * this->z;
    }

    double parallelepiped::diagonal()
    {
        return sqrt(pow(this->x, 2) + pow(this->z, 2) + pow(this->y, 2));
    }
}