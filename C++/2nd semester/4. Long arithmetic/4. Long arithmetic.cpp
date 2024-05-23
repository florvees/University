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
                    data[i] = value[i + 1] - '0';
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
        BigInt& operator=(const BigInt& other)
        {
            delete[] this->data;

            this->data_size = other.data_size;
            this->is_negative = other.is_negative;
            this->data = new int[data_size];

            for (int i = 0; i < this->data_size; i++)
            {
                this->data[i] = other.data[i];
            }

            return *this;
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
        BigInt operator+(BigInt& other)
        {
            BigInt result;
            if (this->is_negative == other.is_negative) {
                result.data_size = std::max(data_size, other.data_size) + 1;
                result.data = new int[result.data_size];
                int carry = 0;
                for (int i = 0; i < result.data_size; ++i) {
                    int sum = carry;
                    if (i < data_size)
                        sum += this->data[i];
                    if (i < other.data_size)
                        sum += other.data[i];
                    result.data[i] = sum % 10;
                    carry = sum / 10;
                }
                result.is_negative = this->is_negative;
                if (result.data[result.data_size - 1] == 0)
                    --result.data_size;
            }
            else {
                BigInt copy = *this;
                result.data_size = std::max(data_size, other.data_size);
                result.data = new int[result.data_size];
                bool flag = false;
                if (copy.data_size == other.data_size) {
                    for (int i = 0; i < copy.data_size; i++) {
                        if (copy.data[i] > other.data[i]) {
                            flag = true;
                        }
                    }
                }
                if (copy.data_size > other.data_size)
                    flag = true;
                if (flag)
                {
                    for (int i = 0; i < result.data_size; i++)
                    {
                        if (copy.data[i] < 0)
                        {
                            copy.data[i] += 10;
                            copy.data[i + 1] -= 1;
                        }
                        if (i >= other.data_size)
                        {
                            result.data[i] = copy.data[i];
                            continue;
                        }
                        if (copy.data[i] - other.data[i] < 0)
                        {
                            copy.data[i] += 10;
                            copy.data[i + 1] -= 1;
                        }
                        result.data[i] = copy.data[i] - other.data[i];
                    }
                    result.is_negative = (copy.is_negative > other.is_negative);
                }
                else {
                    for (int i = 0; i < result.data_size; i++)
                    {
                        if (other.data[i] < 0)
                        {
                            other.data[i] += 10;
                            other.data[i + 1] -= 1;
                        }
                        if (i >= copy.data_size)
                        {
                            result.data[i] = other.data[i];
                            continue;
                        }
                        if (other.data[i] - copy.data[i] < 0)
                        {
                            other.data[i] += 10;
                            other.data[i + 1] -= 1;
                        }
                        result.data[i] = other.data[i] - copy.data[i];
                    }
                    result.is_negative = (other.is_negative > copy.is_negative);
                    if (result.data[result.data_size - 1] == 0)
                        --result.data_size;
                }
            }
            return result;
        }

        friend std::ostream& operator<<(std::ostream& out, BigInt& other);
        friend std::istream& operator>>(std::istream& in, BigInt& other);
    };

    std::ostream& operator<<(std::ostream& out, BigInt& other)
    {
        if (other.is_negative)
        {
            out << '-';
        }
        for (int i = 0; i < other.data_size; i++)
        {
            out << other.data[i];
        }
        return out;
    }

    std::istream& operator>>(std::istream& in, BigInt& other)
    {
        std::string value;
        in >> value;
        other = BigInt(value);
        return in;
    }

}

int main()
{
    df::BigInt test("15");
    df::BigInt cerf("-18");
    df::BigInt goida(test + cerf);
    std::cout << test << std::endl;
    std::cout << cerf << std::endl;
    std::cout << goida << std::endl;
    test = cerf;
    std::cout << cerf << std::endl;
}