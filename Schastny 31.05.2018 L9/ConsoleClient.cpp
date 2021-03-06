// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"KMathDLL.h"
#include<fstream>

int* AllocateMemory( int);

void readArr(char* textfile, int length, int* arr);

int getAmmountFromTextFile(char* textfile);

void createArr(int *, int);

void displayArr(int*, int);

void freeMemory(int*);

int setTheAmmount();

char SetSymb();

int main()
{
	char text[15] = "textfile.txt";
	int ammount = getAmmountFromTextFile(text);

	int *arr = AllocateMemory(ammount);
	readArr(text, ammount, arr);

	displayArr(arr, ammount);
	std::cout << std::endl;

	kmath::waningSorting(arr, ammount);
	std::cout << std::endl;

	displayArr(arr, ammount);
	std::cout << std::endl;

	kmath::deletingEqualElem(arr, ammount);
	std::cout << std::endl;

	char symb = SetSymb();

	int secAmm = ammount;

	int *secArr = AllocateMemory(secAmm);
	kmath::creatingNewArr(arr, secArr, ammount,kmath::translateCharInt(symb) , secAmm);

	if (secAmm == 1) std::cout << "There are no  numbers with theese symbol!" << std::endl;
	else
	{
		displayArr(secArr, secAmm);
		std::cout << std::endl;
	}

	freeMemory(arr);
	freeMemory(secArr);

	system("pause");
    return 0;
}

char SetSymb()
{
	char a; 

	while (true)
	{
		std::cout << "Enter the symbol, that you want to find in the array elemets: " << std::endl;

		std::cin >> a;

		if (a >= 'A' && a <= 'F')
			return a;
	}
}

int setTheAmmount()
{
	int i;

	while (true)
	{
		std::cout << "Enter the ammount of elements:" << std::endl;
		std::cin >> i;

		if (i > 0)
			return i;
	}
}

void createArr(int* arr, int numb)
{
	for (int i = 0; i < numb; ++i)
		std::cin >> arr[i];
}

void displayArr(int *arr, int numb)
{
	for (int i = 0; i < numb; ++i)
		std::cout << arr[i] << ' ';
}

int* AllocateMemory( int n)
{
	if (n < 1)
		throw std::invalid_argument("The ammount of elements can't be less than 0! ");

	int *arr = new int[n];

	return arr;
}

void freeMemory(int* arr)
{

	if (arr == nullptr)
	{
		throw std::invalid_argument("The adress of array is null");
	}
	delete[] arr;
}

int getAmmountFromTextFile(char* textfile)
{
	std::ifstream fin(textfile);

	if (!fin.is_open())
	{
		std::cout << "The file is not opened!" << std::endl;

		system("pause");
	}


	int x, length = 0;

	while (!fin.eof())
	{
		fin >> x;
		++length;
	}

	fin.close();

	return length;
}

void readArr(char* textfile, int length, int* arr)
{
	std::ifstream fin(textfile);

	if (!fin.is_open())
	{
		std::cout << "The file is not opened!" << std::endl;

		system("pause");
	}

	for (int i = 0; i < length; ++i)
	{
		fin >> arr[i];
	}

	fin.close();
}
