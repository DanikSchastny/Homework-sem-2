// ConsoleApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"MatrixLibrary.h"
#include<iostream>


int setSize();

int elementAmmount(int);


int main()
{

	int side = setSize();

	int ammount = elementAmmount(side);

	double* matrix = new double[ammount];

	for (int i = 0; i < ammount; ++i)
	{
		matrix[i] = i + 1;
	}

	Matrix::displayMatrix(matrix, side, ammount);


	std::cout << Matrix::matrixTrace(Matrix::mult(matrix, side, ammount), side);

	delete[] matrix;

	system("pause");
	return 0;
}
int elementAmmount(int size)
{
	int amm = 0;

	for (int i = 0; i <= size; ++i)
	{
		amm += i;
	}

	return amm;
}

int setSize()
{
	int size;

	while (true)
	{
		std::cout << "Enter the size of matrix's side:" << std::endl;

		std::cin >> size;

		if (size <= 0)
		{
			std::cout << "Incorrect ammount" << std::endl;
		}
		else return size;
	}
}


