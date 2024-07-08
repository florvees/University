﻿#include <iostream>

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
        unsigned char* m_data;
        size_t m_byte_lenght;
        size_t m_bit_lenght;
        size_t m_current_size;
    public:
        vector<bool>(size_t lenght)
        {
            m_byte_lenght = lenght / 8 + 1;
            m_bit_lenght = lenght % 8;
            m_current_size = 0;
            m_data = new unsigned char[m_byte_lenght];
        }
        ~vector<bool>()
        {
            delete[] m_data;
        }
        void push_back(bool boolean)
        {
            m_data[m_current_size / 8] << 1;
            m_data[m_current_size / 8] |= boolean;
            m_current_size++;
        }
        size_t size()
        {
            return m_current_size;
        }
        bool& operator[](size_t index)
        {
            bool value = ((1 << (index % 8)) & (m_data[index / 8])) != 0;
            return value;
        }
    };
}

int main()
{
    df::vector<bool> test(9);
    test.push_back(true);
    test.push_back(false);
    test.push_back(true);
    test.push_back(true);
    test.push_back(true);
    test.push_back(true);
    test.push_back(true);
    test.push_back(true);
    for (int i = 0; i < test.size(); i++)
    {
        std::cout << test[i];
    }
    std::cout << "\n~~~~" << std::endl;
    for (int i = 0; i < test.size(); i++)
    {
        std::cout << test[i];
    }
}