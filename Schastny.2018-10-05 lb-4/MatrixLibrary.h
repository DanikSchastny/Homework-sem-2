#pragma once

#ifdef MATRIXLIBRARY_EXPORTS 
#define MATRIXLIBRARY_API __declspec(dllexport) 
#else 
#define MATRIXLIBRARY_API __declspec(dllimport) 
#endif


namespace Matrix
{

	MATRIXLIBRARY_API void displayMatrix(double*, int, int);

	MATRIXLIBRARY_API double* mult(double* matrix, int side, int ammount);

	MATRIXLIBRARY_API double matrixTrace(double* arr, int side);
}
