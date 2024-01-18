#include <iostream>

int main()
{
	setlocale(LC_ALL,"Russian");

    // Задача 4, вариант 4, 1

   /*
   unsigned int n;
   std::cout << "Сколько всего членов последовательности?" << std::endl;
   std::cin >> n;

   int max = 0;
   int sum = 0;
   int nom = 0;
   std::cout << "Введите элементы последовательности по одному:" << std::endl;
   for (int i = 1; i < n+1; i++) // я решил считать элементы с первого номера
   {
       int x;
       std::cin >> x;
       if ((x % 10 == 0) || (x % 10 == 7))
       {
           sum += x;
           if (x > max)
           {
               nom = i;
               max = x;
           }
       }
   }
   std::cout << "Максимальное число последовательности, оканч. на 0 или на 7 : " << max << std::endl;
   std::cout << "Номер наибольшего числа последовательности, оканч. на 0 или на 7: " << nom << std::endl;
   std::cout << "Сумма элементов, оканч. на 7 или на 0: " << sum << std::endl;
   */

   // Задача 4, вариант 4, 2

   /*
   unsigned int N;
   std::cout << "Введите натуральное число N:" << std::endl;
   std::cin >> N;

   unsigned int check;
   unsigned int sum = 0;
   while (N > 0)
   {
       check = N % 10;
       if (check % 2 != 0)
           sum += check;
       N /= 10;
   }
   std::cout << "Сумма нечетных цифр числа: " << sum << std::endl;
   */

}