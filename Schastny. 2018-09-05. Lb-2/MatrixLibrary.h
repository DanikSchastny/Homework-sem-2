#pragma once


#ifdef MATRIXLIBRARY_EXPORTS
#define MATRIXLIBRARY_API __declspec(dllexport) 
#else 
#define MATRIXLIBRARY_API __declspec(dllimport) 
#endif


namespace Matrix
{
	MATRIXLIBRARY_API double redictionFormule(double);

	MATRIXLIBRARY_API double sinTaylor(double value, double accurancy);

	MATRIXLIBRARY_API void createSinTaylorMatrix(double** matrix, int rows, int cols, double accur);

	MATRIXLIBRARY_API void createSinMatrix(double **, int, int);

	MATRIXLIBRARY_API bool comparisonMatrix(double**, double**, int, int, double);
}