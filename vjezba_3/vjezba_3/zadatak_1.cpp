#include <iostream>
#include <vector>

void input_vector(std::vector<int>& v)
{
	int broj;

	do
	{
		std::cin >> broj;
		if (broj != 0)
		{
			v.push_back(broj);
		}
	} while (broj != 0);
}
void print_vector(const std::vector <int>& v)
{
	for (int broj : v)
	{
		std::cout << broj << " ";
	}
	std::cout << std::endl;
}
int main()
{
	std::vector<int> v;

	std::cout << "Unesite brojeve (0 za kraj): ";
	input_vector(v);

	std::cout << "Ispis vektora: ";
	print_vector(v);

	std::cout << "Obrnuti redoslijed vektora: ";
	for (auto it = v.rbegin(); it != v.rend(); ++it)
	{
		std::cout << *it << " ";

	}
	std::cout << std::endl;

	std::vector<int> a;

	for (int i = 1; i <= 20; i++)
	{
		a.push_back(i);
		std::cout << "size: " << a.size() << "; capacity: " << a.capacity() << std::endl;

	}
	std::vector<int> b;
	b.reserve(100);

	for (int i = 1; i <= 20; i++)
	{
		b.push_back(i);
		std::cout << "size: " << b.size() << "; capacity: " << b.capacity() << std::endl;
	}
	b.shrink_to_fit();

	std::cout << "Kapacitet nakon shrink_to_fit(): " << b.capacity() << std::endl;

	return 0;
}