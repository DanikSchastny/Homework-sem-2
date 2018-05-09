#include "stdafx.h"
#include "CppUnitTest.h"
#include"MatrixLibrary.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixLibraryTests
{		
	TEST_CLASS(MatrixLibraryTests)
	{
	public:
		
		TEST_METHOD(FindMaxElementCheck1)
		{
			double m[3][3] = { {1,2,3},{8,5,9}, {16,32,1} };

			double** matrix = new double*[3];
			for (int i = 0; i < 3; ++i)
			{
				matrix[i] = new double[3];

				for (int j = 0; j < 3; ++j)
				{
					matrix[i][j] = m[i][j];
				}
			}

			double maxEl = MatrixLibrary::findMaxEl(matrix, 3, 3, 1, 0);

			Assert::IsTrue(maxEl == 32);

			for (int i = 0; i < 3; ++i)
				delete matrix[i];

			delete[] matrix;
		}

		TEST_METHOD(FindMaxElementCheck2)
		{
			double m[3][3] = { { 1,2,3 },{ 8,5,9 },{ 16,32,1 } };

			double** matrix = new double*[3];
			for (int i = 0; i < 3; ++i)
			{
				matrix[i] = new double[3];

				for (int j = 0; j < 3; ++j)
				{
					matrix[i][j] = m[i][j];
				}
			}

			double maxEl = MatrixLibrary::findMaxEl(matrix, 3, 3, 2, 1);

			Assert::IsTrue(maxEl == 32);

			for (int i = 0; i < 3; ++i)
				delete matrix[i];

			delete[] matrix;
		}

		TEST_METHOD(FindMaxElementCheck3)
		{
			double m[3][3] = { { 1,2,3 },{ 8,5,9 },{ 16,32,1 } };

			double** matrix = new double*[3];
			for (int i = 0; i < 3; ++i)
			{
				matrix[i] = new double[3];

				for (int j = 0; j < 3; ++j)
				{
					matrix[i][j] = m[i][j];
				}
			}

			double maxEl = MatrixLibrary::findMaxEl(matrix, 3, 3, 2, 2);

			Assert::IsTrue(maxEl == 1);

			for (int i = 0; i < 3; ++i)
				delete matrix[i];

			delete[] matrix;
		}

		TEST_METHOD(FindMaxElementCheck4)
		{
			double m[3][3] = { { 5,8,9 },{ 4,7,9 },{ 0,8,2 } };

			double** matrix = new double*[3];
			for (int i = 0; i < 3; ++i)
			{
				matrix[i] = new double[3];

				for (int j = 0; j < 3; ++j)
				{
					matrix[i][j] = m[i][j];
				}
			}

			double maxEl = MatrixLibrary::findMaxEl(matrix, 3, 3, 1, 0);

			Assert::IsTrue(maxEl == 8);

			for (int i = 0; i < 3; ++i)
				delete matrix[i];

			delete[] matrix;
		}

		TEST_METHOD(TheBuildingMatrixTest1)
		{
			double m[3][3] = { { 5,8,9 },{ 4,7,9 },{ 0,8,2 } };
			double result[3][3] = { {8,9,9} , {8,8,9}, {0,8,2} };

			double** matrix = new double*[3];
			double** matrixB = new double*[3];
			for (int i = 0; i < 3; ++i)
			{
				matrix[i] = new double[3];
				matrixB[i] = new double[3];

				for (int j = 0; j < 3; ++j)
				{
					matrix[i][j] = m[i][j];
				}
			}

			MatrixLibrary::buildNewMatrix(matrix, 3, 3, matrixB);

			bool res = true;

			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (matrixB[i][j] != result[i][j])
					{
						res = false;
						break;
					}
				}
			}

			Assert::IsTrue(res);

				for (int i = 0; i < 3; ++i)
				{
					delete matrix[i];
					delete matrixB[i];

				}

			delete[] matrix;
			delete[] matrixB;
		}


		TEST_METHOD(TheBuildingMatrixTest2)
		{
			double m[3][3] = { { 1,2,3 },{ 8,5,9 },{ 16,32,1 } };
			double result[3][3] = { { 32,32,32 } ,{ 32,32,32},{ 16,32,1 } };

			double** matrix = new double*[3];
			double** matrixB = new double*[3];
			for (int i = 0; i < 3; ++i)
			{
				matrix[i] = new double[3];
				matrixB[i] = new double[3];

				for (int j = 0; j < 3; ++j)
				{
					matrix[i][j] = m[i][j];
				}
			}

			MatrixLibrary::buildNewMatrix(matrix, 3, 3, matrixB);

			bool res = true;

			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (matrixB[i][j] != result[i][j])
					{
						res = false;
						break;
					}
				}
			}

			Assert::IsTrue(res);

			for (int i = 0; i < 3; ++i)
			{
				delete matrix[i];
				delete matrixB[i];

			}

			delete[] matrix;
			delete[] matrixB;
		}
		

	};
}