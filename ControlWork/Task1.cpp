﻿// ConsoleApplication9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>

void swap(char& a, char& b);

char fromIntToChar(int);

int enterCountSystem();

void readingTextFile(char* textName, char* binaryName, int base);

void errorFunct();

void displayBinary(char* binaryName, int base);

class Numbers
{
public:
	inline void SetBase(int);

	void SetPnumber();

	inline void SetNumber(int);
	
	Numbers(){}

	Numbers(int base, int number);

	inline int GetBase();

	inline int GetNumber();

	~Numbers() {}

	void display();
private:
	char pnumber[32];
	int number, base;

	static void reverse(char* arr, int size);

};

void Numbers::display()
{
	std::cout << pnumber << ' ' << number << ' ' << base << std::endl;
}

Numbers::Numbers(int base, int number)
{
	this->SetBase(base);
	this->SetNumber(number);
	this->SetPnumber();
}

inline int Numbers::GetBase()
{
	return this->base;
}

inline int Numbers::GetNumber()
{
	return this->number;
}

void Numbers::reverse(char* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			swap(arr[j], arr[j + 1]);
		}
	}
}

inline void Numbers::SetBase(int base)
{
	if (base >= 2 && base <= 16)
		this->base = base;
	else throw std::invalid_argument("Incorrect ammount of base!");
}

inline void Numbers::SetNumber(int number)
{
	this->number = number;
}

void Numbers::SetPnumber()
{
	int j = this->GetNumber() , length = 0;
	while (j > 0)
	{
		pnumber[length] = fromIntToChar(j % this->GetBase());
		j /= this->GetBase();
		length++;
	}

	reverse(pnumber, length);
}

int main()
{
	char text[20] = "numbersList";
	char binary[20] = "binaryList";

	int base = enterCountSystem();

	readingTextFile(text, binary, base);

	displayBinary(binary, base);

    return 0;
}

void swap(char& a, char& b)
{
	char t = a;

	a = b;

	b = t;

}

char fromIntToChar(int x)
{
	if (x >= 0 && x <= 9)
		return x + 48;

	else
		return x + 55;
}

int enterCountSystem()
{
	int k;
	while (true)
	{
		std::cout << "Enter the base of counting system:" << std::endl;
		std::cin >> k;

		if (k >= 2 && k <= 16)
			return k;
	}
}

void readingTextFile(char* textName, char* binaryName, int base)
{
	std::ifstream fin(textName);
	std::ofstream fout(binaryName, std::ios::binary, std::ios::trunc);

	fout.seekp(0, std::ios::beg);

	if (!fin.is_open())
		errorFunct();

	int k;

	while (!fin.eof())
	{
		fin >> k;

		if (k > 0)
		{
			Numbers st(base, k);

			fout.write((char*)&st, sizeof(Numbers));
		}
	}

	fin.close();
	fout.close();
}

void errorFunct()
{
	std::cout << "Error! Can't open the file!" << std::endl;
	system("pause");
	exit(1);
}

void displayBinary(char* binaryName,int base)
{
	std::ifstream fin(binaryName);

	if (!fin.is_open())
	{
		errorFunct();
	}

	while (!fin.eof())
	{
		Numbers st;

		fin.read((char*)&st, sizeof(Numbers));

		st.display();
	}
	
	fin.close();

}

