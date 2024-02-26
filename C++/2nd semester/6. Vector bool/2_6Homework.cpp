#include <iostream>

namespace df
{
    template<typename T>
    class vector
    {
    private:
    public:
    };

    template<>
    class vector<bool>
    {
    private:
        char* arr;
        size_t byte_lenght;
        size_t bit_lenght;
    public:
        vector<bool>(size_t lenght)
        {
            byte_lenght = lenght / 8;
            bit_lenght = lenght % 8;
            arr = new char[byte_lenght];
        }
        ~vector<bool>()
        {
            delete[] arr;
        }
        size_t byte_getter()
        {
            return byte_lenght;
        }
        size_t bit_getter()
        {
            return bit_lenght;
        }
    };
}

int main()  
{

}
