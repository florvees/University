# include "Functions.h"

namespace df
{
	void write(int matrix[100][100], int n)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				std::cin >> matrix[i][j];
	}

	void read(int matrix[100][100], int n)
	{
		std::cout << "Итоговая матрица:" << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				std::cout << matrix[i][j] << " ";
			std::cout << '\n';
		}
	}

	bool prime(int n)
	{
		int count = 0;
		if (n < 0)
		{
			int n_tmp = n - n * 2;
			n = n_tmp;
		}
		if (n == 0 || n == 1)
			return 0;
		for (int i = 2; i <= sqrt(n); i++)
			if (n % i == 0)
				return 0;
		return 1;
	}

	int min(int matrix[100][100], int n)
	{
		int min = matrix[0][0];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (matrix[i][j] < min)
					min = matrix[i][j];
		return min;
	}

	void change(int matrix[100][100], int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			int p_str = 1;
			int v_str = 1;
			for (int j = 0; j < n; j++)
			{
				p_str *= matrix[i][j];
				v_str *= matrix[i + 1][j];
			}
			if (p_str < v_str)
				std::swap(matrix[i], matrix[i + 1]);
		}
	}

	void check_change(int matrix[100][100], int n)
	{
		int min = df::min(matrix, n);
		short m_count = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (matrix[i][j] == min)
					m_count += 1;
		short p_count = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (df::prime(matrix[i][j]))
					p_count += 1;
		if (m_count >= 2 && p_count >= 2)
			df::change(matrix, n);
	}
}

