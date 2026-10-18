#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cout << "Unesite broj dana: ";
	std::cin >> n;

	if (n < 0)
	{
		std::cout << "Broj dana mora biti veci od 0: " << std::endl;
		return 0;
	}
	std::vector<double> temperatura(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> temperatura[i];
	}
	std::vector<double> promjene;
	promjene.reserve(n - 1);

	for (auto it = temperatura.begin() + 1; it != temperatura.end(); ++it)
	{
		promjene.push_back(*it - *(it - 1));
	}
	std::cout << "Vektor promjena: ";
	for (double p : promjene)
	{
		std::cout << p << " ";
	}
	std::cout << std::endl;

	double zadnja = temperatura.back();
	temperatura.resize(7, zadnja);

	std::cout << "Izvjestaj za 7 dana: ";
	for (double t : temperatura)
	{
		std::cout << t << " ";
	}
	std::cout << std::endl;

	std::vector<int> a(5);
	std::vector<int> b{ 5 };

	std::cout << "Broj elemenata vektora a: " << a.size() << std::endl;
	std::cout << "Broj elemenata vektora b: " << b.size() << std::endl;

	return 0;
}