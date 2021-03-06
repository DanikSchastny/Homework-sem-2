// Matrix_Library.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "Matrix_Library.h"
#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>

#pragma region Matrix

inline void mtrxdll::Matrix::SetColumn(int _column)
{
	if (_column == NULL || _column <= 0)
	{
		throw std::invalid_argument("Invalid column of matrix!");
	}
	this->column = _column;
}

inline void mtrxdll::Matrix::SetRow(int _row)
{
	if (_row == NULL || _row <= 0)
	{
		throw std::invalid_argument("Invalid row of matrix!");
	}

	this->row = _row;
}

 MATRIXLIBRARY_API mtrxdll::Matrix::Matrix(int _row,int _column)
{
	this->SetColumn(_column);
	this->SetRow(_row);
	this->SetMatrix(_row, _column); 
}

 MATRIXLIBRARY_API int** mtrxdll::Matrix::GetMatrix()
 {
	 return this->matrix;
 }

MATRIXLIBRARY_API mtrxdll::Matrix::~Matrix()
{
	FreeMemory(GetMatrix(),GetColumn());
}

int** mtrxdll::Matrix::AllocateMemory(int _row, int _column)
{
	{
		if (_row <= 0 || _column <= 0)
		{
			throw std::invalid_argument("Invalid sizes of matrix!");
		}

		int** _matrix = new int*[_column];
		{
			for (int i = 0; i < _column; ++i)
			{
				_matrix[i] = new int[_row];
			}
		}

		return _matrix;
	}
}

 MATRIXLIBRARY_API inline void  mtrxdll::Matrix::SetMatrix(int _row, int _column)
{
	this->matrix = AllocateMemory(_row, _column);
}

MATRIXLIBRARY_API void mtrxdll::Matrix::DisplayMatrix()
{
	for (int i = 0; i < column; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			std::cout << matrix[i][j] << ' ';
		}

		std::cout << std::endl;
	}
}

void  mtrxdll::Matrix::FreeMemory(int ** mtrx,int cols)
{
	for (int i = 0; i < cols; ++i)
	{
		delete[] mtrx[i];
	}
	delete[] mtrx;
}

MATRIXLIBRARY_API inline int mtrxdll::Matrix::GetColumn() const
{
	return this->column;
}

MATRIXLIBRARY_API inline int mtrxdll::Matrix::GetRow() const
{
	return this->row;
}

MATRIXLIBRARY_API void mtrxdll::Matrix::MatrixCopy(const Matrix& _m)
{
	for (int i = 0; i < this->GetColumn(); ++i)
	{
		for (int j = 0; j < this->GetRow(); ++j)
		{
			this->matrix[i][j] = _m.matrix[i][j];
		}
	}
}

MATRIXLIBRARY_API mtrxdll::Matrix::Matrix(const Matrix& _matrix)
{
	this->SetColumn(_matrix.column);
	this->SetRow(_matrix.row);
	this->SetMatrix(_matrix.row, _matrix.column);
	this->MatrixCopy(_matrix);
}

MATRIXLIBRARY_API std::istream& mtrxdll::operator>>(std::istream& input,const Matrix& _matrix)
{
	for (int i = 0; i < _matrix.column; ++i)
	{
		for (int j = 0; j < _matrix.row; ++j)
		{
			input >> _matrix.matrix[i][j];
		}
	}

	return input;
}

MATRIXLIBRARY_API std::ostream& mtrxdll::operator<< (std::ostream& output, const Matrix& _matrix)
{
	for (int i = 0; i < _matrix.column; ++i)
	{
		for (int j = 0; j < _matrix.row; ++j)
		{
			output <<_matrix.matrix[i][j] << ' ';
		}
		output << std::endl;
    }

	return output;
}

MATRIXLIBRARY_API int* mtrxdll::Matrix::operator[](int n)
{
	if (n < 0 || n >= this->GetColumn())
	{
		throw std::out_of_range("invalid ammount of columns!");
	}

	return matrix[n];
}

