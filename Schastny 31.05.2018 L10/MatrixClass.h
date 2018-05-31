#pragma once
class Matrix
{
public:

	inline int** GetMatrix();

	 inline void SetMatrix(int, int);

	 void DisplayMatrix();

	 Matrix(int, int);

	 Matrix() { };

	~Matrix();

	inline int GetRow() const;

	inline int GetColumn() const;

	Matrix(const Matrix&);

	void MatrixCopy(const Matrix&);

	friend std::istream& operator>> (std::istream&, const Matrix&);

    friend std::ostream& operator<< (std::ostream&, const Matrix&);

	int* operator[](int n);

	Matrix& operator = (const Matrix&);

    Matrix operator+(const Matrix&);

	Matrix& operator+=(const Matrix&);

	Matrix operator-(const Matrix&);

	Matrix& operator-=(const Matrix&);

    Matrix operator*(const Matrix&);

	Matrix& operator*=(const Matrix&);

    bool operator !=(const Matrix&);

	bool operator == (const Matrix&);

	void Swap(Matrix&);

    Matrix TransposeMatrix();

	static void buildNewMatrix(Matrix matrixA, Matrix matrixB);

	double findMaxEl(int rowsPosition, int colsPosition);


private:

	void FreeMemory(int **, int);

	inline void  SetColumn(int);

	inline void SetRow(int);

	int ** AllocateMemory(int, int);

	int** matrix;
	int column, row;
};

inline void Matrix::SetColumn(int _column)
{
	if (_column == NULL || _column <= 0)
	{
		throw std::invalid_argument("Invalid column of matrix!");
	}
	this->column = _column;
}

inline void Matrix::SetRow(int _row)
{
	if (_row == NULL || _row <= 0)
	{
		throw std::invalid_argument("Invalid row of matrix!");
	}

	this->row = _row;
}

Matrix::Matrix(int _row, int _column)
{
	this->SetColumn(_column);
	this->SetRow(_row);
	this->SetMatrix(_row, _column);
}

int** Matrix::GetMatrix()
{
	return this->matrix;
}

Matrix::~Matrix()
{
	FreeMemory(GetMatrix(), GetColumn());
}

int** Matrix::AllocateMemory(int _row, int _column)
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

inline void  Matrix::SetMatrix(int _row, int _column)
{
	this->matrix = AllocateMemory(_row, _column);
}

void Matrix::DisplayMatrix()
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

void  Matrix::FreeMemory(int ** mtrx, int cols)
{
	for (int i = 0; i < cols; ++i)
	{
		delete[] mtrx[i];
	}
	delete[] mtrx;
}

inline int Matrix::GetColumn() const
{
	return this->column;
}

inline int Matrix::GetRow() const
{
	return this->row;
}

void Matrix::MatrixCopy(const Matrix& _m)
{
	for (int i = 0; i < this->GetColumn(); ++i)
	{
		for (int j = 0; j < this->GetRow(); ++j)
		{
			this->matrix[i][j] = _m.matrix[i][j];
		}
	}
}

Matrix::Matrix(const Matrix& _matrix)
{
	this->SetColumn(_matrix.column);
	this->SetRow(_matrix.row);
	this->SetMatrix(_matrix.row, _matrix.column);
	this->MatrixCopy(_matrix);
}

 std::istream& operator>>(std::istream& input, const Matrix& _matrix)
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

std::ostream& operator<< (std::ostream& output, const Matrix& _matrix)
{
	for (int i = 0; i < _matrix.column; ++i)
	{
		for (int j = 0; j < _matrix.row; ++j)
		{
			output << _matrix.matrix[i][j] << ' ';
		}
		output << std::endl;
	}

	return output;
}

int* Matrix::operator[](int n)
{
	if (n < 0 || n >= this->GetColumn())
	{
		throw std::out_of_range("invalid ammount of columns!");
	}

	return matrix[n];
}

Matrix& Matrix::operator=(const Matrix& _matrix)
{
	this->FreeMemory(this->GetMatrix(), this->GetColumn());
	this->matrix = AllocateMemory(_matrix.row, _matrix.column);
	this->MatrixCopy(_matrix);

	return *this;
}

bool Matrix::operator==(const Matrix& _matrix)
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

Matrix Matrix::operator+(const Matrix& mtrx)
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

Matrix& Matrix::operator+=(const Matrix& mtrx)
{
	Matrix sum = (*this) + mtrx;
	(*this) = sum;
	return *this;
}

Matrix Matrix::operator-(const Matrix& mtrx)
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

Matrix& Matrix::operator-=(const Matrix& mtrx)
{
	Matrix d = (*this) - mtrx;
	(*this) = d;
	return *this;
}

Matrix Matrix::operator*(const Matrix& mtrx)
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

Matrix& Matrix::operator *=(const Matrix& mtrx)
{
	Matrix m = (*this)*mtrx;
	(*this) = m;
	return *this;
}

bool Matrix::operator !=(const Matrix& mtrx)
{
	if ((*this) == mtrx) return false;
	else return true;
}

Matrix Matrix::TransposeMatrix()
{
	Matrix t(this->column, this->row);
	for (int i = 0; i < this->GetColumn(); ++i)
	{
		for (int j = 0; j < this->GetRow(); ++j)
			t.matrix[i][j] = matrix[j][i];
	}

	return(*this);
}

void Matrix::Swap(Matrix& m)
{
	Matrix t = m;
	m = (*this);
	(*this) = t;
}

double Matrix::findMaxEl(int rowsPosition, int colsPosition)
{
	double maxEl = this->matrix[rowsPosition][colsPosition];

	if (colsPosition == 0)
	{
		for (int i = rowsPosition, iPos = 0; i < this->GetColumn(); ++i, ++iPos)
		{
			for (int j = 0; j <= iPos; ++j)
			{
				if (matrix[i][j] > maxEl)
					maxEl = matrix[i][j];
			}
		}
	}

	if (rowsPosition == this->GetColumn() - 1)
		return matrix[rowsPosition][colsPosition];

	if (colsPosition == this->GetColumn() - 1)
	{
		for (int i = rowsPosition; i < this->GetColumn(); ++i)
		{
			for (int j = this->GetRow() - 1; j >= this->GetRow() - 1 - i; --j)
			{
				if (matrix[i][j] > maxEl)
					maxEl = matrix[i][j];
			}
		}
	}

	if (colsPosition > 0 && colsPosition < this->GetColumn() - 1)
	{
		for (int i = rowsPosition, iPos = 0; i < this->GetColumn(); ++i, ++iPos)
		{

			if (i == rowsPosition)
			{
				if (matrix[i][i] > maxEl)
					maxEl = matrix[i][i];
			}

			else
			{
				int left = colsPosition, right = colsPosition;

				if (left - 1 <= 0)
					left = 0;
				else left -= 1;

				if (right + 1 >= this->GetRow() - 1)
					right = this->GetRow() - 1;
				else right += 1;

				for (int j = left; j <= right; ++j)
				{
					if (matrix[i][j] > maxEl)
						maxEl = matrix[i][j];
				}

			}
		}
	}

	return maxEl;
}

void Matrix::buildNewMatrix(Matrix matrixA,Matrix matrixB)
{
	for (int i = 0; i < matrixA.GetColumn(); ++i)
	{
		for (int j = 0; j < matrixA.GetRow(); ++j)
		{
			matrixB[i][j] =matrixA.findMaxEl( i, j);
		}
	}
}