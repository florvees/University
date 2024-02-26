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
            m_byte_lenght = lenght / 8 + 1;
            m_bit_lenght = lenght % 8;
            m_current_size = 0;
            arr = new char[m_byte_lenght];
        }
        ~vector<bool>()
        {
            delete[] arr;
        }
        void push_back(bool boolean)
        {
                arr[m_current_size / 8] << 1;
                arr[m_current_size / 8] |= boolean;
                m_current_size++;
        }
        size_t size()
        {
            return m_current_size;
        }
        bool operator[](int index)
        {
            char tmp_a = 0b00000001;    
            tmp_a << index % 8;
            return (arr[index / 8] & tmp_a) >> index % 8;
        }
    };
}

int main()  
{
    df::vector<bool> test(12);
    test.push_back(true);
    test.push_back(true);
    test.push_back(false);
    test.push_back(true);
    for (int i = 0; i < 12; i++)
    {
        if (test[i] == true)
        {
            std::cout << "True" << std::endl;
        }
        else
        {
            std::cout << "False" << std::endl;
        }
    }
}