MATRIXLIBRARY_API mtrxdll::Matrix& mtrxdll::Matrix::operator=(const Matrix& _matrix)
{
	this->FreeMemory(this->GetMatrix(), this->GetColumn());
	this->matrix = AllocateMemory(_matrix.row, _matrix.column);
	this->MatrixCopy(_matrix);

	return *this;
}

MATRIXLIBRARY_API bool mtrxdll::Matrix::operator==(const Matrix& _matrix)
{
	if (this->row != _matrix.row || this->column != _matrix.column)
	{
		return false;
	}

	for (int i = 0; i < this->column; ++i)
	{
		for (int j = 0; j < this->row; ++j)
		{
			if (this->matrix[i][j] != _matrix.matrix[i][j])
				return false;
		}
	}

	return true;
}

MATRIXLIBRARY_API mtrxdll::Matrix mtrxdll::Matrix::operator+(const Matrix& mtrx)
{
	int MRow = (mtrx.GetRow() > this->GetRow() ? mtrx.GetRow() : this->GetRow());
	int MColumn = (mtrx.GetColumn() > this->GetColumn() ? mtrx.GetColumn() : this->GetColumn());

	Matrix sum(MRow, MColumn);

	for (int i = 0; i < MColumn; ++i)
	{
		for (int j = 0; j < MRow; ++j)
		{
			if (i >= mtrx.GetColumn() || j >= mtrx.GetRow())
			{
				if (i < this->GetColumn() && j < this->GetRow())
				{
					sum.matrix[i][j] = this->matrix[i][j];
				}
			}

			else if (i >= this->GetColumn() || j >= this->GetRow())
			{
				if (i < mtrx.GetColumn() && j < mtrx.GetRow())
				{
					sum.matrix[i][j] = mtrx.matrix[i][j];
				}
			}

			else sum.matrix[i][j] = this->matrix[i][j] + mtrx.matrix[i][j];
		}
	}

	return sum;
}

MATRIXLIBRARY_API mtrxdll::Matrix& mtrxdll::Matrix::operator+=(const Matrix& mtrx)
{
	Matrix sum = (*this) + mtrx;
	(*this) = sum;
	return *this;
}

MATRIXLIBRARY_API mtrxdll::Matrix mtrxdll::Matrix::operator-(const Matrix& mtrx)
{
	int MRow = (mtrx.GetRow() > this->GetRow() ? mtrx.GetRow() : this->GetRow());
	int MColumn = (mtrx.GetColumn() > this->GetColumn() ? mtrx.GetColumn() : this->GetColumn());
	
	Matrix d(MRow, MColumn);

	for (int i = 0; i < MColumn; ++i)
	{
		for (int j = 0; j < MRow; ++j)
		{
			if (i >= mtrx.GetColumn() || j >= mtrx.GetRow())
			{
				if (i < this->GetColumn() && j < this->GetRow())
				{
					d.matrix[i][j] = this->matrix[i][j];
				}

				else if (i >= this->GetColumn() || j >= this->GetRow())
				{
					if (i < mtrx.GetColumn() && j < mtrx.GetRow())
					{
						d.matrix[i][j] = -1 * mtrx.matrix[i][j];
					}
				}

				else d.matrix[i][j] = this->matrix[i][j] - mtrx.matrix[i][j];
			}
		}
	}

	return d;
}

MATRIXLIBRARY_API mtrxdll::Matrix& mtrxdll::Matrix::operator-=(const Matrix& mtrx)
{
	Matrix d = (*this) - mtrx;
	(*this) = d;
	return *this;
}

MATRIXLIBRARY_API mtrxdll::Matrix mtrxdll::Matrix::operator*(const Matrix& mtrx)
{
	if (this->GetRow() != mtrx.GetColumn())
	{
		throw std::out_of_range("Size-matrix error!");
	}

	Matrix mul(this->column, mtrx.row);

	for (int i = 0; i < this->column; ++i)
	{
		for (int j = 0; j < mtrx.row; ++j)
		{
			mul.matrix[i][j] = 0;
			for (int l = 0; l < mtrx.column; ++l)
			{
				mul.matrix[i][j] += matrix[i][l] * mtrx.matrix[l][j];
			}
		}
	}
	return mul;
}

