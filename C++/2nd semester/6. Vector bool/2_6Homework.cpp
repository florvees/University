#include <iostream>
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
    char* data = new char[1];
    size_t length;

    void pop_back()
    {
        char* p = new char[(this->length / 8) - 1];
        std::copy(*&this->data, (*&this->data) + (this->length / 8) - 1, p);
        std::swap(this->data, p);
        delete[]p;
    }

    void push_last(bool val)
    {
        char* p = new char[(this->length / 8) + 1];
        std::copy(*&this->data, *&(this->data) + (this->length / 8), p);
        p[this->length] = (char)val;
        std::swap(this->data, p);
        delete[]p;
    }
public:
    vector<bool>() {
        this->length = 0;
    }

    size_t size() {
        return this->length;
    }

    void push_back(bool value) {
        if (this->length % 8 == 0) {
            this->push_last(false);
        }
        if (value) {
            this->data[this->length / 8] |= (1 << (this->length % 8));
        }
        this->length++;
    }

    void at(bool val, size_t index)
    {
        if ((index > this->length) || (index < 0))
            throw std::out_of_range("Index out of range");
        if (val) this->data[index / 8] |= (1 << (index % 8));
        else this->data[index / 8] &= ~(1 << (index % 8));
    }

    bool& operator[](size_t index)
    {
        bool curr_val = ((1 << (index % 8)) & (this->data[index / 8])) != 0;
        return curr_val;
    }

    void insert(size_t index, bool value) {
        if (index > this->length) {
            throw std::out_of_range("Index out of range");
        }
        push_back(false);
        for (size_t i = this->length - 1; i > index; --i) {
            this->at((*this)[i - 1], i);
        }
        (*this)[index] = value;
    }

    void erase(size_t index) {
        if (index >= this->length) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < this->length - 1; ++i) {
            (*this)[i] = (*this)[i + 1];
        }
        if ((this->length - 1) % 8 == 0) {
            this->pop_back();
        }
        else {
            this->data[this->length / 8] &= ~(1 << ((this->length - 1) % 8));
        }
        this->length--;
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


    std::cout << "~~~~~~~~" << std::endl;
    test.insert(0, true);
    for (size_t i = 0; i < test.size(); ++i)
    {
        std::cout << test[i] << std::endl;
    }
    std::cout << "~~~~~~~~" << std::endl;


    std::cout << "~~~~~~~~" << std::endl;
    test.erase(2);
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