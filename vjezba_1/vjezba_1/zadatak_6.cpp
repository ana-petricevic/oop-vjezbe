#include <iostream>

struct Fraction
{
	int numerator;
	int denominator;

	void reduce()
	{
		int a{ numerator };
		int b{ denominator };

		while (b != 0)
		{
			int ostatak{ a % b };
			a = b;
			b = ostatak;
		}
		int gcd{ a };

		numerator = numerator / gcd;
		denominator = denominator / gcd;

		if (denominator < 0)
		{
			numerator = -numerator;
			denominator = -denominator;

		}
	}
	double value()
	{
		return static_cast<double>(numerator) / denominator;
	}
	void print()
	{
		std::cout << numerator << "/" << denominator;
	}
};

Fraction sum(const Fraction& a, const Fraction& b)
{
	Fraction rezultat{ a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator };

	rezultat.reduce();

	return rezultat;
}

int main()
{
	Fraction a{ 1,2 };
	Fraction b{ 1,4 };

	std::cout << "Prvi razlomak: ";
	a.print();

	std::cout << std::endl;

	std::cout << "Drugi razlomak: ";
	b.print();

	std::cout << std::endl;

	std::cout << "Decimalna vrijednost prvog razlomka: " << a.value() << std::endl;

	Fraction rezultat{ sum(a,b) };

	std::cout << "Zbroj: ";
	rezultat.print();

	std::cout << std::endl;

	std::cout << "Decimalna vrijednost zbroja: " << rezultat.value() << std::endl;

	return 0;
}