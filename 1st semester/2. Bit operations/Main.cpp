#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	unsigned int x;
	unsigned int i;
	std::cout << "�������� ����� � 10-�� ��:";
	std::cin >> x;
	std::cout << "���������� ���:";
	std::cin >> i;
	x &= (~(1 << i));
	std::cout << x << std::endl;
}