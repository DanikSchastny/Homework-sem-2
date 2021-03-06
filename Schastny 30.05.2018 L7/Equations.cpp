// ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<iostream>
#include<cmath>
#include<iomanip>

double function(double x, double alpha);

double derivative(double x, double alpha);

double newtonMethod(double previous, double eps, double alpha);

double modNewtonMethod(double previous, double eps, double alpha);

void displayResult(double root, double eps, double leftBoard, double rightBoard, double f);


int main()
{
	displayResult(2, 0.001, 0, 1, 0.1);

	system("pause");
	return 0;
}

double function(double x, double alpha)
{
	return (alpha*pow(x, 3) - sin(x));
}

double derivative(double x, double alpha)
{
	return (3 * alpha*pow(x, 2) + cos(x));
}

double modNewtonMethod(double previous, double eps, double alpha)
{
	double following = previous - function(previous, alpha) / derivative(previous, alpha) -
		function(previous - pow(derivative(previous, alpha), -1), alpha) / derivative(previous, alpha);

	while (fabs(previous - following) <= eps)
	{
		previous = following;
		following = previous - function(previous, alpha) / derivative(previous, alpha) -
			function(previous - pow(derivative(previous, alpha), -1), alpha) / derivative(previous, alpha);

		std::cout << '-';
	}

	return following;
}

double newtonMethod(double previous, double eps, double alpha)
	{
		double following = previous - function(previous, alpha) / derivative(previous, alpha);

		while (fabs(previous - following) <= eps)
		{
			previous = following;
			following = previous - function(previous, alpha) / derivative(previous, alpha);

			std::cout << '+';
		}

		return following;
	}

void displayResult(double root, double eps, double leftBoard, double rightBoard, double f)
{
	std::cout << "Newton method:    Mod. Newton method:" << std::endl;

	for (double i = leftBoard; i <= rightBoard; i += f)
	{
		std::cout << ' ' << newtonMethod(root, eps, i) << std::setw(16) << ' ' << modNewtonMethod(root, eps, i) << std::endl;
	}
}