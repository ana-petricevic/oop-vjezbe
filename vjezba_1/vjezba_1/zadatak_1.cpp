#include <iostream>

int main()
{
	int a{}, b{};

	std::cout << "Unesite prvi cijeli broj: ";
	std::cin >> a;

	std::cout << "Unesite drugi cijeli broj: ";
	std::cin >> b;

	int zbroj{ a + b };
	double sredina { (a + b) / 2.0 };
	bool usporedba{ a < b };

	std::cout << "Zbroj: " << zbroj << std::endl;
	std::cout << "Sredina: " << sredina << std::endl;
	std::cout << "Usporedba: " << usporedba << std::endl;

	return 0;
}