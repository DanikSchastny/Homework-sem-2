#pragma once

#ifdef MATRIXLIBRARY_EXPORTS
#define MATRIXLIBRARY_API __declspec(dllexport) 
#else
#define MATRIXLIBRARY_API __declspec(dllimport) 
#endif


namespace MatrixLibrary
{
	MATRIXLIBRARY_API void buildNewMatrix(double**, int, int, double**);

	MATRIXLIBRARY_API double findMaxEl(double**, int, int, int, int);
}