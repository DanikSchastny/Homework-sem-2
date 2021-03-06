// ConsoleApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"MatrixLibrary.h"

int setRows();

int setColumns();

double** allocateMemory(int, int);

void freeMemory(double**, int, int);

double setAccurancy();


int main()
{

	int rows = setRows();
	int cols = setColumns();

	double** matrix = allocateMemory(cols, rows);

	double** secMatrix = allocateMemory(cols, rows);

	double acc = setAccurancy();

	Matrix::createSinTaylorMatrix(matrix, rows, cols, acc);

	Matrix::createSinMatrix(secMatrix, rows, cols);

	if (Matrix::comparisonMatrix(matrix, secMatrix, rows, cols, acc))
		std::cout << "The matrixies are equal!" << std::endl;
	else std::cout << "The matrixies are not equal!" << std::endl;

	freeMemory(matrix, cols, rows);

	freeMemory(secMatrix, cols, rows);

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

double setAccurancy()
{
	double eps;

	while (true)
	{
		std::cout << "Enter the accurancy:" << std::endl;

		std::cin >> eps;

		if (eps <= 0 || eps >= 1)
			std::cout << "The incorrect ammount of accuracy" << std::endl;

		else
			return eps;
	}
}
