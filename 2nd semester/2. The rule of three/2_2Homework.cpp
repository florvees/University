#include <iostream>
#include <string>

class Matrix
{
private:
    int row_amount;
    int column_amount;
    int** matrix;
public:
    Matrix(int row_amount, int column_amout)
    {
        this->row_amount = row_amount;
        this->column_amount = column_amout;
        matrix = new int*[row_amount];
        for (int i = 0; i < row_amount; i++)
        {
            matrix[i] = new int[column_amout];
        }
    }
    Matrix(const Matrix& other)
    {
        this->row_amount = other.row_amount;
        this->column_amount = other.column_amount;
        matrix = new int* [row_amount];
        for (int i = 0; i < row_amount; i++)
        {
            matrix[i] = new int[row_amount];
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < row_amount; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    Matrix& operator=(const Matrix& other)
    {
        for (int i = 0; i < row_amount; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        this->row_amount = other.row_amount;
        this->column_amount = other.column_amount;
        matrix = new int* [other.row_amount];

        for (int i = 0; i < other.row_amount; i++)
        {
            matrix[i] = new int[other.row_amount];
        }

        for (int i = 0; i < other.row_amount; i++)
        {
            for (int j = 0; j < column_amount; j++)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }

        return *this;
    }

    int& operator()(int row, int column)
    {
        return matrix[row][column];
    }

    /*Matrix operator+(Matrix other)
    {
        if (this->row_amount != other.row_amount || this->column_amount != other.column_amount)
        {
            std::cout << "You cannot do this action!" << std::endl;
            return *this;
        }
        else
        {
            Matrix tmp(row_amount, column_amount);
            tmp.row_amount = this->row_amount;
            tmp.column_amount = this->column_amount;

            for (int i = 0; i < tmp.row_amount; i++)
            {
                for (int j = 0; j < tmp.column_amount; j++)
                {
                    tmp(i,j) = this->matrix[i][j] + other.matrix[i][j];
                }
                std::cout << std::endl;
            }

            tmp.read();

            return tmp;
        }
    }*/

    /*Matrix operator-(const Matrix other)
    {
        if (this->row_amount != other.row_amount || this->column_amount != other.column_amount)
        {
            return *this;
        }
        else
        {
            Matrix tmp = *this;

            for (int i = 0; i < tmp.row_amount; i++)
            {
                for (int j = 0; j < tmp.column_amount; j++)
                {
                    tmp.matrix[i][j] = this->matrix[i][j] - other.matrix[i][j];
                }
                std::cout << std::endl;
            }
            return tmp;
        }
    }*/

    void read()
    {

        for (int i = 0; i < row_amount; i++)
        {
            for (int j = 0; j < column_amount; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void set_values()
    {
        for (int i = 0; i < row_amount; i++)
        {
            for (int j = 0; j < column_amount; j++)
            {
                std::cin >> matrix[i][j];
            }
        }
    }

};

int main()
{
    Matrix a(2, 2);
    a.set_values();
    Matrix b(2, 2);
    b.set_values();

    a.read();

    a = b;

    a.read();

    return 0;
}
