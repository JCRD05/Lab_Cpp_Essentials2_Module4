#include <iostream>
#include <array>


class Matrix2x2
{
public:
	Matrix2x2(const std::array<int, 4>& entries) : m_entries(entries) {}

	friend std::ostream& operator<<(std::ostream& output, const Matrix2x2& matrix)
	{
		matrix.print(output);
		return output;
	}

	friend std::istream& operator>>(std::istream& input, Matrix2x2& matrix)
	{
		int value{};
		input >> value;
		matrix.add(value);
		return input;
	}

private:
	int m_lastAdded = 0;
	std::array<int, 4> m_entries;

	void add(const int entry)
	{
		switch (m_lastAdded)
		{
		case 0: m_entries.at(0) = entry; break;
		case 1: m_entries.at(1) = entry; break;
		case 2: m_entries.at(2) = entry; break;
		case 3: m_entries.at(3) = entry; break;
		}
		m_lastAdded++;
		if (m_lastAdded == 4) { m_lastAdded = 0; }
	}

	void print(std::ostream& output) const
	{
		output	<< m_entries.at(0) << " " << m_entries.at(1) << "\n" 
				<< m_entries.at(2) << " " << m_entries.at(3);
	}
};

int main()
{
	std::array<int, 4> matrixArray
	{	0, 0, 
		0, 0	};

	Matrix2x2 myMatrix(matrixArray);

	std::cin >> myMatrix;
	std::cin >> myMatrix;
	std::cin >> myMatrix;
	std::cin >> myMatrix;
	std::cout << myMatrix;
}