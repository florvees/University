#include <iostream>
#include "Functions.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	int matrix[100][100];
	std::cout << "Введите порядок квадратной матрицы:" << std::endl;
	std::cin>>n;
	std::cout << "Введите элементы квадратной матрицы:" << std::endl;
	df::write(matrix,n);
	df::check_change(matrix, n);
	df::read(matrix,n);
}


