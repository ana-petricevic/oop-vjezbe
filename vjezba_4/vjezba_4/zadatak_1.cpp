#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> input_vector()
{
	std::vector<int> v;
	int x;
	std::cout << "Unesite brojeve (0 za kraj)";

	while (std::cin >> x && x != 0)
	{
		v.push_back(x);
	}
	return v;
}
int main()
{
	std::vector<int> v = input_vector();

	if (v.empty())
	{
		std::cout << "Vektor je prazan!" << std::endl;
		return 0;
	}
	int k;
	std::cout << "Unesite k: ";
	std::cin >> k;

	if (k <= 0)
	{
		std::cout << "K mora biti veci od 0!" << std::endl;
		return 0;
	}
	int negativnih = std::count_if(v.begin(), v.end(),[](int x)
	{
		return x < 0;
	});
	std::cout << "Broj negativnih brojeva: " << negativnih << std::endl;

	auto prvi = std::find_if(v.begin(), v.end(), [k](int x)
		{
			return x % k == 0;
		});
	if (prvi != v.end())
	{
		std::cout << "Prvi visekratnik od " << k << " je " << *prvi << " pozicija " << prvi - v.begin() << std::endl;
	}
	else
	{
		std::cout << "Nema visekratinika od k." << std::endl;
	}
	auto min_it = std::min_element(v.begin(), v.end());
	auto max_it = std::max_element(v.begin(), v.end());

	std::cout << "Min element " << *min_it << " pozicija " << min_it-v.begin() << std::endl;

	std::cout << "Max element " << *max_it << " pozicija " << max_it - v.begin() << std::endl;

	v.erase(std::remove_if(v.begin(), v.end(), [k](int x)
		{
			return x % k == 0;
		}), v.end());

	std::cout << "Bez visekratinika: ";

	for (int x : v)
	{
		std::cout << x << " ";

	}
	return 0;
	



}