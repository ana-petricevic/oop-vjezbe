#include <iostream>

void my_trasform(int arr[], int n, int (*f)(int))
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = f(arr[i]);
	}
}

int twice(int x)
{
	return x * 2;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int n = 6;

	my_trasform(arr, n, twice);
	std::cout << "Poziv my_trasform sa funkcijom twice: " << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	int arr2[] = { 1, 2, 3, 4, 5, 6 };

	my_trasform(arr2, n, [](int x)
		{
			if (x % 2 == 0)
			{
				return x / 2;
			}
			else
			{
				return x * 2;
			}
		});

	std::cout << "Ispis niza pozivom funkcije my_trasform s lambdom: " << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;

	int prag = 5;
	int suma = 0;
	int produkt = 1;

	int arr3[] = { 10, 5, 6, 8, 11, 3 };

	auto izracunaj = [&]()
		{
			for (int x : arr3)
			{
				suma += x;
				produkt *= x;
			}
		};

	izracunaj();

	std::cout << "Suma clanova niza arr3: " << suma << std::endl;
	std::cout << "Produkt clanova niza arr3: " << produkt << std::endl;

	int suma2 = 0;

	auto suma_vecih = [prag, &suma2](int niz[], int n)
		{
			for (int i = 0; i < n; i++)
			{
				if (niz[i] > prag)
				{
					suma2 += niz[i];
				}
			}
		};

	suma_vecih(arr3, n);

	std::cout << "Suma clanova vecih od praga: " << suma2 << std::endl;

	return 0;
}