#include <iostream>

class string
{
private:
    char* str;
    size_t lenght;
public:
    string(const char* s)
    {
        lenght = strlen(s)+1;
        str = new char[lenght];
        std::copy(s, s + lenght, str);
    }
    string(const string& other)// : string(other.str)
    {
        lenght = other.lenght;
        str = new char[lenght];
        std::copy(other.str, other.str + lenght, str);
    }
    ~string()
    {
        delete[] str;
    }

    string& operator=(string copy)
    {
        delete[] str;

        lenght = copy.lenght;
        str = new char[lenght];
        std::copy(copy.str, copy.str + lenght, str);

        return *this;
    }

    string& operator+=(const string& other)
    {
        string tmp(*this);

        delete[] str;
        lenght += other.lenght;
        str = new char[lenght];
        std::copy(tmp.str, tmp.str + tmp.lenght, str);
        strcat_s(str, lenght, other.str);

        return *this;
    }

    string operator+(const string& other)
    {
        string tmp(*this);
        tmp += other;
        return tmp;
    }

    char& operator[](int index)
    {
        return str[index];
    }

    bool operator==(const string& other)
    {
        if (lenght != other.lenght)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < lenght; i++)
            {
                if (str[i] != other.str[i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator>(const string & other)
    {
        if (lenght <= other.lenght)
        {
            return false;
        }
        else if (lenght > other.lenght)
        {
            return true;
        }
        else
        {
            for (int i = 0; i < lenght; i++)
            {
                if (str[i] < other.str[i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator<(const string& other)
    {
        if (lenght >= other.lenght)
        {
            return false;
        }
        else if (lenght < other.lenght)
        {
            return true;
        }
        else
        {
            for (int i = 0; i < lenght; i++)
            {
                if (str[i] > other.str[i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    char& at(int index)
    {
        if (index > lenght-1)
        {
            std::cout << "Invalid index! The lenght of the string is - " << lenght << ". You tried - " << index << std::endl;
            exit(1);
        }
        else
        {
            return str[index];
        }
    }

    int find(char letter)
    {
        for (int i = 0; i < lenght; i++)
        {
            if (str[i] == letter)
            {
                return i;
            }
        }
        exit(1);
    }

    size_t length()
    {
        return lenght;
    }

    void c_str()
    {
        std::cout << &str << std::endl;
    }
    

    friend std::iostream& operator>>(std::iostream& in, const string& other);
    friend std::ostream& operator<<(std::ostream& out, const string& other);
};

std::iostream& operator>>(std::iostream& in, const string& other)
{
    std::cin >> other.str;
    return in;
}

std::ostream& operator<<(std::ostream& out, const string& other)
{
    out << other.str;
    return out;
}

int main()
{
    string test1 = "abc";
    string test2 = "def";
    string test3 = "ghi";

    std::cout << test1 << std::endl;
    std::cout << test2 << std::endl;
    std::cout << test1 + test2 << std::endl;

    test1 = test2 + test3;

    std::cout << test1 << std::endl;
    std::cout << test1.find('g') << std::endl;
    std::cout << test1.length() << std::endl;

    if (test1 > test2)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    if (test1 == test2)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    if (test1 < test2)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    test1.c_str();
    test1.at(8);
}
