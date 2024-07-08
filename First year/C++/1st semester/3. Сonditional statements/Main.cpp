#include <iostream>

int main()
{
	setlocale(LC_ALL,"Russian");

    // Задача 3, вариант 4, 1

    /*
    long long A;
    long long B;
    long long C;
    std::cout << "Введите A: ";
    std::cin >> A;
    std::cout << "Введите B: ";
    std::cin >> B;
    std::cout << "Введите C: ";
    std::cin >> C;
    if (((A + B) % C == 0) && (C % B == 0))
        std::cout << (A + B) / C - C / B << std::endl;
    else if (((A + B) % C == 0) && (C % B != 0))
        std::cout << (A + B) / C + B * C << std::endl;
    else
        std::cout << A - B + C << std::endl;
    */


    // Задача 3, вариант 4, 2

    /*
    unsigned short N;
    std::cin >> N;

    switch (N)
    {
    case 0: std::cout << "Все хорошо" << std::endl;
        break;
    case 1: std::cout << "Ошибка чтения файла" << std::endl;
        break;
    case 2: std::cout << "Ошибка записи файла" << std::endl;
        break;
    case 3: std::cout << "Не все поля определены" << std::endl;
        break;
    default: std::cout << "Код ошибки не определен" << std::endl;
        break;
    }
    std::cout << N << std::endl;
    */


    // Задача 3, вариант 4, 3

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