#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split_words(const std::string& text)
{
	std::vector<std::string> rijeci;
	std::size_t pocetak = 0;

	while (pocetak < text.size())
	{
		pocetak = text.find_first_not_of(" \t\n", pocetak);

		if (pocetak == std::string::npos)
		{
			break;
		}
		std::size_t kraj = text.find_first_of(" \t\n", pocetak);

		if (kraj == std::string::npos)
			kraj = text.size();
		rijeci.push_back(text.substr(pocetak, kraj - pocetak));

		pocetak = kraj;
	}
	return rijeci;
}
int main()
{
	std::string tekst;
	std::cout << "Unesite recenicu: " << std::endl;
	std::getline(std::cin, tekst);

	std::vector<std::string> rijeci = split_words(tekst);

	std::cout << "Broj rijeci: " << rijeci.size() << std::endl;

	if (rijeci.empty())
	{
		std::cout << "Nema unesenih rijeci" << std::endl;
		return 0;
	}
	std::string najdulja = rijeci[0];
	std::string prva = rijeci[0];

	for (const std::string& rijec : rijeci)
	{
		if (rijec.size() > najdulja.size())
			najdulja = rijec;
		if (rijec < prva)
			prva = rijec;
	}
	std::cout << "Najdulja rijec: " << najdulja << std::endl;

	std::string obrnuto;

	for (std::size_t i = rijeci.size(); i > 0; i--)
	{
		if (!obrnuto.empty())
			obrnuto += "-";

		obrnuto += rijeci[i - 1];
	}
	std::cout << "Obrnuti redoslijed: " << obrnuto << std::endl;
	std::cout << "Prva po abecedi: " << prva << std::endl;

	return 0;
}