// MatrixLibrary.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include"MatrixLibrary.h"

MATRIXLIBRARY_API double MatrixLibrary::findMaxEl(double** matrix, int rows, int cols, int rowsPosition, int colsPosition)
{
	double maxEl = matrix[rowsPosition][colsPosition];

	if (colsPosition == 0)
	{
		for (int i = rowsPosition, iPos = 0; i < rows; ++i, ++iPos)
		{
			for (int j = 0; j <= iPos; ++j)
			{
				if (matrix[i][j] > maxEl)
					maxEl = matrix[i][j];
			}
		}
	}

	if (rowsPosition == rows - 1)
		return matrix[rowsPosition][colsPosition];

	if (colsPosition == rows - 1)
	{

		for (int i = rowsPosition; i < rows; ++i)
		{
			for (int j = cols - 1; j >= cols - 1 - i; --j)
			{
				if (matrix[i][j] > maxEl)
					maxEl = matrix[i][j];
			}
		}
	}

	if (colsPosition > 0 && colsPosition < rows - 1)
	{
		for (int i = rowsPosition, iPos = 0; i < rows; ++i, ++iPos)
		{

			if (i == rowsPosition)
			{
				if (matrix[i][i] > maxEl)
					maxEl = matrix[i][i];
			}

			else
			{
				int left = colsPosition, right = colsPosition;

				if (left - 1 <= 0)
					left = 0;
				else left -= 1;

				if (right + 1 >= cols - 1)
					right = cols - 1;
				else right += 1;

				for (int j = left; j <= right; ++j)
				{
					if (matrix[i][j] > maxEl)
						maxEl = matrix[i][j];
				}

			}
		}
	}

	return maxEl;
}


MATRIXLIBRARY_API void MatrixLibrary::buildNewMatrix(double** matrixA, int rows, int cols, double** matrixB)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			matrixB[i][j] = findMaxEl(matrixA, rows, cols, i, j);
		}
	}
}
