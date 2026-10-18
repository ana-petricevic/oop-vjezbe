#include <iostream>
#include <array>
#include <algorithm>

constexpr int DAYS = 7;

double total(const std::array<double, DAYS>& hours)
{
	double suma = 0;
	for (double sat : hours)
	{
		suma += sat;
	}
	return suma;
}
int best_day(const std::array<double, DAYS>& hours)
{
	int najbolji = 0;
	for (int i = 1; i < DAYS; i++)
	{
		if (hours[i] > hours[najbolji])
		{
			najbolji = i;
		}
	}
	return najbolji + 1;
}
int main()
{
	std::array<double, DAYS> prvi_tjedan;
	std::array<double, DAYS> drugi_tjedan;

	std::cout << "Unesite broj sati ucenja za 7 dana: " << std::endl;
	for (int i = 0; i < DAYS; i++)
	{
		std::cin >> prvi_tjedan[i];
	}
	std::cout << "Ukupno sati u prvom tjednu: " << total(prvi_tjedan) << std::endl;
	std::cout << "Dan sa najvise sati ucenja: " << best_day(prvi_tjedan) << std::endl;

	drugi_tjedan.fill(1.5);

	std::cout << "Ukupno sati u drugom tjednu: " << total(drugi_tjedan) << std::endl;

	std::cout << std::boolalpha;

	std::cout << "Jesu li tjedni jednaki? " << (prvi_tjedan == drugi_tjedan) << std::endl;
	std::cout << "Je li prvi tjedan manji od drugogaž? " << (prvi_tjedan < drugi_tjedan) << std::endl;

	std::swap(prvi_tjedan, drugi_tjedan);

	std::cout << "Nakon zamjene nizova: " << std::endl;

	std::cout << "Ukupno sati u prvom tjednu: " << total(prvi_tjedan) << std::endl;
	std::cout << "Ukupno sati u drugom tjednu: " << total(drugi_tjedan) << std::endl;

	return 0;
}