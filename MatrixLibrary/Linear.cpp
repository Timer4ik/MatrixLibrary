#include <iostream>
#include <vector>
#include "Linear.h"

Matrix::Matrix(int rows, int cols, std::vector<float> matrix) {
	this->matrix = matrix;
	this->cols = cols;
	this->rows = rows;
}
Matrix::Matrix(int rows, int cols) {
	this->cols = cols;
	this->rows = rows;

	std::vector<float> matrix{};

	for (size_t i = 0; i < getSize(); i++)
	{
		matrix.push_back(0);
	}
	this->matrix = matrix;
}
int Matrix::getCols() {
	return this->cols;
}
int Matrix::getRows() {
	return this->rows;
}
int Matrix::getSize() {
	return this->rows * this->cols;
}
std::vector<float> Matrix::getMatrix() {
	return this->matrix;
}
float& Matrix::operator[](int i) {
	return this->matrix[i];
}
void Matrix::print() {
	for (int i = 0; i < getSize(); i++)
	{
		if ((i) % getCols() == 0) {
			std::cout << std::endl;
		}
		std::cout << matrix[i] << "  ";
	}
}
Matrix operator + (float num, Matrix matrix) {
	if (num == 0) {
		return matrix;
	}

	for (size_t i = 0; i < matrix.getSize(); i++)
	{
		matrix[i] = matrix[i] + num;
	}

	return matrix;
}
Matrix operator + (Matrix matrix, float num) {
	if (num == 0) {
		return matrix;
	}

	for (size_t i = 0; i < matrix.getSize(); i++)
	{
		matrix[i] = matrix[i] + num;
	}

	return matrix;
}
Matrix operator + (Matrix matrix1, Matrix matrix2)
{

	if (matrix1.getCols() != matrix2.getCols() || matrix1.getRows() != matrix2.getRows()) {
		throw "";
	}

	for (size_t i = 0; i < matrix2.getSize(); i++)
	{
		matrix1[i] += matrix2[i];
	}

	return matrix1;
}
Matrix operator * (float num, Matrix matrix) {
	if (num == 0) {
		return matrix;
	}

	for (size_t i = 0; i < matrix.getSize(); i++)
	{
		matrix[i] = matrix[i] * num;
	}

	return matrix;
}
Matrix operator * (Matrix matrix, float num) {
	if (num == 0) {
		return matrix;
	}

	for (size_t i = 0; i < matrix.getSize(); i++)
	{
		matrix[i] = matrix[i] * num;
	}

	return matrix;
}
Matrix operator * (Matrix matrix1, Matrix matrix2)
{
	if (matrix1.getCols() != matrix2.getRows()) {
		throw "";
	}

	int newRows = matrix1.getRows();
	int newCols = matrix2.getCols();
	Matrix newMatrix{ newRows ,newCols };

	int index = 0;
	for (size_t i = 0; i < matrix1.getRows(); i++)
	{
		for (size_t j = 0; j < matrix2.getCols(); j++)
		{
			for (size_t z = 0; z < matrix2.getRows(); z++)
			{
				newMatrix[index] += matrix1[i * matrix1.getCols() + z] * matrix2[z * matrix2.getCols() + j];
			}
			index++;
		}
	}

	return newMatrix;
}
Matrix operator &  (Matrix matrix1, Matrix matrix2) {

	if (matrix1.getCols() != matrix2.getCols() || matrix1.getRows() != matrix2.getRows()) {
		throw "";
	}

	for (size_t i = 0; i < matrix2.getSize(); i++)
	{
		matrix1[i] *= matrix2[i];
	}

	return matrix1;
}
