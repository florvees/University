#include <iostream>

int main()
{
	setlocale(LC_ALL,"Russian");

    // ������ 4, ������� 4, 1

   /*
   unsigned int n;
   std::cout << "������� ����� ������ ������������������?" << std::endl;
   std::cin >> n;

   int max = 0;
   int sum = 0;
   int nom = 0;
   std::cout << "������� �������� ������������������ �� ������:" << std::endl;
   for (int i = 1; i < n+1; i++) // � ����� ������� �������� � ������� ������
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
   std::cout << "������������ ����� ������������������, �����. �� 0 ��� �� 7 : " << max << std::endl;
   std::cout << "����� ����������� ����� ������������������, �����. �� 0 ��� �� 7: " << nom << std::endl;
   std::cout << "����� ���������, �����. �� 7 ��� �� 0: " << sum << std::endl;
   */

   // ������ 4, ������� 4, 2

   /*
   unsigned int N;
   std::cout << "������� ����������� ����� N:" << std::endl;
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
   std::cout << "����� �������� ���� �����: " << sum << std::endl;
   */

}