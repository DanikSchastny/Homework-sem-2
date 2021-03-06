// MatrixLibrary.cpp: определяет экспортированные функции для приложения DLL.
//

#include"MatrixLibrary.h"
#include "stdafx.h"


MATRIXLIBRARY_API void Matrix::displayMatrix(double* matrix, int side, int ammount)
{
	for (int i = 0, sidePos = 0, l = 0; l < side; ++l, i += l)
	{
		if (l == side - 1)
			for (int j = ammount - side; j <= ammount - 1; ++j)
			{
				std::cout << matrix[j] << ' ';
			}
		else
		{

			if (l == 0 || l == 1)
			{
				for (int j = i, f = 0; f < side; ++f, j += f)
				{
					std::cout << matrix[j] << ' ';
				}
			}
			else for (int j = i, f = 0, q = 0; f < side; ++f, ++q)
			{
				if (q <= l)
				{
					std::cout << matrix[j] << ' ';
					if (q<l) ++j;
				}

				else
				{
					j += (f);

					std::cout << matrix[j] << ' ';
				}
			}
		}

		std::cout << std::endl;
	}
}

MATRIXLIBRARY_API double* Matrix::mult(double* matrix, int side, int ammount)
{
	double term = 0;

	double* newMatrix = new double[ammount];

	for (int i = 0, sidePos = 0, l = 0; l < side; ++l, i += l)
	{
		if (l == side - 1)
			for (int j = ammount - side; j <= ammount - 1; ++j)
			{
				term += matrix[j] * matrix[j];
			}
		else
		{
			if (l == 0 || l == 1)
			{
				for (int j = i, f = 0; f < side; ++f, j += f)
				{
					term += matrix[j] * matrix[j];
				}
			}
			else for (int j = i, f = 0, q = 0; f < side; ++f, ++q)
			{
				if (q <= l)
				{
					term += matrix[j] * matrix[j];
					if (q<l) ++j;
				}

				else
				{
					j += (f);

					term += matrix[j] * matrix[j];
				}
			}
		}

		newMatrix[l] = term;
		term = 0;
	}

	return newMatrix;
}

MATRIXLIBRARY_API double Matrix::matrixTrace(double* arr, int side)
{
	double f = 0;

	for (int i = 0; i < side; ++i)
	{
		f += arr[i];
	}

	delete[] arr;

	return f;
}