#include <iostream>
#include <string>

namespace df 
{
    class BigInt 
    {
    public:
        int* data;
        int data_size;
        bool is_negative;
        BigInt() 
        {
            this->data = nullptr;
            this->data_size = 0;
            this->is_negative = false;
        }
        BigInt(const std::string& value)
        {
            if (value[0] == '-')
            {
                is_negative = true;
                data_size = size(value) - 1;
                data = new int[data_size];
                for (int i = 0; i < data_size; i++)
                {
                    data[i] = value[i+1] - '0';
                }
            }
            else
            {
                is_negative = false;
                data_size = size(value);
                data = new int[data_size];
                for (int i = 0; i < data_size; i++)
                {
                    data[i] = value[i] - '0';
                }
            }
        }
        BigInt(const BigInt& other)
        {
            delete[] this->data;

            this->data_size = other.data_size;
            this->is_negative = other.is_negative;
            this->data = new int[data_size];

            for (int i = 0; i < this->data_size; i++)
            {
                this->data[i] = other.data[i];
            }
        }
        ~BigInt()
        {
            delete[] this->data;
            this->data = nullptr;
        }
    };
}

int main()
{
    df::BigInt test("-12345");
    std::cout << test.is_negative << std::endl;
    std::cout << test.data_size << std::endl;
    for (int i = 0; i < test.data_size; i++)
    {
        std::cout << test.data[i];
    }
    std::cout << "\nggggg" << std::endl;

    df::BigInt test2("12415");
    for (int i = 0; i < test2.data_size; i++)
    {
        std::cout << test2.data[i];
    }
    test2 = test;
    std::cout << "\nNew data" << std::endl;
    for (int i = 0; i < test2.data_size; i++)
    {
        std::cout << test2.data[i];
    }
}