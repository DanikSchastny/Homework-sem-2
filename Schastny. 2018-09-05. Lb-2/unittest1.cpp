#include "stdafx.h"
#include "CppUnitTest.h"
#include "MatrixLibrary.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixLibraryTest
{
	TEST_CLASS(MatrixLibraryTestClass)
	{
	public:

		TEST_METHOD(SinusTaylorTest1)
		{
			double x = 0.12;
			double epsl = 0.0012;

			Assert::IsTrue(fabs(Matrix::sinTaylor(x, epsl) - sin(x)) < epsl);
		}

		TEST_METHOD(SinusTaylorTest2)
		{
			double x = 9.12, epsl = 0.000001;

			x = Matrix::redictionFormule(x);

			Assert::IsTrue(fabs(Matrix::sinTaylor(x, epsl) - sin(x)) < epsl);
		}

		TEST_METHOD(MatrixCompare1)
		{
			int rows = 100, cols = 100;

			double epsl = 0.0002;
			double** matrix = new double*[rows];
			double** secMatrix = new double*[rows];

			for (int i = 0; i < rows; ++i)
			{
				secMatrix[i] = new double[cols];
				matrix[i] = new double[cols];
			}

			Assert::IsTrue(Matrix::comparisonMatrix(matrix, secMatrix, rows, cols, epsl));

			for (int i = 0; i < rows; ++i)
			{
				delete[] matrix[i];
				delete[] secMatrix[i];
			}

			delete[] matrix;
			delete[] secMatrix;
		}

		TEST_METHOD(MatrixCompare2)
		{
			int rows = 250, cols = 250;

			double epsl = 0.0015;
			double** matrix = new double*[rows];
			double** secMatrix = new double*[rows];

			for (int i = 0; i < rows; ++i)
			{
				secMatrix[i] = new double[cols];
				matrix[i] = new double[cols];
			}

			Assert::IsTrue(Matrix::comparisonMatrix(matrix, secMatrix, rows, cols, epsl));

			for (int i = 0; i < rows; ++i)
			{
				delete[] matrix[i];
				delete[] secMatrix[i];
			}

			delete[] matrix;
			delete[] secMatrix;
		}

		TEST_METHOD(MatrixCompare3)
		{
			int rows = 500, cols = 500;

			double epsl = 0.0015;
			double** matrix = new double*[rows];
			double** secMatrix = new double*[rows];

			for (int i = 0; i < rows; ++i)
			{
				secMatrix[i] = new double[cols];
				matrix[i] = new double[cols];
			}

			Assert::IsTrue(Matrix::comparisonMatrix(matrix, secMatrix, rows, cols, epsl));

			for (int i = 0; i < rows; ++i)
			{
				delete[] matrix[i];
				delete[] secMatrix[i];
			}

			delete[] matrix;
			delete[] secMatrix;
		}

		TEST_METHOD(MatrixCompare4)
		{
			int rows = 700, cols = 700;

			double epsl = 0.0015;
			double** matrix = new double*[rows];
			double** secMatrix = new double*[rows];

			for (int i = 0; i < rows; ++i)
			{
				secMatrix[i] = new double[cols];
				matrix[i] = new double[cols];
			}

			Assert::IsTrue(Matrix::comparisonMatrix(matrix, secMatrix, rows, cols, epsl));

			for (int i = 0; i < rows; ++i)
			{
				delete[] matrix[i];
				delete[] secMatrix[i];
			}

			delete[] matrix;
			delete[] secMatrix;
		}

		TEST_METHOD(MatrixCompare5)
		{
			int rows = 950, cols = 950;

			double epsl = 0.0001;
			double** matrix = new double*[rows];
			double** secMatrix = new double*[rows];

			for (int i = 0; i < rows; ++i)
			{
				secMatrix[i] = new double[cols];
				matrix[i] = new double[cols];
			}

			Assert::IsTrue(Matrix::comparisonMatrix(matrix, secMatrix, rows, cols, epsl));

			for (int i = 0; i < rows; ++i)
			{
				delete[] matrix[i];
				delete[] secMatrix[i];
			}

			delete[] matrix;
			delete[] secMatrix;
		}

		TEST_METHOD(MatrixCompare6)
		{
			int rows = 1000, cols = 1000;

			double epsl = 0.0001;
			double** matrix = new double*[rows];
			double** secMatrix = new double*[rows];

			for (int i = 0; i < rows; ++i)
			{
				secMatrix[i] = new double[cols];
				matrix[i] = new double[cols];
			}

			Assert::IsTrue(Matrix::comparisonMatrix(matrix, secMatrix, rows, cols, epsl));

			for (int i = 0; i < rows; ++i)
			{
				delete[] matrix[i];
				delete[] secMatrix[i];
			}

			delete[] matrix;
			delete[] secMatrix;
		}

		TEST_METHOD(MatrixCompare7)
		{
			int rows = 2750, cols = 2750;

			double epsl = 0.0000001;
			double** matrix = new double*[rows];
			double** secMatrix = new double*[rows];

			for (int i = 0; i < rows; ++i)
			{
				secMatrix[i] = new double[cols];
				matrix[i] = new double[cols];
			}

			Assert::IsTrue(Matrix::comparisonMatrix(matrix, secMatrix, rows, cols, epsl));

			for (int i = 0; i < rows; ++i)
			{
				delete[] matrix[i];
				delete[] secMatrix[i];
			}

			delete[] matrix;
			delete[] secMatrix;
		}

		TEST_METHOD(MatrixCompare8)
		{
			int rows = 5000, cols = 5000;

			double epsl = 0.00001;
			double** matrix = new double*[rows];
			double** secMatrix = new double*[rows];

			for (int i = 0; i < rows; ++i)
			{
				secMatrix[i] = new double[cols];
				matrix[i] = new double[cols];
			}

			Assert::IsTrue(Matrix::comparisonMatrix(matrix, secMatrix, rows, cols, epsl));

			for (int i = 0; i < rows; ++i)
			{
				delete[] matrix[i];
				delete[] secMatrix[i];
			}

			delete[] matrix;
			delete[] secMatrix;
		}

		TEST_METHOD(MatrixCompare9)
		{
			int rows = 2750, cols = 2750;

			double epsl = 0.0000001;
			double** matrix = new double*[rows];
			double** secMatrix = new double*[rows];

			for (int i = 0; i < rows; ++i)
			{
				secMatrix[i] = new double[cols];
				matrix[i] = new double[cols];
			}

			Assert::IsTrue(Matrix::comparisonMatrix(matrix, secMatrix, rows, cols, epsl));

			for (int i = 0; i < rows; ++i)
			{
				delete[] matrix[i];
				delete[] secMatrix[i];
			}

			delete[] matrix;
			delete[] secMatrix;
		}

		TEST_METHOD(MatrixCompare10)
		{
			int rows = 2000, cols = 2000;

			double epsl = 0.00001;
			double** matrix = new double*[rows];
			double** secMatrix = new double*[rows];

			for (int i = 0; i < rows; ++i)
			{
				secMatrix[i] = new double[cols];
				matrix[i] = new double[cols];
			}

			Assert::IsTrue(Matrix::comparisonMatrix(matrix, secMatrix, rows, cols, epsl));

			for (int i = 0; i < rows; ++i)
			{
				delete[] matrix[i];
				delete[] secMatrix[i];
			}

			delete[] matrix;
			delete[] secMatrix;
		}

	};

}