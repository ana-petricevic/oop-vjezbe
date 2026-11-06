#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

std::vector<std::string> split_words(const std::string& text)
{
	std::vector<std::string> rijeci;
	std::size_t pocetak = 0;

	while (pocetak < text.size())
	{
		pocetak = text.find_first_not_of(" \t\n", pocetak);

		if (pocetak == std::string::npos)
			break;

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
	std::vector<std::string> rijecnik = { "programski", "jezik", "c++", "je", "brz", "i", "mocan", "ali", "nije",
"jednostavan", "za", "pocetnike" };

	std::sort(rijecnik.begin(), rijecnik.end());

	std::string recenica;

	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);

	std::vector<std::string> rijeci = split_words(recenica);
	std::vector <std::string> nepoznate;

	for (std::string rijec : rijeci)
	{
		rijec.erase(std::remove_if(rijec.begin(), rijec.end(), [](unsigned char c)
			{
				return c == ',' || c == ',';
			}), rijec.end()
				);

		std::transform(rijec.begin(), rijec.end(), rijec.begin(), [](unsigned char c)
			{
				return std::tolower(c);
			});

		if (!std::binary_search(rijecnik.begin(), rijecnik.end(), rijec))
		{
			nepoznate.push_back(rijec);
		}
	}
	std::cout << "Nepoznatih rijeci: " << nepoznate.size() << std::endl;

	for (const std::string& rijec : nepoznate)
	{
		std::cout << rijec << " ";
	}
	return 0;
}