MATRIXLIBRARY_API mtrxdll::Matrix& mtrxdll::Matrix::operator *=(const Matrix& mtrx)
{
	Matrix m = (*this)*mtrx;
	(*this) = m;
	return *this;
}

MATRIXLIBRARY_API bool mtrxdll::Matrix::operator !=(const Matrix& mtrx)
{
	if ((*this) == mtrx) return false;
	else return true;
}

MATRIXLIBRARY_API mtrxdll::Matrix mtrxdll::Matrix::TransposeMatrix()
{
	Matrix t(this->column, this->row);
	for (int i = 0; i < this->GetColumn(); ++i)
	{
		for (int j = 0; j < this->GetRow(); ++j)
			t.matrix[i][j] = matrix[j][i];
	}

	return(*this);
}

MATRIXLIBRARY_API void mtrxdll::Matrix::Swap(Matrix& m)
{
	Matrix t = m;
	m = (*this);
	(*this) = t;
}


#pragma endregion matrix

#pragma region TMatrix

template<typename T>
MATRIXLIBRARY_API inline int mtrxdll::TMatrix<T>::GetColumn()
{
	return this->column;
}

template<typename T>
MATRIXLIBRARY_API inline int mtrxdll::TMatrix<T>::GetRow()
{
	return this->row;
}

template<typename T>
MATRIXLIBRARY_API mtrxdll::TMatrix<T>::TMatrix() {}

template<typename T>
MATRIXLIBRARY_API mtrxdll::TMatrix<T>::TMatrix(int cols, int rows)
{
	this->SetColumn(cols)
	this->SetRow(rows);

	this->matrix = this->allocateMemory(cols, rows);
}

template<typename T>
inline void mtrxdll::TMatrix<T>::SetRow(int x)
{
	this->row = x;
}

template<typename T>
inline void  mtrxdll::TMatrix<T>::SetColumn(int x)
{

	this->column = x;
}

template<typename T>
MATRIXLIBRARY_API void mtrxdll::TMatrix<T>::CopyMatrix(const mtrxdll::TMatrix<T>& mtrx )
{
	this->FreeMemory();
	this->SetColumn(mtrx.GetColumn());
	this->SetRow(mtrx.GetRow());
	this->matrix = this->allocateMemory(mtrx.GetColumn(), mtrx.GetRow());

	for (size_t i = 0; i < this->GetColumn(); ++i)
	{
		for (size_t j = 0; j < this->GetRow(); ++j)
		{
			this->matrix[i][j] = mtrx.matrix[i][j];
		}
	}
}

template<typename T>
MATRIXLIBRARY_API mtrxdll::TMatrix<T>::TMatrix(const mtrxdll::TMatrix<T>& mtrx )
{
	this->CopyMatrix(mtrx);
}

template<typename T>
mtrxdll::TMatrix<T>** mtrxdll::TMatrix<T>::allocateMemory(int cols, int rows)
{
	if (cols <= 0 || rows <= 0)
	{
		throw std::invalid_argument("The incorrect sizes of matrix!");
	}

	T** mtrx = new T*[cols];

	for (size_t i = 0; i < cols; ++i)
	{
		mtrx[i] = new T[rows];
	}

	return mtrx;
}

template<typename T>
void mtrxdll::TMatrix<T>::FreeMemory(T** mtrx)
{
	for (size_t i = 0; i < GetColumn(); ++i)
	{
		delete[] mtrx.matrix[i];
	}

	delete[] mtrx.matrix;
}

template<typename T>
MATRIXLIBRARY_API void mtrxdll::TMatrix<T>::DisplayMatrix()
{
	for (size_t i = 0; i < this->GetColumn(); ++i)
	{
		for (size_t j = 0; j < this->GetRow(); ++j)
		{
			std::cout << this->matrix[i][j] << ' ';
		}

		std::cout << std::endl;
	}
}

