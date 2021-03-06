// ConsoleApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"MatrixLibrary.h"


int setRows();

int setColumns();

double** allocateMemory(int, int);

void freeMemory(double**, int, int);


int main()
{

	int rows = setRows();
	int cols = setColumns();

	double** matrix = allocateMemory(cols, rows);
	double** matrixB = allocateMemory(cols, rows);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cin >> matrix[i][j];
		}
	}

	MatrixLibrary::buildNewMatrix(matrix, rows, cols, matrixB);
	 
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			std::cout << matrixB[i][j] << ' ';

		std::cout << std::endl;
	}
	freeMemory(matrix, cols, rows);
	freeMemory(matrixB, cols, rows);

	system("pause");
	return 0;
}

int setRows()
{
	int rows;

	while (true)
	{
		std::cout << "Enter the number of matrix's rows:" << std::endl;

		std::cin >> rows;

		if (rows <= 0)
		{
			std::cout << "Incorrect ammount of rows!" << std::endl;
		}

		else
			return rows;
	}
}

int setColumns()
{
	int col;

	while (true)
	{
		std::cout << "Enter the number of columns:" << std::endl;

		std::cin >> col;

		if (col > 0)
		{
			return col;
		}

		else
			std::cout << "Incorrect ammount of columns!" << std::endl;
	}
}

double** allocateMemory(int column, int row)
{
	double** matrix = new double*[row];

	for (int i = 0; i < row; ++i)
	{
		matrix[i] = new double[column];
	}

	return matrix;
}

void freeMemory(double** matrix, int column, int row)
{
	if (matrix == nullptr)
	{
		throw std::invalid_argument("Free memory error!");
	}

	for (int i = 0; i < row; ++i)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}



