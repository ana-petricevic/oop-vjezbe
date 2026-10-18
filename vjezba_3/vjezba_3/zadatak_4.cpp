#include <iostream>
#include <string>

bool split_mail(const std::string& email, std::string& user, std::string& domain)
{
	std::size_t pozicija = email.find('@');

	if (pozicija == std::string::npos)
		return false;
	if (email.find('@', pozicija + 1) != std::string::npos)
		return false;
	if (pozicija == 0 || pozicija == email.size() - 1)
		return false;

	user = email.substr(0, pozicija);
	domain = email.substr(pozicija + 1);

	if (domain.find('.') == std::string::npos)
		return false;

	return true;
}
int main()
{
	std::string email;
	std::string user;
	std::string domain;

	std::cout << "Unseite e-mail adresu: ";
	std::getline(std::cin, email);

	if (split_mail(email, user, domain))
	{
		std::cout << "Korisnik: " << user << std::endl;
		std::cout << "Domena: " << domain << std::endl;
	}
	else
	{
		std::cout << "Neispravna adresa. " << std::endl;
	}
	return 0;
}