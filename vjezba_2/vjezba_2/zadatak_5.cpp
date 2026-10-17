#include <iostream>

inline double add(double a, double b)
{
	return a + b;
}
inline double subtract(double a, double b)
{
	return a - b;
}
inline double multiply(double a, double b)
{
	return a * b;
}
inline double divide(double a, double b)
{
	return a / b;
}

int main()
{
	double (*operations[4])(double, double) =
	{
		add,
		subtract,
		multiply,
		divide
	};
	double a, b;
	int operation;

	std::cout << "Unesite broj a: " << std::endl;
	std::cin >> a;
	std::cout << "Unesite broj b: " << std::endl;
	std::cin >> b;
	std::cout << "Unesite indeks operacije 0-3: " << std::endl;
	std::cin >> operation;

	if (operation < 0 || operation > 3)
	{
		std::cout << "Neispravna operacija" << std::endl;
	}
	else if (operation == 3 && b == 0)
	{
		std::cout << "Nije moguce dijeliti s nulom" << std::endl;
	}
	else
	{
		std::cout << "Rezultat operacije je: " << operations[operation](a, b) << std::endl;
	}
	return 0;
}