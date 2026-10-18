#include <iostream>
#include <string>

std::string with_separators(std::string digits)
{
	std::size_t pocetak = 0;

	if (!digits.empty() && digits[0] == '-')
		pocetak = 1;

	if (digits.size() > pocetak + 3)
	{
		std::size_t i = digits.size() - 3;

		while (i > pocetak)
		{
			digits.insert(i, ".");
			i -= 3;
		}
	}
	return digits;
}
std::string without_separators(std::string text)
{
	std::size_t pozicija = text.find('.');

	while (pozicija != std::string::npos)
	{
		text.erase(pozicija, 1);
		pozicija = text.find('.', pozicija);
	}
	return text;
}
int main ()
{
	std::string broj;
	std::cout << "Unesite broj: ";
	std::getline(std::cin, broj);

	std::cout << "Broj sa tockama: " << with_separators(broj) << std::endl;

	std::string broj2;
	std::cout << "Unesite broj sa tockama: ";
	std::getline(std::cin, broj2);

	std::cout << "Broj bez tocki: " << without_separators(broj2) << std::endl;

	return 0;
}