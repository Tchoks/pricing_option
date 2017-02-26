#include "stdafx.h"
#include "Matrix.h"

/*template<class T>
Matrix::Matrix(){}
*/
template<class T>
Matrix<T>::Matrix(const int & rows, const int & cols, const T & value) : rows(rows), cols(cols){
	/*data.resize(rows)
	for (int i = 0; i < data.size(); i++) {
		data[i].resize(cols, value);
	}*/
	for (int i = 0; i < rows ; i++) {
		std::vector<T> col_vec(cols, value);
		data.push_back(col_vec);
	}
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& mat) : rows(mat.rows), cols(mat.cols) {
	data = mat.get_mat();
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& mat) {
	if (&mat == this) {
		return *this;
	}

	data = mat.get_mat();
	/*
	const std::int new_rows = mat.rows;
	const std::int new_cols = mat.cols;

	data.resize(new_rows);
	for (int i = 0; i < data.size(); i++) {
		data[i].resize(new_cols);
	}

	for (int i = 0; i < new_rows; i++){
		for (int j = 0; j < new_cols; j++){
			data[i][j] = mat(i, j);
		}
	}
	rows = new_rows;
	cols = new_cols;
	*/
	return *this;
}

template<class T>
std::vector<std::vector<T>> Matrix<T>::get_mat() const
{
	return std::vector<std::vector<T>>(mat);
}

template<class T>
T & Matrix<T>::value(const int & row, const int & col)
{
	return this->data[row][col];
}

/*
template<class T>
T & Matrix<T>::operator()(const int& row, const int& col) {
	return this->data[row][col];
}

template<class T>
const T & Matrix<T>::operator()(const int& row, const int& col) const {
	return this->data[row][col];
}

template<class T>
T & Matrix<T>::operator[](const int row) {
	return data[row];
}

template<class T>
const T & Matrix<T>::operator[](const int row) const {
	return data[row];
}
*/
/*
template<class T>
Matrix::~Matrix() {
}*/
