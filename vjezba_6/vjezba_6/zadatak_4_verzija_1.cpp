#include <iostream>

class Board
{
private:
	int r;
	int c;
	char border;
	char* data;
public:
	Board(int rows, int cols, char ch)
	{
		r = rows;
		c = cols;
		border = ch;
		data = new char[r * c];

		for (int i = 0; i < r * c; i++)
		{
			data[i] = ' ';
		}
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
	~Board()
	{
		delete[] data;
	}
	Board(const Board& other)
	{
		r = other.r;
		c = other.c;
		border= other.border;
		data = new char[r * c];

		for (int i = 0; i < r * c; i++)
		{
			data[i] = other.data[i];
		}
	}
	void set(int i, int j, char ch)
	{
		if(i > 0 && i < r - 1 && j > 0 && j < c - 1)
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
	int cols() const
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
	Board b(4, 8, '#');
	b.set(1, 2, '@');

	

	Board copy = b;

	copy.set(2, 5, '*');
	copy.set(0, 0, '!');

	b.print();

	std::cout << std::endl;

	copy.print();

	std::cout << std::endl;

	std::cout << copy.rows() << ' ' << copy.cols() << ' ' << copy.get(2, 5) << std::endl;

	return 0;
}