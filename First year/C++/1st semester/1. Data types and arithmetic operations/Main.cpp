#include <iostream>

int main()
{
	setlocale(LC_ALL,"Russian");

	unsigned long long h;
	unsigned long long a;
	std::cout << "������:";
	std::cin >> h;
	std::cout << "���������:";
	std::cin >> a;
	float s = 0.5*h*a;
	std::cout << s << std::endl;
}