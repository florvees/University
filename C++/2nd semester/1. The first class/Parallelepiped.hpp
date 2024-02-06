#pragma once

namespace df
{
    class parallelepiped
    {
    private:
        int x;
        int y;
        int z;
    public:
        parallelepiped(int x, int y, int z);

        ~parallelepiped();

        int areas();

        int volume();

        double diagonal();
    };
}