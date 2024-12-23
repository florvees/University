﻿#include <iostream>
#include <string>

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
    char* m_data = new char[1];
    size_t m_length;
public:
    vector<bool>() 
    {
        m_length = 0;
    }

    size_t size() 
    {
        return m_length;
    }

    void push_back(bool value) 
    {
        if (m_length % 8 == 0)
        {
            char* tmp = new char[(m_length / 8) + 1];
            std::copy(*&m_data, *&(m_data) + (m_length / 8), tmp);
            tmp[m_length] = (char)value;
            std::swap(m_data, tmp);
            delete[] tmp;
        }
        if (value) 
        {
            m_data[m_length / 8] |= (1 << (m_length % 8));
        }
        m_length++;
    }

    void at(bool val, size_t index)
    {
        if ((index > m_length) || (index < 0))
            throw std::out_of_range("Index out of range");
        if (val) m_data[index / 8] |= (1 << (index % 8));
        else m_data[index / 8] &= ~(1 << (index % 8));
    }

    bool& operator[](size_t index)
    {
        bool curr_val = ((1 << (index % 8)) & (m_data[index / 8])) != 0;
        return curr_val;
    }

    void insert(size_t index, bool value) 
    {
        if (index > m_length) 
        {
            throw std::out_of_range("Index out of range");
        }
        push_back(false);
        for (size_t i = m_length - 1; i > index; --i) 
        {
            at((*this)[i - 1], i);
        }
        (*this)[index] = value;
    }

    void erase(size_t index) {
        if (index >= m_length) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < m_length - 1; ++i) 
        {
            (*this)[i] = (*this)[i + 1];
        }
        if ((m_length - 1) % 8 == 0) 
        {
            char* tmp = new char[(m_length / 8) - 1];
            std::copy(*&m_data, (*&m_data) + (m_length / 8) - 1, tmp);
            std::swap(m_data, tmp);
            delete[] tmp;
        }
        else 
        {
            m_data[m_length / 8] &= ~(1 << ((m_length - 1) % 8));
        }
        m_length--;
    }
};

int main()
{
    vector<bool> test;

    std::cout << "~~~~~~~~" << std::endl;
    test.push_back(true);
    std::cout << test[0] << std::endl;
    test.push_back(false);
    std::cout << test[1] << std::endl;
    std::cout << "~~~~~~~~" << std::endl;

    test.insert(0, true);
    std::cout << ".insert(0, true)" << std::endl;

    std::cout << "~~~~~~~~" << std::endl;
    for (size_t i = 0; i < test.size(); ++i)
    {
        std::cout << test[i] << std::endl;
    }
    std::cout << "~~~~~~~~" << std::endl;

    test.erase(2);
    std::cout << ".erase(2)" << std::endl;

    std::cout << "~~~~~~~~" << std::endl;
    for (size_t i = 0; i < test.size(); ++i)
    {
        std::cout << test[i] << std::endl;
    }
    std::cout << "The current size of vector is: " << test.size() << std::endl;
    std::cout << "~~~~~~~~" << std::endl;

    std::cout << "~~~~~~~~" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        test.push_back(true);
    }
    for (size_t i = 0; i < test.size(); ++i)
    {
        std::cout << test[i] << std::endl;
    }
    std::cout << "~~~~~~~~" << std::endl;

    return 0;
}