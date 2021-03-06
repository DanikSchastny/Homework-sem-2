// MatrixLibrary.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"

#include"MatrixLibrary.h"


MATRIXLIBRARY_API double Matrix::redictionFormule(double term)
{
	while (term >= 2 * 3.1415)
	{
		term -= 2 * 3.1415;
	}

	return term;
}

MATRIXLIBRARY_API double Matrix::sinTaylor(double value, double accurancy)
{
	if (accurancy < 0.0 || accurancy >= 1)
	{
		throw std::invalid_argument("Incorrect accurancy");
	}

	double term = value, sum = 0;

	for (int i = 1; fabs(term) > accurancy; i++)
	{
		sum += term;
		term = -term * value * value / (2 * i) / (2 * i + 1);
	}

	return sum;
}

MATRIXLIBRARY_API void Matrix::createSinTaylorMatrix(double** matrix, int rows, int cols, double accur)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (j == i)
				matrix[i][j] = j;

			else matrix[i][j] = (Matrix::sinTaylor(Matrix::redictionFormule(i*j), accur) + i + 1) / pow(1 + j, 3);
		}

	}
}

MATRIXLIBRARY_API void Matrix::createSinMatrix(double ** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (j == i)
				matrix[i][j] = j;

			else matrix[i][j] = (sin(Matrix::redictionFormule(i*j)) + i + 1) / pow(1 + j, 3);
		}
	}
}

MATRIXLIBRARY_API bool Matrix::comparisonMatrix(double** taylorMatrix, double** libraryMatrix, int rows, int cols, double acc)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (fabs(taylorMatrix[i][j] - libraryMatrix[i][j]) > acc)
				return false;
		}
	}

	return true;
}

