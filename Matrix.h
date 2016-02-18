#include "Macros.h"


class Matrix {
public:
	Matrix(Matrix& matrix);
    Matrix(unsigned int rows, unsigned int cols);
    Matrix(unsigned int rows, unsigned int cols, double initValue);

    ~Matrix();

	unsigned int GetNumCols();
	unsigned int GetNumRows();
	double* GetRowPointer(unsigned char row);
	double GetElement(unsigned int row, unsigned int col);
	int SetElement(unsigned int row, unsigned int col, double value);

	Matrix operator - ();

	Matrix operator+ (double constant);
	Matrix operator- (double constant);
	Matrix operator* (double constant);
	Matrix operator/ (double constant);

	Matrix operator+ (Matrix &matrix);
	Matrix operator- (Matrix &matrix);
	Matrix operator* (Matrix &matrix);

	Matrix& Negative();

	Matrix& Add(double constant);
	Matrix& Substract(double constant);
	Matrix& Multiply(double constant);
	Matrix& Divide(double constant);

	Matrix& Add(Matrix &matrix);
	Matrix& Substract(Matrix &matrix);
	Matrix& Multiply(Matrix &matrix);

	Matrix& Eye();

private:
    unsigned int cols, rows;
    double **ptr;
};
