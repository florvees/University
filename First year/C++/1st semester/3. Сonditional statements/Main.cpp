#include <iostream>

int main()
{
	setlocale(LC_ALL,"Russian");

    // ������ 3, ������� 4, 1

    /*
    long long A;
    long long B;
    long long C;
    std::cout << "������� A: ";
    std::cin >> A;
    std::cout << "������� B: ";
    std::cin >> B;
    std::cout << "������� C: ";
    std::cin >> C;
    if (((A + B) % C == 0) && (C % B == 0))
        std::cout << (A + B) / C - C / B << std::endl;
    else if (((A + B) % C == 0) && (C % B != 0))
        std::cout << (A + B) / C + B * C << std::endl;
    else
        std::cout << A - B + C << std::endl;
    */


    // ������ 3, ������� 4, 2

    /*
    unsigned short N;
    std::cin >> N;

    switch (N)
    {
    case 0: std::cout << "��� ������" << std::endl;
        break;
    case 1: std::cout << "������ ������ �����" << std::endl;
        break;
    case 2: std::cout << "������ ������ �����" << std::endl;
        break;
    case 3: std::cout << "�� ��� ���� ����������" << std::endl;
        break;
    default: std::cout << "��� ������ �� ���������" << std::endl;
        break;
    }
    std::cout << N << std::endl;
    */


    // ������ 3, ������� 4, 3

    /*
    short x;
    std::cin >> x;
    std::cout << x << std::endl;
    if (x > 0)
        std::cout << "Positive number" << std::endl;
    else
        std::cout << "Negative number" << std::endl;
    */
}