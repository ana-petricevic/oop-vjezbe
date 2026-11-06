#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool starts_with(const std::string& s, const std::string& prefix)
{
	if (prefix.size() > s.size())
		return false;

	return std::equal(prefix.begin(), prefix.end(), s.begin());
}

bool end_with(const std::string& s, const std::string& suffix)
{
	if (suffix.size() > s.size())
		return false;

	return std::equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main()
{
	std::vector<std::string> datoteke = {
		"vjezba04.cpp", "slajdovi.pdf", "main.cpp",
		"README.md", "vjezba04.h", "notes.txt",
		"vjezba03.cpp"
	};

	int broj = std::count_if(datoteke.begin(), datoteke.end(), [](const std::string& ime)
		{
			return end_with(ime, ".cpp");
		});

	std::cout << ".cpp datoteka: " << broj << std::endl;

	datoteke.erase(std::remove_if(datoteke.begin(), datoteke.end(), [](const std::string& ime)
		{
			return starts_with(ime, "vjezba");
		}), datoteke.end()
			);
	for (const std::string& ime : datoteke)
	{
		std::cout << ime << " ";
	}
	std::cout << std::endl;

	return 0;
}