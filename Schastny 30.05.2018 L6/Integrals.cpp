// ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<iostream>
#include<cmath>

double function(double x);

double countingH(double leftBoard, double rightBoard, int part);

double rightRectangle(int part, double leftBoard, double rightBoard);

bool rightRectangleChecking(double eps, int part1, int part2, double rightBoard, double leftBoard);

double avarageRectangle(int part, double leftBoard, double rightBoard);

bool avarageRectangleChecking(double eps, int part1, int part2, double rightBoard, double leftBoard);

bool(*test[])(double eps, int part1, int part2, double rightBoard, double leftBoard) =
{
	avarageRectangleChecking,rightRectangleChecking
};

int main()
{
	double leftBoard = 0, rightBoard = 1, eps = 0.0005;
	int part1 = 100, part2 = 200;

	for (int i = 0; i < 2; ++i)
	{
		if (test[i](eps, part1, part2, rightBoard, leftBoard)) std::cout << "Works!" << std::endl;
		else std::cout << "Error!" << std::endl;
	}

	/*if (rightRectangleChecking(eps, part1, part2, rightBoard, leftBoard))
		std::cout << "Right rectangle method works!" << std::endl;
	else std::cout << "Something wrong with right rectangle method! Try bigger parts!" << std::endl;


	if (avarageRectangleChecking(eps, part1, part2, rightBoard, leftBoard))
		std::cout << "Avarage rectangle method works!" << std::endl;
	else std::cout << "Something wrong with avarage rectangle method! Try bigger parts!" << std::endl; */

	system("pause");
	return 0;
}

double function(double x)
{
	return(1 / sqrt(pow(x, 4)));
}

double countingH(double leftBoard, double rightBoard, int part)
{
	return (rightBoard - leftBoard) / part;
}

double rightRectangle(int part, double leftBoard, double rightBoard)
{
	long double sum = 0;

	double h = countingH(leftBoard, rightBoard, part);

	for (int i = 1; i <= part; ++i)
	{
		double term = leftBoard + h * i;

		sum += function(leftBoard + h*i);
	}
	return h*sum;
}

bool rightRectangleChecking(double eps, int part1, int part2, double rightBoard, double leftBoard)
{
	if (part1 == part2) { std::cout << "error! the equal parts!" << std::endl; }

	if (fabs(rightRectangle(part1, leftBoard, rightBoard) - rightRectangle(part2, leftBoard, rightBoard) < eps))
		return true;

	else return false;
}

double avarageRectangle(int part, double leftBoard, double rightBoard)
{
	double sum = 0;

	double h = countingH(leftBoard, rightBoard, part);

	for (int i = 0; i <= part - 1; ++i)
	{
		sum += function(leftBoard + h*i + h / 2);
	}

	return h*sum;
}

bool avarageRectangleChecking(double eps, int part1, int part2, double rightBoard, double leftBoard)
{
	if (part1 == part2) { std::cout << "error! the equal parts!" << std::endl; }

	if (fabs(avarageRectangle(part1, leftBoard, rightBoard) - avarageRectangle(part2, leftBoard, rightBoard) < eps))
		return true;

	else return false;
}
