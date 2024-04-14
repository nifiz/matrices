#pragma once

#include <memory>
#include <exception>

namespace Math {

	class matrix
	{
	private:
		const short rows;
		const short columns;

		std::unique_ptr<std::unique_ptr<double[]>[]> main_ptr;

	public:
		matrix(const short rows, const short columns, const double initializing_value=0): rows(rows), columns(columns) {

			this->main_ptr = std::make_unique<std::unique_ptr<double[]>[]>(rows);

			for (int i = 0; i < rows; i++) {

				this->main_ptr[i] = std::make_unique<double[]>(columns);

				for (int j = 0; j < columns; j++) {
					this->main_ptr[i][j] = initializing_value;
				}
			}

		}

		//copy constructor

		matrix(const matrix& c_matrix): rows(c_matrix.get_rows()), columns(c_matrix.get_columns()) {
			
			this->main_ptr = std::make_unique<std::unique_ptr<double[]>[]>(this->rows);

			for (int i = 0; i < this->rows; i++) {

				this->main_ptr[i] = std::make_unique<double[]>(columns);

				for (int j = 0; j < this->columns; j++) {
					this->main_ptr[i][j] = c_matrix[i][j];
				}
			}

		}

		std::unique_ptr<double[]> & operator[](const short row) const {

			// TODO:
			// implement throwing an exception when an invalid
			// column index is given in a second bracket
			// (Math::matrix) m[row][invalid_column]
			// std::unique_ptr does not implement this restriction

			if (row < 0 || row >= this->rows) throw std::exception("Invalid row index");
			
			return this->main_ptr[row];
		}

		short get_rows(void) const {
			return this->rows;
		}

		short get_columns(void) const {
			return this->columns;
		}

		matrix operator+(matrix m_add) {
		
			if (this->get_rows() != m_add.get_rows()) throw std::exception("Row mismatch");
			if (this->get_columns() != m_add.get_columns()) throw std::exception("Column mismatch");

			short rows = m_add.get_rows();
			short columns = m_add.get_columns();

			matrix ret_matrix(rows, columns);

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					ret_matrix[i][j] = this->main_ptr[i][j] + m_add[i][j];
				}
			}

			return ret_matrix;
		}



		~matrix() {

		}
	};
}

