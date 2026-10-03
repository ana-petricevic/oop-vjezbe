#include <iostream>
#include <string>

int main()
{
	int godina_rodenja{};

	std::cout << "Unesite godinu rodenja: ";
	std::cin >> godina_rodenja;

	std::cin.ignore();

	std::string ime_prezime{};

	std::cout << "Unesite ime i prezime: ";
	std::getline(std::cin, ime_prezime);

	int razmak{};

	for (int i{}; i < ime_prezime.length(); i++)
	{
		if (ime_prezime[i] == ' ')
		{
			razmak = i;
			break;
		}
	}
	char inicijal_imena{ ime_prezime[0] };
	char inicijal_prezime{ ime_prezime[razmak + 1] };

	std::cout << "Inicijali: " << inicijal_imena << "." << inicijal_prezime << "." << std::endl;

	int broj_znakova{};

	for (char znak : ime_prezime)
	{
		if (znak != ' ')
			broj_znakova++;
	}
	std::cout << "Broj znakova bez razmaka: " << broj_znakova << std::endl;

	int trenutna_godina{ 2026 };

	int godine{ trenutna_godina - godina_rodenja };

	std::cout << "Osoba ove godine navrsava: " << godine << "godina" << std::endl;

	return 0;
}