template<typename T>
MATRIXLIBRARY_API void mtrxdll::TMatrix<T>::GenerateRandomMatrix()
{
	srand(time(NULL));
	for (size_t i = 0; i < this->GetColumn(); ++i)
	{
		for (size_t j = 0; j < this->GetRow(); ++j)
		{
			this->matrix[i][j] = rand() % 10;
		}
	}

}

template<typename T>
MATRIXLIBRARY_API mtrxdll::TMatrix<T>::~TMatrix()
{
	FreeMemory(matrix);
}

/*
template<typename T> 
MATRIXLIBRARY_API std::ostream& mtrxdll::operator<<(std::ostream& output, const TMatrix<T>& mtrx)
{
	for (size_t i = 0; i < mtrx.GetColumn(); ++i)
	{
		for (size_t i = 0; j < mtrx.GetRow(); ++j)
		{
			output << mtrx.matrix[i][j] << ' ';
		}

		output << std::endl;
	}

	return output;
}

template<typename T>
MATRIXLIBRARY_API mtrxdll::TMatrix<T>& mtrxdll::TMatrix<T>::operator=(const mtrxdll::TMatrix<T>& mtrx)
{
	if (this != &mtrx)
	{
		mtrxdll::TMatrix<T>::FreeMemory(*this);

		this->MatrixCopy();
	}

	return *this;
}

template<typename T>
MATRIXLIBRARY_API int* mtrxdll::TMatrix<T>::operator[] (int m)
{
	if (m > cols)
	{
		return 0;
	}

	else return matrix[n];
}

template<typename T>
MATRIXLIBRARY_API bool mtrxdll::TMatrix<T>::operator == (const mtrxdll::TMatrix<T>& mtrx) const
{
	if (this->GetColumn() != mtrx.GetColumn() || this->GetRow() != mtrx.GetRow()) return false;

	for (size_t i = 0; i < this->GetColumn(); ++i)
	{
		for (size_t j = 0; j < this->GetRow(); ++j)
		{
			if (this->matrix[i][j] != mtrx.matrix[i][j]) return false;
		}
	}
}

template<typename T>
MATRIXLIBRARY_API bool  mtrxdll::TMatrix<T>::operator!= (const mtrxdll::TMatrix<T>& mtrx) const
{
	if (*this == mtrx) return false;
}

template<typename T>
MATRIXLIBRARY_API mtrxdll::TMatrix<T> mtrxdll::TMatrix<T>::operator+(const mtrxdll::TMatrix<T>& mtrx) const
{
	int MRow = (mtrx.GetRow() > this->GetRow() ? mtrx.GetRow() : this->GetRow());
	int MColumn = (mtrx.GetColumn() > this->GetColumn() ? mtrx.GetColumn() : this->GetColumn());

	TMatrix<T> sum(MColumn, MRow);

	for (int i = 0; i < MColumn; ++i)
	{
		for (int j = 0; j < MRow; ++j)
		{
			if (i >= mtrx.GetColumn() || j >= mtrx.GetRow())
			{
				if (i < this->GetColumn() && j < this->GetRow())
				{
					sum.matrix[i][j] = this->matrix[i][j];
				}
			}

			else if (i >= this->GetColumn() || j >= this->GetRow())
			{
				if (i < mtrx.GetColumn() && j < mtrx.GetRow())
				{
					sum.matrix[i][j] = mtrx.matrix[i][j];
				}
			}

			else sum.matrix[i][j] = this->matrix[i][j] + mtrx.matrix[i][j];
		}
	}
	return sum;
}
*/
//template<typename T> 
//MATRIXLIBRARY_API std::istream & mtrxdll::operator>>(std::istream &, const mtrxdll::TMatrix<T>& mtrx)
//{
//	for (size_t i = 0; i < mtrx.GetColumn(); ++i)
//	{
//		input >> mtrx.matrix[i][j];
//	}
//	return input;
//}
//
//
//





#pragma endregion 
















//Гради бутч
//Джефри Рихтер