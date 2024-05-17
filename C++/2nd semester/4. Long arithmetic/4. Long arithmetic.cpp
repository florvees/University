#include <iostream>
#include <string>

namespace df 
{
    class BigInt 
    {
    private:
        int* data;
        int data_size;
        bool is_negative;
    public:
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

            //memcpy(this->data, other.data, data_size * sizeof(int));

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
        bool operator<(BigInt& other) 
        {
            if (this->is_negative != other.is_negative)
                return this->is_negative;
            if (this->is_negative)
            {
                if (this->data_size > other.data_size)
                    return true;
                for (int i = 0; i < data_size; i++)
                {
                    if (this->data[i] > other.data[i])
                    {
                        return true;
                    }
                }
            }
            else
            {
                if (this->data_size < other.data_size)
                    return true;
                for (int i = 0; i < data_size; i++)
                {
                    if (this->data[i] < other.data[i])
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        bool operator>(BigInt& other)
        {
            return other < *this;
        }
        bool operator==(BigInt& other)
        {
            return !(*this < other) && !(other < *this);
        }
        bool operator!=(BigInt& other)
        {
            return !(*this == other);
        }
    };
}

int main()
{
    df::BigInt test("12145");
    df::BigInt cerf("12415");
    if (test < cerf)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
}