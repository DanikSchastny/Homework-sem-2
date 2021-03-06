// 18.04.2018.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>

void createWordArray(char**, char*,int&);
bool checkForASymb(char);
void addNewWord(char**, char*,int&);
bool checkForBelonging(char**,int, char*);
bool isEqual(char*, char*);
int length(char* );
void strcopy(char*, char*);

int main()
{
	char** words;
	char str[50];
	std::ofstream fin("text.txt");
	if (!fin.is_open())
	{
		exit(1);
	}

	int i = 0;
	while (fin.eof())
	{
		fin << str;
		createWordArray(words, str, i);
	}
    return 0;
}

void createWordArray(char** words, char* substring,int &position)
{
	if (!checkForBelonging(words,position, substring))
	{
		addNewWord(words, substring, position);
	}
}

void addNewWord(char** a, char* b, int &pos)
{
	int q = pos;

	char a[pos + 1] = new char[length(b)];     /?

	strcopy(a[pos + 1], b);
	++pos;
}

bool checkForBelonging(char** words, int number, char* substring)
{
	for (size_t i = 0; i < number; ++i)
	{
		if (!isEqual(words[i], substring))
			return false;
	}

	return true;
}

bool isEqual(char* a, char* b)
{
	if (length(a) != length(b))
		return false;

	for (size_t i = 0; i < length(a); ++i)
	{
		if (a[i] != b[i])
			return false;
	}

	return true;
}

int length(char* a)
{
	int i = 0;
	while (checkForASymb(a[i]))
	{
		++i;
	}
	return i;
}

bool checkForASymb(char a)
{
	if (a >= 'A' && a <= 'Z' || a >= 'a' && a <= 'z')
		return true;
	
	return false;
}

void strcopy(char* a, char* b)
{
	if (length(a) == length(b))
	{
		for (size_t i = 0; i < length(a); ++i)
		{
			a[i] = b[i];
		}
	}
}