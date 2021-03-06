// ConsoleApplication14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>


void fullFirstFile(char* bin1);

int setRows();

int setCols();

void displayFile(char* bin);

void replacingFormFiles(char* bin1, char* bin2, char* bin3);

void copyFile(char* bin1, char* bin2);

int countMatrixes(char* bin);


class Matrix
{
public:

	int getColumn() ;

	int getRow();
	
	int getEl(int row, int col);

	friend std::istream& operator>> (std::istream&, Matrix&);

	friend std::ostream& operator<< (std::ostream&, const Matrix&);

	void setEl(int row, int col, int x);

	Matrix(int rows, int cols);

	Matrix() {}

private:
	void setColumn(int x);

	void setRow(int x);

	int matrix[100][100];
	int column, row;
};

int main()
{

	char binary1[15] = "bin1.bin";  char binary2[15] = "bin2.bin";  char binary3[15] = "bin3.bin";

	std::cout << "Enter the matrixies, to full the first file!" << std::endl;
	fullFirstFile(binary1);

	std::cout << "Enter the matrixies, to full the second file!" << std::endl;
	fullFirstFile(binary2);

	replacingFormFiles(binary1, binary2, binary3);

	std::cout << "The result of 1st file:" << std::endl;
	displayFile(binary1);

	std::cout << std::endl;

	std::cout << "The result of 2nd file:" << std::endl;
	displayFile(binary2);

	std::cout << std::endl;

	std::cout << "the result of 3rd file:" << std::endl;
	displayFile(binary3);

	std::cout << std::endl;

	system("pause");

    return 0;
}

void Matrix::setColumn(int x)
{
	if (x > 0) this->column = x;
	else throw std::invalid_argument("Incorrect size!");
}

void Matrix::setRow(int x)
{
	if (x > 0) this->row = x;

	else throw std::invalid_argument("Incorrect sizes");
}

std::istream& operator>>(std::istream& input,Matrix& _matrix)
{
	int x;
	for (int i = 0; i < _matrix.getRow(); ++i)
	{
		for (int j = 0; j < _matrix.getColumn(); ++j)
		{
			input >> x;

			_matrix.setEl(i, j, x);
		}
	}

	return input;
}

std::ostream& operator<< (std::ostream& output, const Matrix& _matrix)
{
	for (int i = 0; i < _matrix.column; ++i)
	{
		for (int j = 0; j < _matrix.row; ++j)
		{
			output << _matrix.matrix[i][j] << ' ';
		}
		output << std::endl;
	}

	return output;
}

int Matrix::getColumn()
{
	return this->column;
}

int Matrix::getRow()
{
	return this->row;
}

int Matrix::getEl(int row, int col)
{
	if(row < this->getColumn() && col < this->getColumn())
	return this->matrix[row][col];

	else throw std::out_of_range("Incorrect index!");
}

void Matrix::setEl(int row, int col, int x)
{
	if (row < this->getRow() && col < this->getColumn())
		this->matrix[row][col] = x;

	else throw std::out_of_range("Incorrect index!");
}

Matrix::Matrix(int rows, int cols)
{
	this->setColumn(cols);
	this->setRow(rows);
}

void fullFirstFile(char* bin1)
{
	std::ofstream fout(bin1, std::ios::binary | std::ios::trunc);
	if (!fout.is_open())
	{
		std::cout << "The file is not opened!" << std::endl;
		system("pause");
		exit(1);
	}
	while (true)
	{
		std::cout << "Add new matrix? Y/N" << std::endl;
		char x;
		std::cin >> x;

		if (x == 'N') break;

		int r = setRows(), c = setCols();

		Matrix y(r, c);
		std::cin >> y;

		std::cout << y;

		fout.write((char*)&y, sizeof(Matrix));


	}

	fout.close();
}

int setCols()
{
	int col;

	while (true)
	{
		std::cout << "Enter the ammount of coloumns of matrix:" << std::endl;
		std::cin >> col;

		if (col > 0 && col < 100) return col;
	}
}

int setRows()
{
	int row;

	while (true)
	{
		std::cout << "Enter the ammount of rows of matrix:" << std::endl;
		std::cin >> row;

		if (row > 0 && row < 100) return row;
	}
}

void displayFile(char* bin)
{
	std::ifstream fin(bin);
	if (!fin.is_open())
	{
		std::cout << "The file is not opened!" << std::endl;
		system("pause");
		exit(1);
	}

	Matrix y;

	while (fin.read((char*)&y, sizeof(Matrix)))
	{

		std::cout << y << std::endl;
	}

	fin.close();
}

void replacingFormFiles(char* bin1, char* bin2, char* bin3)
{
	char copy1[15] = "copy1.bin"; char copy2[15] = "copy2.bin";

	std::ifstream fin1(bin1, std::ios::binary), fin2(bin2, std::ios::binary);

	std::ofstream fout1(copy1, std::ios::binary), fout2(copy2, std::ios::binary), fout3(bin3, std::ios::binary);
	if (!fin1.is_open() || !fin2.is_open() || !fout1.is_open() || !fout2.is_open() || !fout3.is_open())
	{
		std::cout << "The file is not opened!" << std::endl; system("pause"); exit(1);
	}

	int numb1 = countMatrixes(bin1), numb2 = countMatrixes(bin2);

	Matrix x, y; int j = 0;

	while (numb1 && numb2)
	{
		++j;
		fin1.read((char*)&x, sizeof(Matrix));
		fin2.read((char*)&y, sizeof(Matrix));

		if (j % 2)
		{
			fout2.write((char*)&y, sizeof(Matrix));
			fout2.write((char*)&x, sizeof(Matrix));

			--numb1; --numb2;
		}
		else
		{
			fout2.write((char*)&x, sizeof(Matrix));
			fout2.write((char*)&y, sizeof(Matrix));

			--numb1; --numb2;
		}
	}

	if (numb1 == 0)
	{
		while (numb2)
		{
			Matrix z;
			fin2.read((char*)&z, sizeof(Matrix));

			fout3.write((char*)&z, sizeof(Matrix));

			--numb2;
		}
	}

	else
	{
		while (numb1)
		{
			Matrix z;
			fin1.read((char*)&z, sizeof(Matrix));

			fout1.write((char*)&z, sizeof(Matrix));

			--numb1;
		}
	}


	fin1.close(); fin2.close(); fout1.close(); fout2.close(); fout3.close();

	copyFile(copy1, bin1);
	copyFile(copy2, bin2);

}

void copyFile(char* bin1, char* bin2)
{
	std::ifstream fin(bin1, std::ios::binary);
	std::ofstream fout(bin2, std::ios::binary | std::ios::trunc);

	if (!fin.is_open() || !fout.is_open())
	{
		std::cout << "The file is not opened!" << std::endl;
		system("pause");
		exit(1);
	}

	Matrix t;

	while (fin.read((char*)&t, sizeof(Matrix)))
	{
		fout.write((char*)&t, sizeof(Matrix));
	}

	fin.close(); fout.close();
}

int countMatrixes(char* bin)
{
	std::ifstream fin(bin, std::ios::binary);

	if (!fin.is_open())
	{
		std::cout << "The file is not opened!" << std::endl;
		system("pause");
		exit(1);
	}
	int i = 0;
	Matrix y;
	while (fin.read((char*)&y, sizeof(Matrix)))
	{
		++i;
	}
	fin.close();

	return i;
}
