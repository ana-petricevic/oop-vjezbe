#include <iostream>

class IntStack
{
private:
	int* niz;
	int br;
	int kapacitet;
public:
	IntStack(int k = 2)
	{
		kapacitet = k;
		br = 0;
		niz = new int[kapacitet];
	}
	~IntStack()
	{
		delete[]niz;
	}
	IntStack(const IntStack& s)
	{
		br = s.br;
		kapacitet = s.kapacitet;
		niz = new int[kapacitet];

		for (int i = 0; i < br; i++)
			niz[i] = s.niz[i];
	}
	void push(int x)
	{
		if (br == kapacitet)
		{
			kapacitet *= 2;
			int* novi = new int[kapacitet];
			for (int i = 0; i < br; i++)
				novi[i] = niz[i];
			delete[] niz;
			niz = novi;
		}
		niz[br] = x;
		br++;
	}
	void pop()
	{
		if (br > 0)
			br--;
	}
	int top() const
	{
		if (br > 0)
			return niz[br - 1];
		return -1;
	}
	bool empty() const
	{
		return br == 0;
	}
	int size() const
	{
		return br;
	}
	int capacity() const
	{
		return kapacitet;
	}
};

int main()
{
	IntStack s;

	std::cout << "Ispis velicina, kapacitet i zadnji element s niza: ";
	for (int i = 1; i <= 5; ++i)
		s.push(i * 10);
	std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << std::endl;

	IntStack c = s;
	c.pop();
	c.push(99);

	std::cout << "Zadnji element s i c niza: " << s.top() << ' ' << c.top() << std::endl;


	std::cout << "Ispis s niza:  ";
	while (!s.empty())
	{
		std::cout << s.top() << ' ';
		s.pop();
	}
	std::cout << std::endl;

	return 0;
}