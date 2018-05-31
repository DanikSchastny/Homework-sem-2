//Matrix_Library.h


#pragma once


#ifdef MATRIXLIBRARY_EXPORTS 
#define MATRIXLIBRARY_API __declspec(dllexport) 
#else 
#define MATRIXLIBRARY_API __declspec(dllimport) 
#endif
#include<iostream> 

namespace mtrxdll
{

	class Matrix
	{
	public:

		MATRIXLIBRARY_API inline int** GetMatrix();

		MATRIXLIBRARY_API inline void SetMatrix(int, int);

		MATRIXLIBRARY_API void DisplayMatrix();

		MATRIXLIBRARY_API Matrix(int, int);

		MATRIXLIBRARY_API Matrix() { };

		MATRIXLIBRARY_API ~Matrix();

		MATRIXLIBRARY_API inline int GetRow() const;

		MATRIXLIBRARY_API inline int GetColumn() const;

		MATRIXLIBRARY_API Matrix(const Matrix&);

		MATRIXLIBRARY_API void MatrixCopy(const Matrix&);

		MATRIXLIBRARY_API friend std::istream& operator>> (std::istream&, const Matrix&);

		MATRIXLIBRARY_API friend std::ostream& operator<< (std::ostream&, const Matrix&);

		MATRIXLIBRARY_API int* operator[](int n);

		MATRIXLIBRARY_API Matrix& operator = (const Matrix&);

		MATRIXLIBRARY_API Matrix operator+(const Matrix&);

		MATRIXLIBRARY_API Matrix& operator+=(const Matrix&);

		MATRIXLIBRARY_API Matrix operator-(const Matrix&);

		MATRIXLIBRARY_API Matrix& operator-=(const Matrix&);

		MATRIXLIBRARY_API Matrix operator*(const Matrix&);

		MATRIXLIBRARY_API Matrix& operator*=(const Matrix&);

		MATRIXLIBRARY_API bool operator !=(const Matrix&);

		MATRIXLIBRARY_API bool operator == (const Matrix&);

		MATRIXLIBRARY_API void Swap(Matrix&);

		MATRIXLIBRARY_API Matrix TransposeMatrix();

		//MATRIXLIBRARY_API void CreateTaylorMatrix(int, int, double, Matrix&);

		//MATRIXLIBRARY_API void CreateLibMatrix(int, int, Matrix&);


	private:

		void FreeMemory(int **, int);

		inline void  SetColumn(int);

		inline void SetRow(int);

		int ** AllocateMemory(int, int);

		int** matrix;
		int column, row;
	};

	template<typename T>
	class TMatrix
	{
	public:
		MATRIXLIBRARY_API TMatrix();

	    MATRIXLIBRARY_API TMatrix(int, int);

		MATRIXLIBRARY_API ~TMatrix();

		MATRIXLIBRARY_API inline int GetRow();

		MATRIXLIBRARY_API inline int GetColumn();

		MATRIXLIBRARY_API void DisplayMatrix();

		MATRIXLIBRARY_API void GenerateRandomMatrix();

		MATRIXLIBRARY_API void CopyMatrix(const TMatrix<T>& mtrx);

		MATRIXLIBRARY_API TMatrix(const TMatrix<T>&);

	private:

		inline void SetColumn(int);

		inline void SetRow(int);

		TMatrix<T>** allocateMemory(int, int);

		static void FreeMemory(T**);

		int row, column;
		T** matrix;

	};

	
}
