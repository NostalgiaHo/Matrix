#include "Matrix.h"
#include <cassert>

Matrix::Matrix(Matrix &matrix)
{
	this->cols = matrix.cols;
	this->rows = matrix.rows;

	ptr = new double*[rows];
	for (int i = 0; i != rows; ++i)
	{
		ptr[i] = new double[cols];
		for (int j = 0; j != cols; ++j)
		{
			ptr[i][j] = matrix.ptr[i][j];
		}
	}
}

Matrix::Matrix(unsigned int rows, unsigned int cols)
{
	this->cols = cols;
	this->rows = rows;

	ptr = new double*[rows];
	for (int i = 0; i != rows; ++i)
	{
		ptr[i] = new double[cols];
		for (int j = 0; j != cols; ++j)
		{
			ptr[i][j] = 0;
		}
	}
}

Matrix::Matrix(unsigned int rows, unsigned int cols, double initValue)
{
    this->cols = cols;
    this->rows = rows;

    ptr = new double*[rows];
    for (int i = 0; i != rows; ++i)
    {
        ptr[i] = new double[cols];
        for (int j = 0; j != cols; ++j)
        {
            ptr[i][j] = initValue;
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i != rows; ++i)
    {
        delete[] ptr[i];
    }
    delete[] ptr;
}

unsigned int Matrix::GetNumCols()
{
	return cols;
}

unsigned int Matrix::GetNumRows()
{
	return rows;
}

double* Matrix::GetRowPointer(unsigned char row)
{
	if (row > rows)
	{
		return nullptr;
	}
	return ptr[row];
}

double Matrix::GetElement(unsigned int row, unsigned int col)
{
	if (row > rows)
	{
		return MATRIX_ROW_TOO_LARGE;
	}
	if (col > cols)
	{
		return MATRIX_COL_TOO_LARGE;
	}
	return ptr[row][col];
}

int Matrix::SetElement(unsigned int row, unsigned int col, double value)
{
	if (row > rows)
	{
		return MATRIX_ROW_TOO_LARGE;
	}
	if (col > cols)
	{
		return MATRIX_COL_TOO_LARGE;
	}
	ptr[row][col] = value;
	return 0;
}

Matrix Matrix::operator- () 
{
	Matrix matrix(*this);
	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			matrix.ptr[i][j] = -matrix.ptr[i][j];
		}
	}
	return matrix;
}

Matrix Matrix::operator+ (double constant)
{
	Matrix matrix(*this);
	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			matrix.ptr[i][j] += constant;
		}
	}
	return matrix;
}

Matrix Matrix::operator- (double constant)
{
	return *this + (-constant); 
}

Matrix Matrix::operator* (double constant)
{
	Matrix matrix(*this);
	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			matrix.ptr[i][j] *= constant;
		}
	}
	return matrix;
}

Matrix Matrix::operator/ (double constant)
{
	assert(constant != 0);
	Matrix matrix(*this);
	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			matrix.ptr[i][j] /= constant;
		}
	}
	return matrix;
}

Matrix Matrix::operator+ (Matrix &matrix)
{	
	assert(this->rows == matrix.rows);
	assert(this->cols == matrix.cols);
	Matrix m(*this);
	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			m.ptr[i][j] += matrix.ptr[i][j];
		}
	}
	return m;
}

Matrix Matrix::operator- (Matrix &matrix)
{
	assert(this->rows == matrix.rows);
	assert(this->cols == matrix.cols);
	Matrix m(*this);
	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			m.ptr[i][j] -= matrix.ptr[i][j];
		}
	}
	return m;
}

Matrix Matrix::operator* (Matrix &matrix)
{
	assert(this->cols == matrix.rows);
	Matrix m(this->rows, matrix.cols);
	for (int i = 0; i != this->rows; ++i)
	{
		for (int j = 0; j != matrix.cols; ++j)
		{
			for (int k = 0; k != this->cols; ++k)
			{
				m.ptr[i][j] += this->ptr[i][k] * matrix.ptr[k][j];
			}
		}
	}
	return m;
}

Matrix& Matrix::Negative()
{
	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			ptr[i][j] = -ptr[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::Add(double constant)
{
	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			ptr[i][j] += constant;
		}
	}
	return *this;
}

Matrix& Matrix::Substract(double constant)
{
	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			ptr[i][j] -= constant;
		}
	}
	return *this;
}

Matrix& Matrix::Multiply(double constant)
{
	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			ptr[i][j] *= constant;
		}
	}
	return *this;
}

Matrix& Matrix::Divide(double constant)
{
	assert(constant != 0);
	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			ptr[i][j] /= constant;
		}
	}
	return *this;
}

Matrix& Matrix::Add(Matrix &matrix)
{
	assert(this->rows == matrix.rows);
	assert(this->cols == matrix.cols);
	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			ptr[i][j] += matrix.ptr[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::Substract(Matrix &matrix)
{
	assert(this->rows == matrix.rows);
	assert(this->cols == matrix.cols);
	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			ptr[i][j] -= matrix.ptr[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::Multiply(Matrix &matrix)
{
	assert(this->cols == matrix.rows);
	double **tempPtr = this->ptr;
	this->cols = matrix.cols;

	this->ptr = new double*[this->rows];
	for (int i = 0; i != this->rows; ++i)
	{
		ptr[i] = new double[this->cols];
		for (int j = 0; j != this->cols; ++j)
		{
			ptr[i][j] = 0;
		}
	}

	for (int i = 0; i != this->rows; ++i)
	{
		for (int j = 0; j != matrix.cols; ++j)
		{
			for (int k = 0; k != matrix.rows; ++k)
			{
				this->ptr[i][j] += tempPtr[i][k] * matrix.ptr[k][j];
			}
		}
	}
	for (int i = 0; i != this->rows; ++i)
	{
		delete[] tempPtr[i];
	}
	delete tempPtr;

	return *this;
}

Matrix& Matrix::Eye()
{ 
	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			ptr[i][j] = (i == j) ? 1 : 0;
		}
	}
	return *this;
}
