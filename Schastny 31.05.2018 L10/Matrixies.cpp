// ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#include"MatrixClass.h"


void displayFile(char* textfile);


int main()
{
	char textfile[15] = "textfile.txt";
	displayFile(textfile);

	std::ifstream fin(textfile);
	if (!fin.is_open()) { std::cout << "The file is not opened!" << std::endl; system("pause"); exit(1); }

	system("pause");
	system("cls");

	while (!fin.eof())
	{
		int x;
		fin >> x;

		Matrix y(x, x), z(x, x);
		fin >> y;
		Matrix::buildNewMatrix(y, z);

		std::cout << z;
		std::cout << std::endl;
	}

	fin.close();


	system("pause");
	return 0;
}



void displayFile(char* textfile)
{
	std::ifstream fin(textfile);

	if(!fin.is_open()) { std::cout << "The file is not opened!" << std::endl; system("pause"); exit(1); }

	
	while (!fin.eof())
	{
		int x; fin >> x;
		Matrix y(x, x);

		fin >> y;

		std::cout << y << std::endl;
	}

	fin.close();
}

int setRows();

int setColumns();

double** allocateMemory(int, int);

void freeMemory(double**, int, int);

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