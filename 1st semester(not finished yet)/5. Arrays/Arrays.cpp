
#include <iostream>
#include <vector> 

int main()
{

    setlocale(LC_ALL, "Rus");

    // Вариант 4, задача 5, 1

    /*
    const short N = 10000;
    int mas[N];
    unsigned short n;
    bool fin_check = 0;

    std::cout << "Сколько всего элементов последовательности?" << std::endl;
    std::cin >> n;
    std::cout << "Введите элементы последовательности по одному:" << std::endl;

    for (int i = 0; i < n; i++)
        std::cin >> mas[i];

    for (int i = 0; i < n; i++)
    {
        int del_check = 0;
        if (del_check == 0)
            for (int k = 2; k <= sqrt(mas[i]) + 1; k++)
                if ((mas[i] % k) == 0)
                    del_check += 2; //ищет делители числа
        if (del_check == 0) //делителей кроме 1 и числа нет - дает сигнал что простое
            fin_check += 1;
    }
    if (fin_check == 0)
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (mas[i] < mas[j])
                    std::swap(mas[i], mas[j]);
    }
    for (int i = 0; i < n; i++)
        std::cout << mas[i] << std::endl;
    */

    // Вариант 4, задача 5, 2

    /*
    const int N = 10000;
    int mas[N];
    unsigned int n;

    std::cout << "Сколько всего элементов последовательности?" << std::endl;
    std::cin >> n;
    std::cout << "Введите элементы последовательности по одному:" << std::endl;
    for (int i = 0; i < n; i++)
        std::cin >> mas[i];



    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            short digiti1;
            short digitj1;

            short tempi = mas[i];
            short tempj = mas[j];
            while (tempi > 99)
                tempi /= 10;
            digiti1 = tempi / 10;
            while (tempj > 99)
                tempj /= 10;
            digitj1 = tempj / 10;
            if (digiti1 > digitj1)
                std::swap(mas[i], mas[j]);
            else if (digiti1 == digitj1)
            {
                unsigned int check;
                short tempi = mas[i];
                short tempj = mas[j];
                short min_digiti = 9;
                short min_digitj = 9;
               
                check = 0;
                while(tempi > 0)
                {
                    check = tempj % 10;
                    if (check < min_digiti)
                        min_digiti = check;
                    tempi /= 10;
                }
                check = 0;
                while (tempj > 0)
                {
                    check = tempj % 10;
                    if (check < min_digitj)
                        min_digitj = check;
                    tempj /= 10;
                }
                if (min_digiti > min_digitj)
                    std::swap(mas[i], mas[j]);
                if (min_digiti == min_digitj)
                    if (mas[i] > mas[j])
                        std::swap(mas[i], mas[j]);
            }
            
        }
    for (int i = 0; i < n; i++)
        std::cout << mas[i] << std::endl;

    */

    // Вариант 4, задача 5, 3
    
    /*
    const int N = 100;
    int matrix[N][N];
    int sum[100]; //тут храню все суммы строк
    unsigned short n;
    unsigned short m;
    std::cout << "Введите кол-во строк:" << std::endl;
    std::cin >> n;
    std::cout << "Введите кол-во столбцов:" << std::endl;
    std::cin >> m;
    std::cout << "Введите матрицу:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        int pre_sum = 0;
            for (int j = 0; j < m; j++)
            {
                std::cin >> matrix[i][j];
                pre_sum += matrix[i][j];
                sum[i] = pre_sum;
            }  
    }
    int min = sum[0];
    int min_index; // для запоминания индекса строки с наименьш. суммой
    for (int i = 0; i < n; ++i)
    {
        if (sum[i] < min)
        {
            min = sum[i];
            min_index = i;
        }
            
    }
    for (int j = 0; j < m; j++)
        matrix[min_index][j] = min;

    std::cout << "Итоговая матрица: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << matrix[i][j] << " "; //решил красиво вывести
        std::cout << std::endl;
    }
    */
    
    // Вариант 4, задача 5, 4

    /*
    std::vector<int> mas;
    unsigned short n;   
    std::cout << "Сколько элементов в последовательности?" << std::endl;
    std::cin >> n;
    std::cout << "Введите элементы последовательности по одному:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        int elem;
        std::cin >> elem;
        mas.push_back(elem);
    }
    for (int i = 0; i < n; i++)
    {
        int dig = mas[i];
        int pal_dig = 0;
        while (dig != 0) // алгоритм создания палидрома 
        {
            pal_dig *= 10;
            pal_dig += dig % 10;
            dig /= 10;
        }
        if (pal_dig == mas[i])
        {
            mas.erase(mas.begin() + i);
            n -= 1;
        }
    }
    int n_temp = n;
    for (int i = 0; i < n_temp; i++)
    {
        int del_check = 0;
        if (del_check == 0)
            for (int k = 2; k <= sqrt(mas[i]) + 1; k++)
                if ((mas[i] % k) == 0)
                    del_check += 2;
        if (del_check == 0)
        {
            mas.push_back(mas[i]);
            n += 1;
        }
    }
    std::cout << "Результат:" << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << mas[i] << std::endl;
    */

}

