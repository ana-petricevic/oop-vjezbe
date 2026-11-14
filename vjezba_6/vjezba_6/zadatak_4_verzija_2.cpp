#include <iostream>
#include <vector>

class BoardVector
{
private:
	int r;
	int c;
	char border;
	std::vector<char> data;
public:
	BoardVector(int rows, int cols, char ch)
		: r(rows), c(cols), border(ch), data(rows* cols, ' ')
	{
		for (int i = 0; i < r; i++)
		{
			data[i * c] = border;
			data[i * c + c - 1] = border;
		}
		for (int j = 0; j < c; j++)
		{
			data[j] = border;
			data[(r - 1) * c + j] = border;
		}
	}
	void set(int i, int j, char ch)
	{
		if (i > 0 && i < r - 1 && j >0 && j < c - 1)
		{
			data[i * c + j] = ch;
		}
	}
	char get(int i, int j) const
	{
		return data[i * c + j];
	}
	int rows() const
	{
		return r;
	}
	int cols()
	{
		return c;
	}
	void print() const
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				std::cout << data[i * c + j];
			}
			std::cout << std::endl;
		}
	}
};
int main()
{
	BoardVector b2(4, 8, '#');

	b2.set(1, 2, '@');

	BoardVector copy2 = b2;

	copy2.set (1, 2, '@');
	copy2.set (0, 0, '!');

	b2.print();

	std::cout << std::endl;

	copy2.print();

	std::cout << std::endl;

	std::cout << copy2.rows() << ' ' << copy2.cols() << ' ' << copy2.get(2, 5) << std::endl;

	return 0;

}