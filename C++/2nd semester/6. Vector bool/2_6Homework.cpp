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
        size_t size;
    public:
        vector<bool>(size_t lenght)
        {
            byte_lenght = lenght / 8;
            bit_lenght = lenght % 8;
            size_t size = byte_lenght + bit_lenght;
            arr = new char[byte_lenght];
        }
        ~vector<bool>()
        {
            delete[] arr;
        }
        size_t size()
        {
            return size;
        }
        void push_back(bool boolean)
        {

        }
    };
}

int main()  
{

}
