#include <iostream>

class Coin {
	int value;
	static int counter;

public:
	Coin(int v) : value(v)
	{
		counter++;
	}
	~Coin()
	{
		counter--;
	}
	static int remaining()
	{
		return counter;
	}
};

int Coin::counter = 0;

void bonus()
{
	Coin c1(5);
	Coin c2(5);
	Coin c3(10);
	std::cout << Coin::remaining() << std::endl;
}
int main()
{
	std::cout << Coin::remaining() << std::endl;

	Coin gold(50);
	{
		Coin a(1);
		Coin b(1);
		std::cout << Coin::remaining() << std::endl;
	}
	std::cout << Coin::remaining() << std::endl;
	bonus();
	std::cout << Coin::remaining() << std::endl;

	return 0;
}


