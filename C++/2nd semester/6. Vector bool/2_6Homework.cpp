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
        size_t m_byte_lenght;
        size_t m_bit_lenght;
        size_t m_current_size;
    public:
        vector<bool>(size_t lenght)
        {
            m_byte_lenght = lenght / 8;
            m_bit_lenght = lenght % 8;
            m_current_size = 0;
            arr = new char[m_byte_lenght];
            for (int i = 0; i < m_byte_lenght; i++)
            {
                arr[i] = 0b00000000;
            }
        }
        ~vector<bool>()
        {
            delete[] arr;
        }
        size_t size()
        {
            return m_current_size;
        }
        void push_back(bool boolean)
        {
            arr[m_current_size / 8] |= boolean;
            arr[m_current_size / 8] << 1;
            m_current_size++;
        }
        bool operator[](int index)
        {
            char tmp_a = 0b1;    
            tmp_a << index % 8;
            bool value = (arr[index / 8] & tmp_a) >> index % 8;
            return value;
        }
    };
}

int main()  
{
    df::vector<bool> test(8);
    test.push_back(true);
    test.push_back(false);
    test.push_back(true);
    for (int i = 0; i < 8; i++)
    {
        std::cout << test[i];
    }
    std::cout << '\n';
    /*for (int i = 0; i < 18; i++)
    {
        std::cout << (i / 8) << std::endl;
    }*/
}
