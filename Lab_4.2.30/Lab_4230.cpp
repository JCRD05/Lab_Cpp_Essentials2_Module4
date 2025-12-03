#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

class Matrix
{
public:
	Matrix(const int rows, const int columns)
	{
		if (rows < 1 || columns < 1)
		{
			throw std::invalid_argument("Error: Number of rows/columns cannot be less than 1");
		}

		m_rows = rows;
		m_columns = columns;
		m_entries.assign(m_rows * m_columns, 0);
	}

	friend std::ostream& operator<<(std::ostream& output, const Matrix& matrix)
	{
		if (matrix.m_entries.empty()) { return output; }

		for (int i = 0; i < matrix.m_entries.size(); i++)
		{
			output << std::setw(4) << matrix.m_entries.at(i) << ' ';
			if ((i + 1) % matrix.m_columns == 0) { output << '\n'; }
		}
		return output;
	}

	void fill(const int value)
	{
		m_entries.assign(m_rows * m_columns, value);
	}

	void fill(const std::vector<int>& entries)
	{
		if (entries.size() != (m_rows * m_columns))
		{
			throw std::invalid_argument("Error: not enough values to fill the matrix");
		}
		m_entries = entries;
	}

	Matrix operator+(const int value) const
	{
		Matrix result(m_rows, m_columns);
		for (int i = 0; i < m_entries.size(); i++)
		{
			result.m_entries.at(i) = m_entries.at(i) + value;
		}
		return result;
	}

	Matrix operator+(const Matrix& other) const
	{
		if (m_rows != other.m_rows || m_columns != other.m_columns)
		{
			throw std::invalid_argument("Error: Unmatch Matrices Dimensions (Rows and Columns must match)");
		}

		Matrix result(m_rows, m_columns);
		for (int i = 0; i < m_entries.size(); i++)
		{
			result.m_entries.at(i) = m_entries.at(i) + other.m_entries.at(i);
		}
		return result;
	}

	Matrix operator-(const int value) const
	{
		Matrix result(m_rows, m_columns);
		for (int i = 0; i < m_entries.size(); i++)
		{
			result.m_entries.at(i) = m_entries.at(i) - value;
		}
		return result;
	}

	Matrix operator-(const Matrix& other) const
	{
		if (m_rows != other.m_rows || m_columns != other.m_columns)
		{
			throw std::invalid_argument("Error: Unmatch Matrices Dimensions (Rows and Columns must match)");
		}

		Matrix result(m_rows, m_columns);
		for (int i = 0; i < m_entries.size(); i++)
		{
			result.m_entries.at(i) = m_entries.at(i) - other.m_entries.at(i);
		}
		return result;
	}

	Matrix operator*(const int value) const
	{
		Matrix result(m_rows, m_columns);
		for (int i = 0; i < m_entries.size(); i++)
		{
			result.m_entries.at(i) = m_entries.at(i) * value;
		}
		return result;
	}

	Matrix operator*(const Matrix& other) const
	{
		if (m_columns != other.m_rows)
		{
			throw std::invalid_argument("Error: Invalid Matrices Dimensions for Multiplication");
		}

		int resultRows = m_rows;
		int resultCols = other.m_columns;

		Matrix result(resultRows, resultCols);
		std::vector<int> newEntries(resultRows * resultCols);

		for (int i = 0; i < resultRows; i++)
		{
			for (int j = 0; j < resultCols; j++)
			{
				int sum = 0;
				for (int k = 0; k < m_columns; k++)
				{
					int valThis = m_entries[i * m_columns + k];
					int valOther = other.m_entries[k * other.m_columns + j];
					sum += valThis * valOther;
				}
				newEntries[i * resultCols + j] = sum;
			}
		}

		result.fill(newEntries);
		return result;
	}

private:
	int m_rows;
	int m_columns;
	std::vector<int> m_entries;
};

int main()
{
	try
	{
		Matrix mat1(3, 3);
		mat1.fill(1);

		Matrix mat3(3, 3);
		mat3.fill(3);

		std::cout << "--- Initial Matrices ---\n";
		std::cout << "Matrix 1 (All 1s):\n" << mat1 << "\n";
		std::cout << "Matrix 2 (All 3s):\n" << mat3 << "\n";

		std::cout << "--- Scalar Operations ---\n";
		std::cout << "Mat1 + 5:\n" << (mat1 + 5) << "\n";
		std::cout << "Mat3 - 1:\n" << (mat3 - 1) << "\n";
		std::cout << "Mat1 * 2:\n" << (mat1 * 2) << "\n";

		std::cout << "--- Matrix Operations ---\n";
		std::cout << "Mat1 + Mat3:\n" << (mat1 + mat3) << "\n";
		std::cout << "Mat3 - Mat1:\n" << (mat3 - mat1) << "\n";
		std::cout << "Mat1 * Mat3:\n" << (mat1 * mat3) << "\n";

		Matrix matDiff(2, 4);
		matDiff.fill(2);
		std::cout << "Matrix 3 (Different Size 2x4):\n" << matDiff << "\n";

		std::cout << "--- Testing Exceptions ---\n";

		try
		{
			std::cout << "Test 1: Invalid Constructor... ";
			Matrix invalid(0, 5);
		}
		catch (const std::exception& e)
		{
			std::cout << "Caught: " << e.what() << "\n";
		}

		try
		{
			std::cout << "Test 2: Invalid Fill size... ";
			std::vector<int> wrongSizeVec{ 1, 2, 3 };
			mat1.fill(wrongSizeVec);
		}
		catch (const std::exception& e)
		{
			std::cout << "Caught: " << e.what() << "\n";
		}

		try
		{
			std::cout << "Test 3: Addition Dimension Mismatch (3x3 + 2x4)... ";
			Matrix result = mat1 + matDiff;
		}
		catch (const std::exception& e)
		{
			std::cout << "Caught: " << e.what() << "\n";
		}

		try
		{
			std::cout << "Test 4: Subtraction Dimension Mismatch (3x3 - 2x4)... ";
			Matrix result = mat1 - matDiff;
		}
		catch (const std::exception& e)
		{
			std::cout << "Caught: " << e.what() << "\n";
		}

		try
		{
			std::cout << "Test 5: Multiplication Dimension Mismatch (3x3 * 2x4)... ";
			Matrix result = mat1 * matDiff;
		}
		catch (const std::exception& e)
		{
			std::cout << "Caught: " << e.what() << "\n";
		}

	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected Error: " << e.what() << "\n";
	}

	return 0;
}