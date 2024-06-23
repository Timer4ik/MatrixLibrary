#ifndef LINEAR_H
#define LINEAR_H

class Matrix {
private:
	std::vector<float> matrix;
	int cols;
	int rows;
public:
	Matrix(int rows, int cols, std::vector<float> matrix);
	Matrix(int rows, int cols);
	int getCols();
	int getRows();
	int getSize();
	std::vector<float> getMatrix();
	float& operator[](int i);
	void print();
};
Matrix operator + (float num, Matrix matrix);
Matrix operator + (Matrix matrix, float num);
Matrix operator + (Matrix matrix1, Matrix matrix2);
Matrix operator * (float num, Matrix matrix);
Matrix operator * (Matrix matrix, float num);
Matrix operator * (Matrix matrix1, Matrix matrix2);
Matrix operator &  (Matrix matrix1, Matrix matrix2);

#endif // ! LINEAR_H