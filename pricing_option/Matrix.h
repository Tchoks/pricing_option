#pragma once
#include <vector>


template<class T>
class Matrix
{
	public:
		//Matrix(); // default constructor

		Matrix(const int& rows, const int& cols, const T& value);

		Matrix(const Matrix<T>& mat);

		Matrix<T>& operator= (const Matrix<T>& mat);

		std::vector<std::vector<T>> get_mat() const;
		T& value(const int& row, const int& col);

		//T& operator() (const int& row, const int& col);
		//const T& operator() (const int& row, const int& col) const ;

		/*T& operator[] (const std::int row);
		const T& operator[] (const std::int row) const;
		*/
		//virtual ~Matrix();

	private:
		const int rows;
		const int cols;
		std::vector<std::vector<T>> data;

};

