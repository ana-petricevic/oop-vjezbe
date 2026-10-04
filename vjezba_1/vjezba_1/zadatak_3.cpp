#include <iostream>

int& najveci(int arr[], int n)
{
	int indeks_najveceg{ 0 };

	for (int i{1}; i < n; i++)
	{
		if (arr [ i]  > arr[indeks_najveceg])
		{
			indeks_najveceg = i;
		}
	}
	return arr[indeks_najveceg];
}

int main()
{
	int niz[]{ 4, -7, 12, 0, 9, -3 };

	std::cout << "Pocetni niz: ";

	for (int broj : niz)
	{
		std::cout << broj << " ";
	}
	std::cout << std::endl;

	for (int& broj : niz)
	{
		if (broj < 0)
			broj = -broj;
	}
	std::cout << "Niz nakon promjene negativnih elemenata: ";

	for (int broj : niz)
	{
		std::cout << broj << " ";
	}
	std::cout << std::endl;

	najveci(niz, 6) = 0;

	std::cout << "Niz nakon postavljanja najveceg elementa na 0: ";

	for (int broj : niz)
	{
		std::cout << broj << " ";
	}
	std::cout << std::endl;

	return 0;
}