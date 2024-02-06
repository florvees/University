#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	unsigned int x;
	unsigned int i;
	std::cout << "Исходное число в 10-ой СС:";
	std::cin >> x;
	std::cout << "Изменяемый бит:";
	std::cin >> i;
	x &= (~(1 << i));
	std::cout << x << std::endl;
}