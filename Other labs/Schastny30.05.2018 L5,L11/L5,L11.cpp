// ConsoleApplication13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


char** createWordsArr(int ammount);

char* createWord(int p);

int setAmmount();

void freeMemory(char**, int);

void displayWordsArr(char** words, int ammount);

int* createRepArr(int ammount);

void setToZero(int* arr, int ammount);

void freeMemory(int*);

char* allocateMemory(char* str);

bool stringCompare(char* str1, char* str2);

void fileScan(char* textfile, char** words, int ammount, int* arr);

void relCheck(char** words, char* str, int* arr, int ammount);

void displayResult(char** words, int* arr, int ammount);


int main()
{
	char textfile[15] = "textfile.txt";
	int ammount = setAmmount();
	char** words = createWordsArr(ammount);

	int* arr = createRepArr(ammount);
	system("cls");
    fileScan(textfile,words, ammount,arr);

	freeMemory(arr);
	freeMemory(words, ammount);

	system("pause");
    return 0;
}

int setAmmount()
{
	int ammount; 

	while (true)
	{
		std::cout << "Enter the ammount of words:" << std::endl;
		std::cin >> ammount;

		if (ammount <= 0) std::cout << "Error! The incorrect ammount of words!" << std::endl;
		else return ammount;
	}
}

char* createWord(int p)
{
	char str[30];

	if(p == 0) std::cin.ignore();

	std::cin.getline(str, 30);

	char* word = new char[strlen(str) + 1];
	strcpy(word, str);

	return word;
}

char** createWordsArr(int ammount)
{
	char** words = new char*[ammount];

	for (int i = 0; i < ammount; ++i)
	{
		std::cout << "Enter the word:" << std::endl;
		words[i] = createWord(i);

	}

	return words;
}

void freeMemory(char** words, int ammount)
{
	for (int i = 0; i < ammount; ++i)
	{
		delete[] words[i];
	}

	delete[] words;
}

void displayWordsArr(char** words, int ammount)
{
	for (int i = 0; i < ammount; ++i)
	{
		std::cout << words[i] << std::endl;
	}
}

int* createRepArr(int ammount)
{
	int* reilretraition = new int[ammount];

	setToZero(reilretraition, ammount);

	return reilretraition;
}

void setToZero(int* arr, int ammount)
{
	for (int i = 0; i < ammount; ++i)
		arr[i] = 0;
}

void freeMemory(int* arr)
{
	delete[] arr;
}



void fileScan(char* textfile, char** words, int ammount, int* arr)
{
	std::ifstream fin(textfile); 
	if (!fin.is_open()) { std::cout << "Error! the file is not opened!" << std::endl; system("pause"); exit(1); }

	char x; int q = 0;
	while (!fin.eof())
	{
		char str[30]; int i = 0, length = 0;
		fin.get(x);

		while (true)
		{
			str[i] = x;
			++i;

			fin.get(x);

			if (x == ' ') break;
			if (x == '\n') { q = 1; }
			if (fin.eof()) break;
		}

		char* substr = allocateMemory(str);
		
		relCheck(words, substr, arr, ammount);

		if (q == 1 || fin.eof())
		{
			displayResult(words, arr, ammount); 
			setToZero(arr, ammount);
			std::cout << std::endl;
			q = 0;
		}

		delete[] substr;
	}

	fin.close();

}

void displayResult(char** words, int* arr, int ammount)
{
	for (int i = 0; i < ammount; ++i)
	{
		std::cout << words[i] << ' ' << arr[i] << std::endl;
	}
}

char* allocateMemory(char* str)
{
	int  length = 0, j = 0;
	while (true)
	{
		if (str[j] >= 65 && str[j] <= 91 || str[j] >= 97 && str[j] <= 122)
		{
			length++;
			++j;
		}

		else break;


	}
	char* substr = new char[length + 1];

	for (int i = 0; i <= length; ++i)
	{
		substr[i] = str[i];
		if (i == length) substr[i] = '\0';
	}

	return substr;
}

void relCheck(char** words, char* str, int* arr, int ammount)
{
	for (int i = 0; i < ammount; ++i)
	{
		if (stringCompare(words[i], str)) ++arr[i];
	}
}

bool stringCompare(char* str1, char* str2)
{
	if (strlen(str1) != strlen(str2)) return false;

	for (int i = 0; i < strlen(str1); ++i)
		if (str1[i] != str2[i])
			return false;

	return true;
}