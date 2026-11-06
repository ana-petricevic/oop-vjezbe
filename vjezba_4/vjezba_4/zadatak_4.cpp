#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

struct PasswordInfo {
	int length;
	int digits;
	int uppercase;
	int special;
};
PasswordInfo analyze(const std::string& password)
{
	PasswordInfo info;

	info.length = password.size();

	info.digits = std::count_if(password.begin(), password.end(), [](char c)
		{
			return std::isdigit(c);
		});

	info.uppercase = std::count_if(password.begin(), password.end(), [](char c)
		{
			return std::isupper(c);
		});

	info.special = std::count_if(password.begin(), password.end(), [](char c)
		{
			return std::ispunct(c);
		});
	return info;

}
bool is_strong(const PasswordInfo& info)
{
	return info.length >= 10 && info.digits >= 1 && info.uppercase >= 1 && info.special >= 1;
}

int main()
{
	std::string password;

	std::cout << "Unesite lozinku: ";
	std::cin >> password;

	PasswordInfo info = analyze(password);

	std::cout << "Duljina: " << info.length << std::endl;
	std::cout << "Znamenke: " << info.digits << std::endl;
	std::cout << "Velika slova: " << info.uppercase << std::endl;
	std::cout << "Posebni znakovi: " << info.special << std::endl;

	if (is_strong(info))
	{
		std::cout << "Lozinka je jaka." << std::endl;
	}
	else
	{
		std::cout << "Lozinka je slaba." << std::endl;
	}
	return 0;

}